/** 
 * Face recognizer class
 * @brief Recognizes faces, adds people to known database, trains to recognize new known faces.
 * @author group53
 */

#define THRESHOLD 15.0

#include "FaceRecognizer.h"
#include "./camera/Camera.h"
#include <vector>
using namespace std;

/** 
 * @brief Retrains the face recognizer with all known faces from the database
 */ 
void FaceRecognizer::retrain() {
	// format imgs and labels
	vector<cv::Mat> imgs;
	vector<int> labels;
	for (int i = 0; i < Database::getInstance().knownSize(); ++i) {
		// add to images
		auto personImg = Database::getInstance()[i].getImage();
		imgs.reserve(imgs.size() + personImg.size());
		imgs.insert(imgs.end(), personImg.begin(), personImg.end());

		labels.insert(labels.end(), personImg.size(), i);
	}
	model->train(imgs, labels);
}


/** 
 * @brief Constructor that creates a face recognizer object and trains it with known faces
 */ 
FaceRecognizer::FaceRecognizer() {
	model->setThreshold(THRESHOLD);
	if (Database::getInstance().knownSize() > 0) {
		retrain();
	}
};

/** 
 * @brief Add person to known database
 * @param person
 */ 
void FaceRecognizer::addPerson(KnownPerson person) {
	Database::getInstance().addKnownPerson(person);
	retrain();
}

/** 
 * @brief Predict whether face is known or unknown after capturing camera frame input
 * @return person ID, confidence level, distance and image
 */ 
Result FaceRecognizer::predictCamera() {
	Camera cam = Camera::getInstance();
	return this->predict(cam.captureGrayscale());
}

/** 
 * @brief Helper function to predict whether face is known or unknown 
 * @param image camera frame input
 * @return person ID, confidence level, distance and image
 */ 
Result FaceRecognizer::predict(const cv::Mat &image) {
	int index = 0;
	double confidence = 0.0;
	model->predict(image, index, confidence);
	double distance = -1;
	auto dect = FaceDetection::getDetector();
	auto data = dect.detectWithEyeDistance(image);
	if (index != -1) {
		distance = data.first_person_distance;
	} else {
		if (data.number_of_faces > 0 && data.first_person_distance < 2 && data.first_person_distance != -1) {
			index = -2;
		}
	}
	this->callAll({.personID = index, .confidence = confidence, .distance=distance, .image=image});

	return {.personID = index, .confidence = confidence, .distance=distance, .image=image};
}

/** 
 * @brief Checks if there are known faces in the database
 * @return True if known face database is empty or false otherwise
 */ 
bool FaceRecognizer::isEmpty() {
	return Database::getInstance().knownSize() == 0;
}

/**
 * @brief Add a subscription to be called everytime a prediction is made
 * @param function: the subscribed function. The result.personID = -1 when a known person is not found,
 * 										-2 when a face is found but is unknown.
 * 										if result.distance > 2 the person is too far
 */
void FaceRecognizer::onPrediction(const std::function<void(Result)> &function) {
    callbacks.push_back(function);
}

/**
 * @brief Add a subscription to be called everytime a prediction is made
 * @param function: the subscribed function. The result.personID = -1 when a known person is not found,
 * 										-2 when a face is found but is unknown.
 * 										if result.distance > 2 the person is too far
 */
void FaceRecognizer::callAll(Result result) {
	for (const auto &func : callbacks) {
		func(result);
	}
}

/** 
 * @brief Get known person from database
 * @param i personID (i.e. index)
 * @return known person
 */ 
KnownPerson FaceRecognizer::getPersonByID(int i) {
	return Database::getInstance()[i];
}

/** 
 * @brief Destructor
 */ 
FaceRecognizer::~FaceRecognizer() = default;

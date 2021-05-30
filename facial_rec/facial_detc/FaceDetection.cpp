/** 
 * Face detection class
 * @brief Detects number of faces in frame and distance between eyes.
 * @author group53
 */

#include "FaceDetection.h"
#include <math.h>
using namespace std;
using namespace cv;

/** 
* @brief Destructor
*/
FaceDetection::~FaceDetection() {

}
/** 
 * @brief Constructor that creates a face detection object
 */
FaceDetection::FaceDetection() {
	face_cascade.load("../classifiers/haarcascade_frontalface_alt.xml");
	eyes_cascade.load("../classifiers/haarcascade_eye.xml");
}

/** 
 * @brief Determine number of faces and their distance from the system with distance between eyes
 * @param image camera frame input
 * @return number of faces and their distance
 */
Data FaceDetection::detectWithEyeDistance(cv::Mat image) {
	std::vector<Rect> faces;
	face_cascade.detectMultiScale(image, faces);
	double diff = -1;
	if (!faces.empty()) {
		auto firstface = faces[0];
		Mat faceROI = image(faces[0]);

		std::vector<Rect> eyes;
		eyes_cascade.detectMultiScale(faceROI, eyes);
		if (eyes.size() >= 2) {
			diff = 100 / sqrt(pow(eyes[0].x - eyes[1].x, 2) + pow(eyes[0].y - eyes[1].y, 2));
		}
	}

	return {.number_of_faces = static_cast<int>(faces.size()), .faces = faces, .first_person_distance =  diff};
}

/** 
 * @brief Determine number of faces and their distance from the system without distance between eyes
 * @param image camera frame input
 * @return number of faces and their distance
 */
Data FaceDetection::detectWithoutEyeDistance(cv::Mat image) {
	std::vector<Rect> faces;
	face_cascade.detectMultiScale(image, faces);
	return {.number_of_faces = static_cast<int>(faces.size()), .faces = faces, .first_person_distance = -1};
}

/** 
 * Face recognizer class
 * @brief Recognizes faces, adds people to known database, trains to recognize new known faces.
 * @author group53
 */

#ifndef CS3307_FACIAL_REC_FACERECOGNIZER_H_
#define CS3307_FACIAL_REC_FACERECOGNIZER_H_

#include "database/Database.h"
#include "database/KnownPerson.h"
#include "facial_detc/FaceDetection.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <vector>
#include <functional>

struct Result {
  int personID;   /**< person ID */
  double confidence;    /**< confidence value */
  double distance;    /**< calculated distance */
  cv::Mat image;
};

class FaceRecognizer {
 private:
  /** 
   * @brief Constructor that creates a face recognizer object and trains it with known faces
   */ 
  FaceRecognizer();
  cv::Ptr<cv::face::LBPHFaceRecognizer> model = cv::face::LBPHFaceRecognizer::create();
  std::vector<std::function<void(Result)>> callbacks;
  
  /**
   * @brief Add a subscription to be called everytime a prediction is made
   * @param function: the subscribed function. The result.personID = -1 when a known person is not found,
   * 										-2 when a face is found but is unknown.
   * 										if result.distance > 2 the person is too far
   */
  void callAll(Result result);

 public:
  /** 
  * Create an instance of the face recognizer class using Singleton design pattern
  */
  static FaceRecognizer &getRecognizer() {
	  static FaceRecognizer recog;
	  return recog;
  }

  /** 
   * @brief Destructor
   */
  ~FaceRecognizer();

  /** 
   * @brief Add known person to database
   * @param person
   */ 
  void addPerson(KnownPerson person);

  /** 
   * @brief Helper function to predict whether face is known or unknown 
   * @param image camera frame input
   * @return person ID, confidence level, distance and image
   */ 
  Result predict(const cv::Mat &image);
  
  /** 
   * @brief Predict whether face is known or unknown after capturing camera frame input
   * @return person ID, confidence level, distance and image
   */
  Result predictCamera();
  
  /** 
   * @brief Checks if there are known faces in the database
   * @return True if known face database is empty or false otherwise
   */
  bool isEmpty();

  /**
   * @brief Add a subscription to be called everytime a prediction is made
   * @param function: the subscribed function. The result.personID = -1 when a known person is not found,
   * 										-2 when a face is found but is unknown.
   * 										if result.distance > 2 the person is too far
   */
  void onPrediction(const std::function<void(Result)> &func);
  
  /** 
   * @brief Retrains the face recognizer with all known faces from the database
   */ 
  void retrain();
  
  /** 
   * @brief Get known person from database
   * @param i personID (i.e. index)
   * @return known person
   */ 
  static KnownPerson getPersonByID(int i);
};

#endif /**< CS3307_FACIAL_REC_FACERECOGNIZER_H_ */

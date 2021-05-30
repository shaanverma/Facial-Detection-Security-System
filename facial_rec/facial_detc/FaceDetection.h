/** 
 * Face detection class
 * @brief Detects number of faces in frame and distance between eyes.
 * @author group53
 */


#ifndef CS3307_FACIAL_REC_FACIAL_DETC_FACEDETECTION_H_
#define CS3307_FACIAL_REC_FACIAL_DETC_FACEDETECTION_H_

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"


struct Data {
  int number_of_faces;    /**< number of faces */
  std::vector<cv::Rect> faces;  /**< faces vector */
  double first_person_distance;   /**< first person distance */
};

class FaceDetection {
 public:

  /** 
   * @brief Destructor
   */
  virtual ~FaceDetection();

  /** 
   * @brief Create an instance of the Face Detection class using Singleton design pattern
   * @return face detector
   */
  static FaceDetection &getDetector() {
	  static FaceDetection Detector;
	  return Detector;
  }

  /** 
   * @brief Determine number of faces and their distance from the system with distance between eyes
   * @param image camera frame input
   */
  Data detectWithEyeDistance(cv::Mat image);
  
  /** 
   * @brief Determine number of faces and their distance from the system without distance between eyes
   * @param image camera frame input
   */
  Data detectWithoutEyeDistance(cv::Mat image);

 private:
  FaceDetection();
  cv::CascadeClassifier face_cascade;   /**< face cascade */
  cv::CascadeClassifier eyes_cascade;   /**< eyes cascade */
};

#endif /**< CS3307_FACIAL_REC_FACIAL_DETC_FACEDETECTION_H_ */

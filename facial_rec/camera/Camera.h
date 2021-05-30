/** 
 * Camera
 * @brief Camera for facial recognition.
 * @author group53
 */

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#ifndef CS3307_FACIAL_REC_CAMERA_CAMERA_H_
#define CS3307_FACIAL_REC_CAMERA_CAMERA_H_

class Camera {
 public:
  /** 
   * @brief Delete the copy assignment operator
   */
  void operator=(const Camera &) = delete;
  
  /** 
  * @brief Create an instance of the camera class using Singleton design pattern
  */
  static Camera &getInstance() {
	  static Camera _instance;
	  return _instance;
  }

  /** 
   * @brief Capture GBR frame
   * @return GBR frame
   */
  cv::Mat capture();

  /** 
   * @brief Capture grayscame frame
   * @return grayscale frame
   */
  cv::Mat captureGrayscale();

  /** 
   * @brief Capture RGB frame
   * @return RGB frame
   */
  cv::Mat captureRGB();

 private:
  /** 
   * @brief Constructor that creates a camera object
   */
  Camera();
  cv::VideoCapture cap;

};

#endif /**< CS3307_FACIAL_REC_CAMERA_CAMERA_H_ */

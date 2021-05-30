/** 
 * Camera class
 * @brief Camera for facial recognition.
 * @author group53
 */

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
#include "Camera.h"

/** 
 * @brief Constructor that creates a camera object
 */
Camera::Camera() {
	/** 
	 * --- INITIALIZE VIDEOCAPTURE
	 * --- open the default camera using default API
	 */
	int deviceID = 0;             /**< 0 = open default camera */
	int apiID = cv::CAP_ANY;      /**< 0 = autodetect default API */
	cap.open(deviceID, apiID);  /**< open selected camera using selected API */
	/** 
	 * check if we succeeded
	 */
	if (!cap.isOpened()) {
		cerr << "ERROR! Unable to open camera\n";
	}
}

/** 
 * @brief Capture GBR frame
 * @return GBR frame
 */
Mat Camera::capture() {
	Mat frame;
	cap.read(frame);
	// check if we succeeded
	if (frame.empty()) {
		cerr << "ERROR! blank frame grabbed\n";
	}
	return frame;
}

/** 
 * @brief Capture RGB frame
 * @return RGB frame
 */
cv::Mat Camera::captureRGB() {
	Mat frame = this->capture();
	Mat rgb;
	if (!frame.empty()) {
		cv::cvtColor(frame, rgb, cv::COLOR_BGR2RGB);
	}
	return rgb;
}

/** 
 * @brief Capture grayscame frame
 * @return grayscale frame
 */
cv::Mat Camera::captureGrayscale() {
	Mat frame = this->capture();
	Mat greyMat2;
	cv::cvtColor(frame, greyMat2, cv::COLOR_BGR2GRAY);
	return greyMat2;
}


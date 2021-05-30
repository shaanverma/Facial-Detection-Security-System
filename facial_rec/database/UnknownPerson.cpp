/** 
 * Unknown person
 * @brief Stores information about the unknown person (images).
 * @author group53
 */
#include "UnknownPerson.h"
#include <opencv2/core.hpp>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

/** 
 * Constructor that creates an unknown person object
 * @param images images of known person
 */
UnknownPerson::UnknownPerson(vector<cv::Mat> imgs) {
	images = imgs;
}

/** 
 * Destructor
 */
UnknownPerson::~UnknownPerson() {
}

/** 
 * Set person's images
 * @param imgs
 */
void UnknownPerson::setImage(vector<cv::Mat> imgs) {
	images = imgs;
}

/** 
 * Get person's images
 * @return images
 */
vector<cv::Mat> UnknownPerson::getImage() {
	return images;
}



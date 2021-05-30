/** 
 * Unknown person class
 * @brief Stores information about the unknown person (images).
 * @author group53
 */

#ifndef UNKNOWNPERSON_CLASS_H
#define UNKNOWNPERSON_CLASS_H
#include <string>
#include <vector>
#include <opencv2/core.hpp>

class UnknownPerson {
 public:
  std::vector<cv::Mat> images; /**< person's images */ 

  /** 
   * @brief Constructor that creates an unknown person object
   * @param images images of unknown person
   */
  UnknownPerson(std::vector<cv::Mat> imgs);
  
  /** 
   * @brief Destructor
   */
  ~UnknownPerson();

  /** 
   * @brief Set person's images
   * @param imgs
   */
  void setImage(std::vector<cv::Mat> imgs);

  /** 
   * @brief Get person's images
   * @return imgs
   */
  std::vector<cv::Mat> getImage();

};

#endif
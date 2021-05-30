/** 
 * Known person class
 * @brief Stores information about the known person (name, phone number, images).
 * @author group53
 */

#ifndef KNOWNPERSON_CLASS_H
#define KNOWNPERSON_CLASS_H
#include <string>
#include <vector>
#include <opencv2/core.hpp>

class KnownPerson {
 public:
  
  std::string firstName; /**< person's first name */ 
  std::string lastName; /**< person's last name */ 
  std::string phoneNumber; /**< person's phone number */ 
  std::vector<cv::Mat> images; /**< person's images */ 

  /** 
   * @brief Constructor that creates a known person object
   * @param first_name first name
   * @param last_name last name
   * @param phone_number phone number
   * @param images images of known person
   */
  KnownPerson(const std::string &first_name,
              const std::string &last_name,
              const std::string &phone_number,
              const std::vector<cv::Mat> &images);

  /** 
   * @brief Destructor
   */
  ~KnownPerson();

  /** 
   * @brief Set person's first name
   * @param fName
   */
  void setFirstName(std::string fName);

  /** 
   * @brief Set person's last name
   * @param lName
   */
  void setLastName(std::string lName);
  
  /** 
   * @brief Set person's phone number
   * @param pNum
   */
  void setPhoneNumber(std::string pNum);
  
  /** 
   * @brief Set person's images
   * @param imgs
   */
  void setImage(std::vector<cv::Mat> imgs);

  /** 
   * @brief Get person's first name
   * @return first name
   */
  std::string getFirstName();

  /** 
   * @brief Get person's last name
   * @return last name
   */
  std::string getLastName();

  /** 
   * @brief Get person's phone number
   * @return phone number
   */
  std::string getPhoneNumber();

  /** 
   * @brief Get person's images
   * @return images
   */
  std::vector<cv::Mat> getImage();
};

#endif
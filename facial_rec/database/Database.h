/** 
 * Database class.
 * Database that stores known and unknown people.
 * @author group53
 */

#ifndef DATABASE_CLASS_H
#define DATABASE_CLASS_H
#include <string>
#include <vector>
#include "KnownPerson.h"
#include "UnknownPerson.h"

class Database {
 public:
  /** 
   * @brief Delete the copy assignment operator
   */
  void operator=(const Database &) = delete;
  
   /** 
   * @brief Create an instance of the database class using Singleton design pattern
   */ 
  static Database &getInstance() {
	  static Database _instance;
	  return _instance;
  }
  /** 
   * @brief Destructor
   */
  ~Database();

  /** 
   * @brief Add a known person to the database
   * @param kPerson new known person
   */
  int addKnownPerson(KnownPerson kPerson);

  /** 
   * @brief Add an unknown person to the database
   * @param ukPerson new known person
   */
  void addUnknownPerson(UnknownPerson ukPerson);
  
  /** 
   * @brief Get a known person from the database
   * @param b known person index
   */
  KnownPerson operator[](int b);
  
  /**
  * @brief Get number of known people
  */
  int knownSize();
 
 
 private:
  Database();
  std::vector<KnownPerson> known;
  std::vector<UnknownPerson> unknown;

};

#endif

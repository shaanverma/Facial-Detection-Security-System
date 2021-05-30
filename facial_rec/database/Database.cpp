/** 
 * Database that stores known and unknown people.
 * @author group53
 */

#include "Database.h"
#include "KnownPerson.h"
#include "UnknownPerson.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/** 
 * @brief Constructor that creates a database object
 */
Database::Database() = default;

/** 
 * Destructor
 */
Database::~Database() = default;

/** 
 * @brief Add a known person to the database
 * @param kPerson new known person
 * @return number of known people
 */
int Database::addKnownPerson(KnownPerson kPerson) {
	known.push_back(kPerson);
	return knownSize() - 1;
}

/** 
 * @brief Add an unknown person to the database
 * @param ukPerson new unknown person
 */
void Database::addUnknownPerson(UnknownPerson ukPerson) {
	unknown.push_back(ukPerson);
}

/** 
 * @brief Get a known person from the database
 * @param b known person index
 * @return known person
 */
KnownPerson Database::operator[](int b) {
	return known[b];
}

/** 
 * @brief Get number of known people
 * @return number of known people
 */
int Database::knownSize() {
	return known.size();
}


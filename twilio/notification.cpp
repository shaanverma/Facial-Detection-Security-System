/**
@brief: Provides the system a method of sending a text notification.
@author:Group53
**/

#include "notification.h"
//#include <iostream>
#include "twilio.h"
#include <string>
using namespace std;

/**
@brief: Constructor that creates a database object
@param: none
@return: none
**/
notification::notification() {
    string account_sid = "ACcb6b0c1f3b03f080a6e0c64b2e11d177";
    string auth_token = "35044a065e00e6add3ce78dedb93a0be";
    string message_body = "Hmm...Looks like someone I don't recognize is at your door";
    string from_number = "+12185302718";
    string to_number = "+5198525738";
    string picture_url = "";
    bool verbose = false;

}

string response;
auto Twilio::twilio = std::make_shared<twilio::Twilio>(
    account_sid,
    auth_token
);

//Determines if the message was sent successfully
bool message_success = twilio->send_message(
        to_number,
        from_number,
        message,
        response,
        picture_url,
        verbose
);

/**
@brief: Destructor
@param: none
@return: none
**/
notification::~notification() {
}



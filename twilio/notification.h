#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <string>


class notification {
 public:
 

    // Constructor
    notification();
    
    // Destructor
    ~notification();

    
private:
    std::string account_sid;
    std::string auth_token;
    std::string message_body;
    std::string from_number;
    std::string to_number;
    std::string picture_url;
    bool verbose;

};

#endif

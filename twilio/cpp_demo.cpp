
// taken from https://github.com/TwilioDevEd/twilio_cpp_demo/blob/b27466ab64ffd9e8c844d3082f111b2b1c391980/src/twilio.cc
/*
* This example demonstrates sending a SMS or MMS in C++ using the Twilio REST
* APIs.  After building, you should be able to run it with:
*
* ./bin/cpp_demo
*
*/

#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cpp_demo"
#include "twilio.h"

int main(int argc, char * argv[])
{
        int cmd;
        std::string account_sid = "ACcb6b0c1f3b03f080a6e0c64b2e11d177";
        std::string auth_token = "35044a065e00e6add3ce78dedb93a0be";
        std::string message = "Hmm...Looks like someone I don't recognize is at your door";
        std::string from_number = "+12185302718";
        std::string to_number = "+5198525738";
        std::string picture_url = "";
        bool verbose = false;


        opterr = 0;

        while ((cmd = getopt(argc, argv, "a:s:m:f:t:p:vh?")) != -1) {
                switch (cmd) {
                        case '?':
                        case 'h':
                                printf("Twilio C++ Example Help:\n");
                                printf("-a: Account\t\t"
                                       "(ex: -a \"ACXXXXX\")\n");
                                printf("-s: Auth Token\t\t"
                                       "(ex: -s \"your_token\")\n");
                                printf("-f: From Number\t\t"
                                       "(ex: -f \"+18005551212\")\n");
                                printf("-t: To Number\t\t"
                                       "(ex: -t \"+18005551212\")\n");
                                printf("-m: Message to send\t"
                                       "(ex: -m \"Hello, Twilio!\")\n");
                                printf("-p: (Opt.) URL to Image\t"
                                       "(ex: -p \"Hello, Twilio!\")\n");
                                printf("-v: Verbose Mode\n");
                                printf("-h: This help dialog\n");
                                return 0;
                        case 'a':
                                account_sid = optarg;
                                break;
                        case 's':
                                auth_token = optarg;
                                break;
                        case 'm':
                                message = optarg;
                                break;
                        case 'f':
                                from_number = optarg;
                                break;
                        case 't':
                                to_number = optarg;
                                break;
                        case 'p':
                                picture_url = optarg;
                                break;
                        case 'v':
                                verbose = true;
                                break;
                        default:
                                abort();
                }
        }

        if ( account_sid.empty() or auth_token.empty() or from_number.empty()
                or to_number.empty() or message.empty() ) {
                std::cout<< "You didn't include all necessary inputs!\n"
                        "Call using -h for help.\n" << std::endl;
                return -1;
        }

        // Instantiate a twilio object and call send_message
        std::string response;
        auto twilio = std::make_shared<twilio::Twilio>(
            account_sid,
            auth_token
        );
        
        bool message_success = twilio->send_message(
                to_number,
                from_number,
                message,
                response,
                picture_url,
                verbose
        );

       
        // Report success or failure
        if (!message_success) {
                if (verbose) {
                        std::cout << "Message send failed." << std::endl;
                        if (!response.empty()) {
                                std::cout << "Response:" << std::endl
                                        << response << std::endl;
                        }
                }
                return -1;
        } else if (verbose) {
                std::cout << "SMS sent successfully!" << std::endl;
                std::cout << "Response:" << std::endl << response
                        << std::endl;
        }

        return 0;
}




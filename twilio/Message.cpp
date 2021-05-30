#include "Message.h"
#include "twilio.h"
Message::~Message() {

}
Message::Message() {
	time(&timer);
}
void Message::run(Result r) {
	time(&timer);
	if (difftime(timer, lasttimer) > 30 && r.personID == -2) {
		auto account_sid = "AC11538a9898674364c3e62265d4aca88d";
		auto auth_token = "139072545bb77e074914b19002fd4d2f";
		auto message_body = "Hmm...Looks like someone I don't recognize is at your door";
		auto from_number = "+19207728989";
		auto picture_url = "";
		bool verbose = false;

		auto opterr = 0;

		// Instantiate a twilio object and call send_message
		std::string response;
		auto twilio = std::make_shared<twilio::Twilio>(
			account_sid,
			auth_token
		);
		for (int i = 0; i < Database::getInstance().knownSize(); ++i) {
			twilio->send_message(
				Database::getInstance()[i].getPhoneNumber(),
				from_number,
				message_body,
				response,
				picture_url,
				verbose
			);
		}

		time(&lasttimer);
	}
}
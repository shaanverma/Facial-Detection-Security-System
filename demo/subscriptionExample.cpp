#include "demo/subscriptionExample.h"
#include <QDebug>

subscriptionExample::subscriptionExample() {
	time(&timer);
}
void subscriptionExample::run(Result r) {
	time(&timer);
	if (difftime(timer, lasttimer) > 30) {
		qDebug() << "hello" << endl;
		time(&lasttimer);
	}

}

subscriptionExample::~subscriptionExample() = default;

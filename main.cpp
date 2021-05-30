/**
main.cpp
@brief: Runs the facial recognition security system with a user interface.
@author: Group53
**/

#include "UI/mainwindow.h"
#include <QApplication>
#include <utility>
#include <screenshots/SaveScreenshot.h>
#include "twilio/Message.h"

int main(int argc, char *argv[]) {
	//pointer to save a screenshot
	auto *screenshot = new SaveScreenshot();

	//facial recognition
	FaceRecognizer::getRecognizer().onPrediction([screenshot](Result r) {
	  screenshot->run(std::move(r));
	});
	auto *message = new Message();

	FaceRecognizer::getRecognizer().onPrediction([message](Result r) {
	  message->run(std::move(r));
	});

	//User interface
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();

}

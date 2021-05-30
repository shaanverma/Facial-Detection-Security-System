/**
@brief: 
@author: Group53
**/

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./addnewuser.h"

#include <QTimer>
#include <QDebug>

#include <cstdlib>

#include "../facial_rec/camera/Camera.h"
#include "../facial_rec/FaceRecognizer.h"
#include <bits/stdc++.h>

/**
@brief: Constructor
@param: *parent
@return: none
**/
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	kprevTime = time(NULL);
	ukprevTime = time(NULL);

	timer = new QTimer(this);
	system("aplay ../audio/launch.wav");
	predictionTimer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &MainWindow::updateImage);
	connect(predictionTimer, &QTimer::timeout, this, &MainWindow::updatePrediction);
	timer->start(10);
	predictionTimer->start(1000);
}

/**
@brief: Updates the camera image when it is not empty
@param: none 
@return: none
**/
void MainWindow::updateImage() {
	Camera c = Camera::getInstance();
	auto img = c.captureRGB();
	if (!img.empty()) {
		ui->cameraImage->setPixmap(QPixmap::fromImage(QImage(img.data,
		                                                     img.cols,
		                                                     img.rows,
		                                                     img.step,
		                                                     QImage::Format_RGB888)));
	}
}

/**
@brief: update the prediction text
@param: none
@return: none
**/
void MainWindow::updatePrediction() {

	if (!FaceRecognizer::getRecognizer().isEmpty()) {
		curTime = time(NULL);
		kdiffTime = curTime - kprevTime;
		ukdiffTime = curTime - ukprevTime;
		Camera c = Camera::getInstance();
		auto img = c.captureGrayscale();
		if (!img.empty()) {
			auto pred = FaceRecognizer::getRecognizer().predict(img);
			int i = pred.personID;
			if (i > -1) {
				auto person = FaceRecognizer::getPersonByID(i);
				ui->prediction->setText("Hello " + 
					QString::fromStdString(person.firstName) + "\n" + QString::number(pred.confidence) + " "
						+ QString::number(pred.distance));
				if (kdiffTime >= 30){
					system("aplay ../audio/welcomeback.wav");
					kprevTime = time(NULL);
				}
			} else if (i == -1) {
				ui->prediction->setText("No faces found " + QString::number(pred.confidence));
			} else {
				ui->prediction->setText("Unknown person found");
				if (ukdiffTime >= 30){
					system("aplay ../audio/doorbell.wav");
					ukprevTime = time(NULL);
				}	
			}
		}
	} else {
		ui->prediction->setText("No users in database");
	}
}

/**
@brief: Destructor
@param: none
@return: none
**/
MainWindow::~MainWindow() {
	delete ui;
}

/**
@brief: Rings a the doorbell when the button is clicked
@param: none
@return: none
**/
void MainWindow::on_audioButton_clicked() {
	system("aplay ../audio/doorbell.wav");

}

/**
@brief: action for "View Screenshots"
@param: none
@return: none
**/
void MainWindow::on_pushButton_clicked() {
    system("/usr/bin/pcmanfm ./screenshots");

}

/**
@brief: action for add new user
@param: none
@return: none
**/
void MainWindow::on_actionAdd_New_User_triggered() {
	newuserdialog = new AddNewUser();
	newuserdialog->show();
}

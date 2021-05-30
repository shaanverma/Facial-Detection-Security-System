/**
@author: Group53
@brief: This class provides the UI fuctionality to add a new user to the system
**/

#include "addnewuser.h"
#include "ui_addnewuser.h"
#include "../facial_rec/camera/Camera.h"
#include <QDebug>

/**
@brief: Constructor
@param: *parent
@return: none
**/
AddNewUser::AddNewUser(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddNewUser) {
	ui->setupUi(this);
}

/**
@brief: Destructor
@param: none
@return: none
**/
AddNewUser::~AddNewUser() {
	delete ui;
}

/**
@brief: Captures an image of the user with information, and adds it to the image vector.
@param: none
@return: none
**/
void AddNewUser::on_captureButton_clicked() {
	Camera c = Camera::getInstance();
	auto frame = c.captureGrayscale();
	images.push_back(frame);
}

/**
@brief: Action for user submission
@param: none
@return: none
**/
void AddNewUser::on_buttonBox_accepted() {
	KnownPerson person = KnownPerson(ui->firstname->text().toStdString(),
	                                 ui->lastname->text().toStdString(),
	                                 ui->phone->text().toStdString(),
	                                 images);
	FaceRecognizer::getRecognizer().addPerson(person);
	this->close();
}

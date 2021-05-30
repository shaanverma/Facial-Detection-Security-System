/**
@brief: Provides a blueprint to addnewuser.cpp
@author: Group53
**/

#ifndef ADDNEWUSER_H
#define ADDNEWUSER_H

#include <QDialog>
#include <vector>
#include "../facial_rec/FaceRecognizer.h"

namespace Ui {
class AddNewUser;
}

class AddNewUser : public QDialog {
 Q_OBJECT

 public:
  explicit AddNewUser(QWidget *parent = nullptr);
  ~AddNewUser();

 private slots:
  void on_captureButton_clicked();
  void on_buttonBox_accepted();

 private:
  Ui::AddNewUser *ui;
  FaceRecognizer recog = FaceRecognizer::getRecognizer();
  std::vector<cv::Mat> images;
};

#endif // ADDNEWUSER_H

/**
@brief: Provides classes and fuction prototypes to mainwindow.cpp
@author: Group53
**/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>

#include "../facial_rec/camera/Camera.h"
#include "../facial_rec/FaceRecognizer.h"
#include "./addnewuser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  //constructor
  MainWindow(QWidget *parent = nullptr);
  //destructor
  ~MainWindow();

 //functions
 private slots:
  void on_pushButton_clicked();
  void updateImage();
  void updatePrediction();

  void on_actionAdd_New_User_triggered();
  void on_audioButton_clicked();

 //variables and pointers
 private:
  QTimer *timer;
  QTimer *predictionTimer;
  long curTime;
  long kprevTime;
  long kdiffTime;
  long ukprevTime;
  long ukdiffTime;
  Ui::MainWindow *ui;
  AddNewUser *newuserdialog;

};
#endif // MAINWINDOW_H

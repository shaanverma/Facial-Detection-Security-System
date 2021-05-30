/**
@brief: Header for SaveScreenshot.cpp
@author: Group53
**/
#ifndef CS3307_SAVESCREENSHOT_H
#define CS3307_SAVESCREENSHOT_H

#include <ctime>
#include <facial_rec/FaceRecognizer.h>
#include <QDebug>

class SaveScreenshot {
public:
    SaveScreenshot();
    ~SaveScreenshot();
    void run(Result r);

private:
    time_t timer;
    time_t lasttimer = 0;
    int count;
};


#endif //CS3307_SAVESCREENSHOT_H

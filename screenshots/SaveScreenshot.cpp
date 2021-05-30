/**
@brief: Saves a screenshot from the camera to a directory
@author: Group53
**/
#include <string>
#include "SaveScreenshot.h"
#include <filesystem>
namespace fs = std::filesystem;

/**
@brief: Constructor
@param: none
@return: none
**/
SaveScreenshot::SaveScreenshot() {
    time(&timer);
    fs::remove_all("./screenshots");
    fs::create_directory("./screenshots");
}

/**
@brief: triggers the screenshot
@param: none
@return: none
**/
void SaveScreenshot::run(Result r) {
    time(&timer);
    if (difftime(timer, lasttimer) > 30) {
        if (r.personID == -2){
            bool t = imwrite("./screenshots/test" + std::to_string(count) + ".bmp",  r.image);
            count++;
            time(&lasttimer);
        }


    }

}

SaveScreenshot::~SaveScreenshot() = default;

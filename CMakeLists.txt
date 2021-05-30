cmake_minimum_required(VERSION 3.16)
project(cs3307)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
if (UNIX)
    set(CURL_LIBRARY "-lcurl")
    set(CURL_INCLUDE_DIR)
    find_package(CURL REQUIRED)

    find_package(OpenCV REQUIRED)
    include_directories(${OpenCV_INCLUDE_DIRS})
endif ()
add_executable(cs3307 main.cpp
        facial_rec/database/Database.cpp facial_rec/database/Database.h
        facial_rec/database/KnownPerson.cpp facial_rec/database/KnownPerson.h
        facial_rec/database/UnknownPerson.cpp facial_rec/database/UnknownPerson.h
        facial_rec/FaceRecognizer.cpp facial_rec/FaceRecognizer.h
        twilio/twilio.cpp twilio/twilio.h twilio/type_conversion.h
        facial_rec/camera/Camera.cpp facial_rec/camera/Camera.h
        UI/mainwindow.cpp UI/mainwindow.h UI/mainwindow.ui
        UI/addnewuser.cpp UI/addnewuser.h UI/addnewuser.ui
        facial_rec/facial_detc/FaceDetection.cpp facial_rec/facial_detc/FaceDetection.h
        demo/subscriptionExample.cpp demo/subscriptionExample.h
        screenshots/SaveScreenshot.cpp screenshots/SaveScreenshot.h
        twilio/Message.cpp twilio/Message.h)
if (UNIX)
    target_link_libraries(cs3307 ${OpenCV_LIBS})
    include_directories(${CURL_INCLUDE_DIR})
    target_link_libraries(cs3307 ${CURL_LIBRARIES})
endif ()
target_link_libraries(cs3307 Qt5::Widgets)
target_link_libraries(cs3307 stdc++fs)

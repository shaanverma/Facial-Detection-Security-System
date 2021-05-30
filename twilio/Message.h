#ifndef CS3307_TWILIO_MESSAGE_H_
#define CS3307_TWILIO_MESSAGE_H_

#include <facial_rec/FaceRecognizer.h>

class Message {
 public:
  Message();
  virtual ~Message();
  void run(Result r);
 private:
  time_t timer;
  time_t lasttimer = 0;
};

#endif //CS3307_TWILIO_MESSAGE_H_
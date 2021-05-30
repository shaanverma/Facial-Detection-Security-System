#ifndef CS3307_UI_SUBSCRIPTIONEXAMPLE_H_
#define CS3307_UI_SUBSCRIPTIONEXAMPLE_H_

#include <ctime>
#include <facial_rec/FaceRecognizer.h>

class subscriptionExample {
 public:
  subscriptionExample();
  virtual ~subscriptionExample();
  void run(Result r);
 private:
  time_t timer;
  time_t lasttimer = 0;

};

#endif //CS3307_UI_SUBSCRIPTIONEXAMPLE_H_

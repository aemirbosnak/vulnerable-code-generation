//FormAI DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
  bool isOn;
  int brightness;
} Light;

void turnOn(Light* light) {
  light->isOn = true;
  printf("Light turned on!\n");
}

void turnOff(Light* light) {
  light->isOn = false;
  printf("Light turned off!\n");
}

bool isMotionDetected() {
  srand(time(NULL));
  return rand() % 2;
}

void checkMotionSensor(Light* light) {
  if (isMotionDetected()) {
    turnOn(light);
  }
  else {
    turnOff(light);
  }
}

int main() {
  Light kitchenLight = {false, 0};
  Light livingRoomLight = {false, 0};
  
  // set kitchen light to turn on everyday at 6pm
  int hour = 18;
  int minute = 0;
  while (true) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    if (tm->tm_hour == hour && tm->tm_min == minute) {
      turnOn(&kitchenLight);
    }
  }
  
  // check motion sensor every minute for living room light
  while (true) {
    sleep(60);
    checkMotionSensor(&livingRoomLight);
  }
  
  return 0;
}
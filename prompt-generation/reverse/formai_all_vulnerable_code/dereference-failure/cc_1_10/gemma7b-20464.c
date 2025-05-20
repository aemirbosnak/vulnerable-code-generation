//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSOR_NUM 10
#define MAX_EVENT_NUM 20

typedef struct Sensor {
  int sensor_num;
  char status;
  char event_type;
  struct Sensor *next;
} Sensor;

typedef struct Event {
  char event_type;
  char event_time;
  struct Event *next;
} Event;

Sensor *sensors = NULL;
Event *events = NULL;

void insertSensor(int sensor_num, char status, char event_type) {
  Sensor *newSensor = (Sensor *)malloc(sizeof(Sensor));
  newSensor->sensor_num = sensor_num;
  newSensor->status = status;
  newSensor->event_type = event_type;
  newSensor->next = NULL;

  if (sensors == NULL) {
    sensors = newSensor;
  } else {
    sensors->next = newSensor;
    sensors = newSensor;
  }
}

void insertEvent(char event_type, char event_time) {
  Event *newEvent = (Event *)malloc(sizeof(Event));
  newEvent->event_type = event_type;
  newEvent->event_time = event_time;
  newEvent->next = NULL;

  if (events == NULL) {
    events = newEvent;
  } else {
    events->next = newEvent;
    events = newEvent;
  }
}

int main() {
  insertSensor(1, 'A', 'S');
  insertSensor(2, 'B', 'A');
  insertSensor(3, 'C', 'E');

  insertEvent('R', '08:00');
  insertEvent('T', '08:05');
  insertEvent('A', '08:10');

  Sensor *sensor = sensors;
  Event *event = events;

  while (sensor) {
    printf("Sensor %d: status %c, event type %c\n", sensor->sensor_num, sensor->status, sensor->event_type);
    sensor = sensor->next;
  }

  while (event) {
    printf("Event type %c, time %s\n", event->event_type, event->event_time);
    event = event->next;
  }

  return 0;
}
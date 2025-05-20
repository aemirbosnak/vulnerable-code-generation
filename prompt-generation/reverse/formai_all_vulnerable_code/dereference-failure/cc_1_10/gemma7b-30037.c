//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

typedef struct Sensor {
  int sensor_id;
  char sensor_name[20];
  char sensor_location[20];
  int sensor_status;
  struct Sensor* next;
} Sensor;

Sensor* sensor_list = NULL;

void sensor_add(int sensor_id, char* sensor_name, char* sensor_location) {
  Sensor* new_sensor = (Sensor*)malloc(sizeof(Sensor));
  new_sensor->sensor_id = sensor_id;
  strcpy(new_sensor->sensor_name, sensor_name);
  strcpy(new_sensor->sensor_location, sensor_location);
  new_sensor->sensor_status = 0;
  new_sensor->next = sensor_list;
  sensor_list = new_sensor;
}

void sensor_check() {
  Sensor* current_sensor = sensor_list;
  while (current_sensor) {
    // Simulate sensor status change
    current_sensor->sensor_status = rand() % 2;

    // Log sensor status change
    printf("Sensor %d: Status changed to %d\n", current_sensor->sensor_id, current_sensor->sensor_status);
    sleep(1);
  }
}

int main() {
  // Initialize sensor list
  sensor_add(1, "Kitchen Light", "Kitchen");
  sensor_add(2, "Living Room Light", "Living Room");
  sensor_add(3, "Bedroom Light", "Bedroom");

  // Sensor check loop
  while (1) {
    sensor_check();
    sleep(5);
  }

  return 0;
}
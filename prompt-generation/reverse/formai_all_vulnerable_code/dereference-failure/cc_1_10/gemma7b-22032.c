//Gemma-7B DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#define debug(x) printf x
#else
#define debug(x)
#endif

#define MAX_TEMP 50
#define TEMP_STEP 1

struct Sensor {
  int id;
  float temperature;
  struct Sensor* next;
};

void update_sensor(struct Sensor* sensor, float new_temperature) {
  sensor->temperature = new_temperature;
  if (sensor->next) {
    update_sensor(sensor->next, new_temperature);
  }
}

void print_sensors(struct Sensor* sensor) {
  printf("Sensor ID: %d, Temperature: %.2f\n", sensor->id, sensor->temperature);
  if (sensor->next) {
    print_sensors(sensor->next);
  }
}

int main() {
  struct Sensor* head = NULL;

  // Create a few sensors
  struct Sensor* sensor1 = malloc(sizeof(struct Sensor));
  sensor1->id = 1;
  sensor1->temperature = 25.0f;
  sensor1->next = NULL;

  struct Sensor* sensor2 = malloc(sizeof(struct Sensor));
  sensor2->id = 2;
  sensor2->temperature = 30.0f;
  sensor2->next = sensor1;

  struct Sensor* sensor3 = malloc(sizeof(struct Sensor));
  sensor3->id = 3;
  sensor3->temperature = 20.0f;
  sensor3->next = sensor2;

  head = sensor3;

  // Update the sensors' temperatures
  update_sensor(head, 32.0f);

  // Print the sensors' temperatures
  print_sensors(head);

  return 0;
}
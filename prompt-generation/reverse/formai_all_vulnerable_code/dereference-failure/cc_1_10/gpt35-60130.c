//FormAI DATASET v1.0 Category: Temperature monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TEMP_THRESHOLD 100.0f

typedef struct temperature {
  float value;
  char unit[3];
  char timestamp[30];
} temperature_t;

typedef struct sensor {
  char name[20];
  int id;
  temperature_t *temp_data;
} sensor_t;

void display_temperature(sensor_t *sensor, temperature_t *temp_data) {
  printf("%s (Sensor ID: %d)\n", sensor->name, sensor->id);
  printf("Temperature: %.2f %s\n", temp_data->value, temp_data->unit);
  printf("Timestamp: %s\n", temp_data->timestamp);
}

void display_high_temperatures(sensor_t *sensors, int num_sensors) {
  int i;
  for(i = 0; i < num_sensors; i++) {
    if(sensors[i].temp_data->value > TEMP_THRESHOLD) {
      printf("High temperature detected!\n");
      display_temperature(&sensors[i], sensors[i].temp_data);
    }
  }
}

int main() {
  int num_sensors = 3;
  sensor_t sensors[3];

  //Initialize sensor data
  strcpy(sensors[0].name, "Sensor A");
  sensors[0].id = 1;
  sensors[0].temp_data = (temperature_t *) malloc(sizeof(temperature_t));
  sensors[0].temp_data->value = 97.5f;
  strcpy(sensors[0].temp_data->unit, "C");
  strcpy(sensors[0].temp_data->timestamp, "2021-04-12 09:30:22");

  strcpy(sensors[1].name, "Sensor B");
  sensors[1].id = 2;
  sensors[1].temp_data = (temperature_t *) malloc(sizeof(temperature_t));
  sensors[1].temp_data->value = 89.2f;
  strcpy(sensors[1].temp_data->unit, "C");
  strcpy(sensors[1].temp_data->timestamp, "2021-04-12 09:30:22");

  strcpy(sensors[2].name, "Sensor C");
  sensors[2].id = 3;
  sensors[2].temp_data = (temperature_t *) malloc(sizeof(temperature_t));
  sensors[2].temp_data->value = 105.1f;
  strcpy(sensors[2].temp_data->unit, "C");
  strcpy(sensors[2].temp_data->timestamp, "2021-04-12 09:30:22");

  display_high_temperatures(sensors, num_sensors);

  //Free dynamically allocated memory
  int i;
  for(i = 0; i < num_sensors; i++) {
    free(sensors[i].temp_data);
    sensors[i].temp_data = NULL;
  }

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEASUREMENTS 100

typedef struct Measurement {
  char date[MAX_MEASUREMENTS];
  int heart_rate;
  int blood_pressure[2];
  float temperature;
} Measurement;

Measurement measurements[MAX_MEASUREMENTS];

void initialize_measurements() {
  for (int i = 0; i < MAX_MEASUREMENTS; i++) {
    measurements[i].date[0] = '\0';
    measurements[i].heart_rate = 0;
    measurements[i].blood_pressure[0] = 0;
    measurements[i].blood_pressure[1] = 0;
    measurements[i].temperature = 0.0f;
  }
}

void add_measurement(char date, int heart_rate, int blood_pressure[2], float temperature) {
  int i = 0;
  for (; measurements[i].date[0] != '\0'; i++) {}
  measurements[i].date[0] = date;
  measurements[i].heart_rate = heart_rate;
  measurements[i].blood_pressure[0] = blood_pressure[0];
  measurements[i].blood_pressure[1] = blood_pressure[1];
  measurements[i].temperature = temperature;
}

void display_measurements() {
  for (int i = 0; measurements[i].date[0] != '\0'; i++) {
    printf("Date: %s\n", measurements[i].date);
    printf("Heart Rate: %d\n", measurements[i].heart_rate);
    printf("Blood Pressure: %d/%d\n", measurements[i].blood_pressure[0], measurements[i].blood_pressure[1]);
    printf("Temperature: %.2f\n", measurements[i].temperature);
    printf("\n");
  }
}

int main() {
  initialize_measurements();

  add_measurement('2023-01-01', 70, 120/80, 25.0f);
  add_measurement('2023-01-02', 65, 110/80, 23.5f);
  add_measurement('2023-01-03', 72, 130/80, 24.0f);

  display_measurements();

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

// Define the maximum and minimum temperatures that can be measured.
#define MAX_TEMP 100
#define MIN_TEMP -50

// Define the number of seconds between temperature measurements.
#define TEMP_INTERVAL 1

// Define the size of the buffer to store temperature measurements.
#define BUF_SIZE 100

// Define the number of measurements to average.
#define AVG_SIZE 10

// Define the temperature sensor data structure.
typedef struct {
  int temp;            // The temperature in degrees Celsius.
  unsigned long time;   // The time in seconds since the sensor was last read.
} temp_sensor_t;

// Define the temperature monitor data structure.
typedef struct {
  temp_sensor_t sensor;  // The temperature sensor.
  int avg_temp;          // The average temperature over the last AVG_SIZE measurements.
  int max_temp;          // The maximum temperature over the last AVG_SIZE measurements.
  int min_temp;          // The minimum temperature over the last AVG_SIZE measurements.
} temp_monitor_t;

// Create a new temperature sensor.
temp_sensor_t* temp_sensor_create(int temp, unsigned long time) {
  temp_sensor_t* sensor = (temp_sensor_t*)malloc(sizeof(temp_sensor_t));
  assert(sensor);
  sensor->temp = temp;
  sensor->time = time;
  return sensor;
}

// Destroy a temperature sensor.
void temp_sensor_destroy(temp_sensor_t* sensor) {
  free(sensor);
}

// Create a new temperature monitor.
temp_monitor_t* temp_monitor_create(temp_sensor_t* sensor) {
  temp_monitor_t* monitor = (temp_monitor_t*)malloc(sizeof(temp_monitor_t));
  assert(monitor);
  monitor->sensor = *sensor;
  monitor->avg_temp = 0;
  monitor->max_temp = INT_MIN;
  monitor->min_temp = INT_MAX;
  return monitor;
}

// Destroy a temperature monitor.
void temp_monitor_destroy(temp_monitor_t* monitor) {
  free(monitor);
}

// Update the temperature monitor with a new temperature measurement.
void temp_monitor_update(temp_monitor_t* monitor, temp_sensor_t* sensor) {
  // Calculate the average temperature.
  monitor->avg_temp = (monitor->avg_temp * (AVG_SIZE - 1) + sensor->temp) / AVG_SIZE;

  // Update the maximum and minimum temperatures.
  if (sensor->temp > monitor->max_temp) {
    monitor->max_temp = sensor->temp;
  }
  if (sensor->temp < monitor->min_temp) {
    monitor->min_temp = sensor->temp;
  }
}

// Print the temperature monitor data.
void temp_monitor_print(temp_monitor_t* monitor) {
  printf("Current temperature: %d degrees Celsius\n", monitor->sensor.temp);
  printf("Average temperature: %d degrees Celsius\n", monitor->avg_temp);
  printf("Maximum temperature: %d degrees Celsius\n", monitor->max_temp);
  printf("Minimum temperature: %d degrees Celsius\n", monitor->min_temp);
}

// Main function.
int main(void) {
  // Create a temperature sensor.
  temp_sensor_t* sensor = temp_sensor_create(20, 0);

  // Create a temperature monitor.
  temp_monitor_t* monitor = temp_monitor_create(sensor);

  // Update the temperature monitor with a new temperature measurement.
  temp_monitor_update(monitor, sensor);

  // Print the temperature monitor data.
  temp_monitor_print(monitor);

  // Destroy the temperature monitor.
  temp_monitor_destroy(monitor);

  // Destroy the temperature sensor.
  temp_sensor_destroy(sensor);

  return 0;
}
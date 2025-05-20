//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10
#define TEMP_RANGE_MIN -100
#define TEMP_RANGE_MAX 1000

typedef struct {
    char name[32];
    int min_temp;
    int max_temp;
    int current_temp;
} sensor_t;

void initialize_sensors(sensor_t sensors[], int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        strcpy(sensors[i].name, "Sensor ");
        char num_str[3];
        sprintf(num_str, "%d", i + 1);
        strcat(sensors[i].name, num_str);
        sensors[i].min_temp = TEMP_RANGE_MIN;
        sensors[i].max_temp = TEMP_RANGE_MAX;
        sensors[i].current_temp = 0;
    }
}

void print_sensor_info(sensor_t sensor) {
    printf("Name: %s\n", sensor.name);
    printf("Min Temp: %d\n", sensor.min_temp);
    printf("Max Temp: %d\n", sensor.max_temp);
    printf("Current Temp: %d\n\n", sensor.current_temp);
}

int read_sensor_data(sensor_t sensors[], int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        int temp = rand() % (TEMP_RANGE_MAX - TEMP_RANGE_MIN + 1) + TEMP_RANGE_MIN;
        if (temp < sensors[i].min_temp || temp > sensors[i].max_temp) {
            printf("Sensor %d: Temperature out of range!\n", i + 1);
        } else {
            sensors[i].current_temp = temp;
            printf("Sensor %d: Current Temp: %d\n", i + 1, temp);
        }
    }
    return 0;
}

int main() {
    int num_sensors = 5;
    sensor_t sensors[MAX_SENSORS];
    initialize_sensors(sensors, num_sensors);
    printf("Initializing sensors...\n");
    for (int i = 0; i < num_sensors; i++) {
        print_sensor_info(sensors[i]);
    }
    printf("Reading sensor data...\n");
    read_sensor_data(sensors, num_sensors);
    return 0;
}
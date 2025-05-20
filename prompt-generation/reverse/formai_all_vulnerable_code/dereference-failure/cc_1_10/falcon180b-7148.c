//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_LENGTH 20
#define SENSOR_VALUE_LENGTH 10
#define SENSOR_DATA_LENGTH (SENSOR_NAME_LENGTH + SENSOR_VALUE_LENGTH + 2)
#define SENSOR_DATA_FORMAT "%.2f"

typedef struct sensor_t {
    char name[SENSOR_NAME_LENGTH];
    double value;
} sensor_t;

sensor_t sensors[MAX_SENSORS];
int num_sensors = 0;

void add_sensor(char* name, double value) {
    if (num_sensors >= MAX_SENSORS) {
        printf("Error: Maximum number of sensors reached.\n");
        return;
    }
    strcpy(sensors[num_sensors].name, name);
    sensors[num_sensors].value = value;
    num_sensors++;
}

void display_sensors() {
    printf("Sensor Data:\n");
    for (int i = 0; i < num_sensors; i++) {
        printf(SENSOR_DATA_FORMAT " %s\n", sensors[i].value, sensors[i].name);
    }
}

int main() {
    char input[100];
    while (1) {
        printf("Enter sensor name and value (format: name value): ");
        fgets(input, 100, stdin);
        char* name = strtok(input, " ");
        double value = atof(strtok(NULL, " "));
        add_sensor(name, value);
        display_sensors();
        printf("\n");
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_SENSORS 10

typedef struct {
    char name[20];
    double temperature;
} TemperatureSensor;

TemperatureSensor sensors[MAX_TEMP_SENSORS];
int numSensors;

void addSensor(char* name, double temperature) {
    if (numSensors >= MAX_TEMP_SENSORS) {
        printf("Error: Maximum number of sensors reached. ");
        return;
    }

    strcpy(sensors[numSensors].name, name);
    sensors[numSensors].temperature = temperature;
    numSensors++;
}

void printSensors() {
    printf("Temperature Sensors:\n");
    for (int i = 0; i < numSensors; i++) {
        printf("%s: %.2f C\n", sensors[i].name, sensors[i].temperature);
    }
}

void updateSensors() {
    time_t now = time(NULL);
    struct tm* timeInfo = localtime(&now);

    for (int i = 0; i < numSensors; i++) {
        sensors[i].temperature = (double) timeInfo->tm_hour + (double) timeInfo->tm_min / 60.0;
    }
}

int main() {
    numSensors = 0;

    addSensor("CPU", 45.0);
    addSensor("GPU", 60.0);
    addSensor("HDD", 40.0);

    while (1) {
        updateSensors();
        printSensors();
        sleep(10);
    }

    return 0;
}
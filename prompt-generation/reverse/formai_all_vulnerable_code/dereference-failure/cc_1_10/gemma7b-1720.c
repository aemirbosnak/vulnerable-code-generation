//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_SENSOR_NUMBER 10

typedef struct Sensor {
    int sensor_id;
    char *sensor_name;
    int sensor_status;
    struct Sensor *next;
} Sensor;

Sensor *sensors = NULL;

void addSensor(int sensor_id, char *sensor_name) {
    Sensor *newSensor = (Sensor *)malloc(sizeof(Sensor));
    newSensor->sensor_id = sensor_id;
    newSensor->sensor_name = sensor_name;
    newSensor->sensor_status = 0;
    newSensor->next = NULL;

    if (sensors == NULL) {
        sensors = newSensor;
    } else {
        sensors->next = newSensor;
        sensors = newSensor;
    }
}

void monitorSensors() {
    Sensor *currentSensor = sensors;
    while (currentSensor) {
        // Check sensor status and trigger alarm if necessary
        if (currentSensor->sensor_status) {
            printf("Sensor %d: %s is triggered!\n", currentSensor->sensor_id, currentSensor->sensor_name);
            system("beep");
        }
        currentSensor = currentSensor->next;
    }
}

int main() {
    // Add sensors
    addSensor(1, "Front Door");
    addSensor(2, "Back Door");
    addSensor(3, "Kitchen Window");

    // Monitor sensors
    while (1) {
        monitorSensors();
        sleep(1);
    }

    return 0;
}
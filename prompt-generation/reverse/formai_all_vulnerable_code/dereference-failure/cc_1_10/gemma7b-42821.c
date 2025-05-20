//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SENSOR_READING 5
#define SENSOR_THRESHOLD 3

struct Sensor {
    int sensor_id;
    char sensor_state;
    int reading;
    struct Sensor* next;
};

struct Sensor* sensor_head = NULL;

void insert_sensor(int sensor_id, char sensor_state, int reading) {
    struct Sensor* new_sensor = malloc(sizeof(struct Sensor));
    new_sensor->sensor_id = sensor_id;
    new_sensor->sensor_state = sensor_state;
    new_sensor->reading = reading;
    new_sensor->next = sensor_head;
    sensor_head = new_sensor;
}

void monitor_sensors() {
    struct Sensor* current_sensor = sensor_head;
    while (current_sensor) {
        printf("Sensor ID: %d, State: %c, Reading: %d\n", current_sensor->sensor_id, current_sensor->sensor_state, current_sensor->reading);
        current_sensor = current_sensor->next;
    }
}

void check_intrusion() {
    struct Sensor* current_sensor = sensor_head;
    while (current_sensor) {
        if (current_sensor->reading > SENSOR_THRESHOLD) {
            printf("Intrusion detected at Sensor ID: %d\n", current_sensor->sensor_id);
            // Take appropriate actions, such as logging, alerting, or activating security measures
        }
        current_sensor = current_sensor->next;
    }
}

int main() {
    insert_sensor(1, 'A', 4);
    insert_sensor(2, 'B', 5);
    insert_sensor(3, 'C', 2);
    insert_sensor(4, 'D', 6);
    insert_sensor(5, 'E', 3);

    monitor_sensors();

    check_intrusion();

    return 0;
}
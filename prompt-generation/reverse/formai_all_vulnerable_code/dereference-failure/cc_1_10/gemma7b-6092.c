//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

typedef struct SensorNode {
    int sensor_id;
    struct SensorNode* next;
} SensorNode;

SensorNode* sensor_head = NULL;

void add_sensor(int sensor_id) {
    SensorNode* new_node = malloc(sizeof(SensorNode));
    new_node->sensor_id = sensor_id;
    new_node->next = sensor_head;
    sensor_head = new_node;
}

void monitor_sensors() {
    SensorNode* current_node = sensor_head;
    while (current_node) {
        // Simulate sensor reading
        int sensor_reading = rand() % 10;

        // Check if sensor reading is abnormal
        if (sensor_reading > 5) {
            printf("Sensor %d: ABNORMAL READING (%d)\n", current_node->sensor_id, sensor_reading);
        }
        current_node = current_node->next;
    }
}

int main() {
    // Add sensors
    add_sensor(1);
    add_sensor(2);
    add_sensor(3);

    // Monitor sensors repeatedly
    while (1) {
        monitor_sensors();
        sleep(1);
    }

    return 0;
}
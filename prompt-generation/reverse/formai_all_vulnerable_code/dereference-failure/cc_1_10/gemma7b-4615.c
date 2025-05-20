//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_SENSOR_NUM 10
#define MAX_EVENT_NUM 100

typedef struct Sensor {
    char name[20];
    int sensor_num;
    int event_num;
    int state;
    struct Sensor *next;
} Sensor;

Sensor *sensor_head = NULL;

void sensor_add(char *name, int sensor_num, int event_num) {
    Sensor *new_sensor = malloc(sizeof(Sensor));
    strcpy(new_sensor->name, name);
    new_sensor->sensor_num = sensor_num;
    new_sensor->event_num = event_num;
    new_sensor->state = 0;
    new_sensor->next = sensor_head;
    sensor_head = new_sensor;
}

void sensor_check(int sensor_num) {
    Sensor *current_sensor = sensor_head;
    while (current_sensor) {
        if (current_sensor->sensor_num == sensor_num) {
            current_sensor->state = 1;
            printf("Sensor %s is triggered!\n", current_sensor->name);
            break;
        }
        current_sensor = current_sensor->next;
    }
}

int main() {
    sensor_add("Front Door", 1, 10);
    sensor_add("Back Door", 2, 12);
    sensor_add("Kitchen Door", 3, 14);

    sensor_check(1);
    sensor_check(2);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SENSOR_COUNT 10

typedef struct Sensor {
    int sensor_id;
    char *sensor_name;
    int sensor_status;
    struct Sensor *next;
} Sensor;

Sensor *sensors = NULL;

void add_sensor(int sensor_id, char *sensor_name, int sensor_status) {
    Sensor *new_sensor = malloc(sizeof(Sensor));
    new_sensor->sensor_id = sensor_id;
    new_sensor->sensor_name = sensor_name;
    new_sensor->sensor_status = sensor_status;
    new_sensor->next = NULL;

    if (sensors == NULL) {
        sensors = new_sensor;
    } else {
        sensors->next = new_sensor;
        sensors = new_sensor;
    }
}

int main() {
    add_sensor(1, "Kitchen Door", 0);
    add_sensor(2, "Living Room Door", 1);
    add_sensor(3, "Back Door", 0);

    while (1) {
        Sensor *current_sensor = sensors;

        while (current_sensor) {
            if (current_sensor->sensor_status == 1) {
                system("play sound.wav");
                printf("Intruder alert at sensor %d: %s\n", current_sensor->sensor_id, current_sensor->sensor_name);
            }
            current_sensor = current_sensor->next;
        }

        sleep(1);
    }

    return 0;
}
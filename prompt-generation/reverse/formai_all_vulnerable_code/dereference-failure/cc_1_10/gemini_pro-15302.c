//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int value;
} sensor_t;

typedef struct {
    char *name;
    void (*action)(sensor_t *sensor);
} actuator_t;

typedef struct {
    sensor_t *sensors;
    actuator_t *actuators;
    int num_sensors;
    int num_actuators;
} smart_home_t;

void turn_on_light(sensor_t *sensor) {
    if (sensor->value > 100) {
        printf("Turning on light\n");
    }
}

void turn_off_light(sensor_t *sensor) {
    if (sensor->value < 100) {
        printf("Turning off light\n");
    }
}

void turn_on_fan(sensor_t *sensor) {
    if (sensor->value > 80) {
        printf("Turning on fan\n");
    }
}

void turn_off_fan(sensor_t *sensor) {
    if (sensor->value < 80) {
        printf("Turning off fan\n");
    }
}

int main() {
    smart_home_t home;
    home.sensors = malloc(sizeof(sensor_t) * 2);
    home.actuators = malloc(sizeof(actuator_t) * 2);
    home.num_sensors = 2;
    home.num_actuators = 2;

    home.sensors[0].name = "light sensor";
    home.sensors[0].value = 50;

    home.sensors[1].name = "temperature sensor";
    home.sensors[1].value = 75;

    home.actuators[0].name = "light";
    home.actuators[0].action = turn_on_light;

    home.actuators[1].name = "fan";
    home.actuators[1].action = turn_on_fan;

    for (int i = 0; i < home.num_sensors; i++) {
        for (int j = 0; j < home.num_actuators; j++) {
            if (strcmp(home.sensors[i].name, home.actuators[j].name) == 0) {
                home.actuators[j].action(&home.sensors[i]);
            }
        }
    }

    return 0;
}
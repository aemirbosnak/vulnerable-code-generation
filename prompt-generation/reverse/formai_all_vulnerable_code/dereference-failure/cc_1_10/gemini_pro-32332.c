//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 10

typedef enum {
    DEVICE_TYPE_LIGHT,
    DEVICE_TYPE_SWITCH,
    DEVICE_TYPE_SENSOR
} device_type_t;

typedef struct {
    char *name;
    device_type_t type;
    bool state;
} device_t;

device_t devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char *name, device_type_t type, bool state) {
    if (num_devices == MAX_DEVICES) {
        printf("Error: maximum number of devices reached.\n");
        return;
    }

    devices[num_devices].name = strdup(name);
    devices[num_devices].type = type;
    devices[num_devices].state = state;
    num_devices++;
}

void print_devices() {
    for (int i = 0; i < num_devices; i++) {
        printf("%s: ", devices[i].name);
        switch (devices[i].type) {
            case DEVICE_TYPE_LIGHT:
                printf("light");
                break;
            case DEVICE_TYPE_SWITCH:
                printf("switch");
                break;
            case DEVICE_TYPE_SENSOR:
                printf("sensor");
                break;
        }
        printf(" (%s)\n", devices[i].state ? "on" : "off");
    }
}

void toggle_device(char *name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = !devices[i].state;
            printf("%s %s\n", devices[i].name, devices[i].state ? "on" : "off");
            return;
        }
    }

    printf("Error: device not found.\n");
}

int main() {
    add_device("Kitchen Light", DEVICE_TYPE_LIGHT, false);
    add_device("Living Room Switch", DEVICE_TYPE_SWITCH, true);
    add_device("Front Door Sensor", DEVICE_TYPE_SENSOR, false);

    print_devices();

    toggle_device("Kitchen Light");
    toggle_device("Living Room Switch");

    print_devices();

    return 0;
}
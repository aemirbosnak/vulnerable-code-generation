//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef enum {
    DEVICE_TYPE_LIGHT,
    DEVICE_TYPE_SENSOR,
    DEVICE_TYPE_SWITCH
} device_type;

typedef struct {
    char *name;
    device_type type;
    int state;
} device;

device devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char *name, device_type type, int state) {
    if (num_devices >= MAX_DEVICES) {
        printf("Error: maximum number of devices reached\n");
        return;
    }

    devices[num_devices].name = strdup(name);
    devices[num_devices].type = type;
    devices[num_devices].state = state;

    num_devices++;
}

void remove_device(char *name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            free(devices[i].name);
            for (int j = i; j < num_devices - 1; j++) {
                devices[j] = devices[j + 1];
            }
            num_devices--;
            return;
        }
    }

    printf("Error: device not found\n");
}

void toggle_device(char *name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = !devices[i].state;
            return;
        }
    }

    printf("Error: device not found\n");
}

void print_devices() {
    printf("Devices:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("  %s: ", devices[i].name);
        switch (devices[i].type) {
            case DEVICE_TYPE_LIGHT:
                printf("light");
                break;
            case DEVICE_TYPE_SENSOR:
                printf("sensor");
                break;
            case DEVICE_TYPE_SWITCH:
                printf("switch");
                break;
        }
        printf(" (state: %s)\n", devices[i].state ? "on" : "off");
    }
}

int main() {
    add_device("Light 1", DEVICE_TYPE_LIGHT, 0);
    add_device("Sensor 1", DEVICE_TYPE_SENSOR, 0);
    add_device("Switch 1", DEVICE_TYPE_SWITCH, 0);

    print_devices();

    toggle_device("Light 1");
    toggle_device("Sensor 1");
    toggle_device("Switch 1");

    print_devices();

    remove_device("Sensor 1");

    print_devices();

    return 0;
}
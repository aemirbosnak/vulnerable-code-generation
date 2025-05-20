//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef enum {
    DEVICE_TYPE_LIGHT,
    DEVICE_TYPE_FAN,
    DEVICE_TYPE_THERMOSTAT
} device_type_t;

typedef struct {
    char *name;
    device_type_t type;
    int state; // 0 for off, 1 for on
} device_t;

device_t devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char *name, device_type_t type) {
    if (num_devices >= MAX_DEVICES) {
        printf("Error: maximum number of devices reached\n");
        return;
    }

    devices[num_devices].name = strdup(name);
    devices[num_devices].type = type;
    devices[num_devices].state = 0;
    num_devices++;
}

void print_devices() {
    printf("Devices:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("  %s (%s, state = %d)\n", devices[i].name,
               devices[i].type == DEVICE_TYPE_LIGHT ? "light" :
               devices[i].type == DEVICE_TYPE_FAN ? "fan" :
               devices[i].type == DEVICE_TYPE_THERMOSTAT ? "thermostat" : "unknown",
               devices[i].state);
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

    printf("Error: device not found\n");
}

int main() {
    add_device("Living Room Light", DEVICE_TYPE_LIGHT);
    add_device("Bedroom Fan", DEVICE_TYPE_FAN);
    add_device("Upstairs Thermostat", DEVICE_TYPE_THERMOSTAT);

    print_devices();

    toggle_device("Living Room Light");
    toggle_device("Bedroom Fan");

    print_devices();

    return 0;
}
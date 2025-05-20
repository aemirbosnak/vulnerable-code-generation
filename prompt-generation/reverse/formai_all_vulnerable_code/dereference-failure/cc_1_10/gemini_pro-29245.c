//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int state;
} device;

device devices[] = {
    {"light", 0},
    {"fan", 0},
    {"tv", 0},
    {"ac", 0}
};

int num_devices = sizeof(devices) / sizeof(device);

void print_usage() {
    printf("Usage: smart_home <command> <device> <state>\n");
    printf("Commands: on, off, toggle\n");
    printf("Devices: light, fan, tv, ac\n");
    printf("States: 0, 1\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    char *command = argv[1];
    char *device_name = argv[2];
    int state = atoi(argv[3]);

    if (strcmp(command, "on") == 0) {
        for (int i = 0; i < num_devices; i++) {
            if (strcmp(devices[i].name, device_name) == 0) {
                devices[i].state = 1;
                printf("%s is now on\n", device_name);
                break;
            }
        }
    } else if (strcmp(command, "off") == 0) {
        for (int i = 0; i < num_devices; i++) {
            if (strcmp(devices[i].name, device_name) == 0) {
                devices[i].state = 0;
                printf("%s is now off\n", device_name);
                break;
            }
        }
    } else if (strcmp(command, "toggle") == 0) {
        for (int i = 0; i < num_devices; i++) {
            if (strcmp(devices[i].name, device_name) == 0) {
                devices[i].state = !devices[i].state;
                printf("%s is now %s\n", device_name, devices[i].state ? "on" : "off");
                break;
            }
        }
    } else {
        print_usage();
        return 1;
    }

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100

typedef struct {
    char name[32];
    int type; // 0 = light, 1 = thermostat, 2 = door
    int state; // 0 = off, 1 = on, 2 = open, 3 = closed
} device;

device devices[MAX_DEVICES];
int num_devices = 0;

void load_devices() {
    FILE *fp = fopen("devices.txt", "r");
    if (fp == NULL) {
        printf("Error opening devices.txt\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *name = strtok(line, ",");
        char *type = strtok(NULL, ",");
        char *state = strtok(NULL, ",");

        device d;
        strcpy(d.name, name);
        d.type = atoi(type);
        d.state = atoi(state);

        devices[num_devices++] = d;
    }

    fclose(fp);
}

void print_devices() {
    for (int i = 0; i < num_devices; i++) {
        printf("%s: ", devices[i].name);
        switch (devices[i].type) {
            case 0:
                printf("light");
                break;
            case 1:
                printf("thermostat");
                break;
            case 2:
                printf("door");
                break;
        }
        printf(" (%s)\n", devices[i].state ? "on" : "off");
    }
}

void control_device(char *name, char *command) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            if (strcmp(command, "on") == 0) {
                devices[i].state = 1;
            } else if (strcmp(command, "off") == 0) {
                devices[i].state = 0;
            } else if (strcmp(command, "open") == 0) {
                devices[i].state = 2;
            } else if (strcmp(command, "close") == 0) {
                devices[i].state = 3;
            }
            break;
        }
    }
}

int main() {
    load_devices();
    print_devices();

    char input[1024];
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        char *command = strtok(input, " ");
        char *name = strtok(NULL, " ");

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "on") == 0 || strcmp(command, "off") == 0 || strcmp(command, "open") == 0 || strcmp(command, "close") == 0) {
            control_device(name, command);
        } else {
            printf("Invalid command\n");
        }

        print_devices();
    }

    return 0;
}
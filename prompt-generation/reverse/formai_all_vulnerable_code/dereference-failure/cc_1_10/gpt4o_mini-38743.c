//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LENGTH 20

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    int status; // 0: off, 1: on
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char* name) {
    if (deviceCount < MAX_DEVICES) {
        strncpy(devices[deviceCount].name, name, DEVICE_NAME_LENGTH);
        devices[deviceCount].status = 0; // Default OFF
        deviceCount++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Device limit reached, cannot add more devices.\n");
    }
}

void toggleDevice(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status; // Toggle status
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void listDevices() {
    printf("List of smart devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf(" - %s: %s\n", devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

void scheduleDevice(const char* name, int hour, int minute) {
    // Simple scheduling logic, just print a message
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            printf("Device '%s' scheduled to turn ON at %02d:%02d.\n", name, hour, minute);
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void currentTime() {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);
    printf("Current time: %02d:%02d:%02d\n", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
}

int main() {
    int choice;
    char name[DEVICE_NAME_LENGTH];
    int hour, minute;

    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. List Devices\n");
        printf("4. Schedule Device\n");
        printf("5. Show Current Time\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name);
                addDevice(name);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                scanf("%s", name);
                toggleDevice(name);
                break;
            case 3:
                listDevices();
                break;
            case 4:
                printf("Enter device name to schedule: ");
                scanf("%s", name);
                printf("Enter hour and minute (HH MM): ");
                scanf("%d %d", &hour, &minute);
                scheduleDevice(name, hour, minute);
                break;
            case 5:
                currentTime();
                break;
            case 6:
                printf("Exiting Smart Home Automation System.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
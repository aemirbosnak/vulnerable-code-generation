//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LENGTH 50

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    int status; // 0: off, 1: on
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int device_count;
} SmartHome;

// Initialize a new smart home
SmartHome* create_smart_home() {
    SmartHome* home = (SmartHome*)malloc(sizeof(SmartHome));
    home->device_count = 0;
    return home;
}

// Add a device to the smart home
void add_device(SmartHome* home, const char* device_name) {
    if (home->device_count < MAX_DEVICES) {
        strcpy(home->devices[home->device_count].name, device_name);
        home->devices[home->device_count].status = 0; // initially off
        home->device_count++;
        printf("Device '%s' added successfully.\n", device_name);
    } else {
        printf("Device limit reached. Cannot add '%s'.\n", device_name);
    }
}

// Toggle the device status
void toggle_device(SmartHome* home, const char* device_name) {
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, device_name) == 0) {
            home->devices[i].status = !home->devices[i].status;
            printf("Device '%s' is now %s.\n", device_name, home->devices[i].status ? "on" : "off");
            return;
        }
    }
    printf("Device '%s' not found.\n", device_name);
}

// Display the status of all devices
void display_device_status(SmartHome* home) {
    printf("\n--- Device Status ---\n");
    for (int i = 0; i < home->device_count; i++) {
        printf("%s: %s\n", home->devices[i].name, home->devices[i].status ? "On" : "Off");
    }
}

void free_smart_home(SmartHome* home) {
    free(home);
}

int main() {
    int choice;
    SmartHome* home = create_smart_home();
    
    while (1) {
        printf("\n--- Smart Home Automation ---\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. Display Device Status\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: {
                char device_name[DEVICE_NAME_LENGTH];
                printf("Enter device name: ");
                fgets(device_name, DEVICE_NAME_LENGTH, stdin);
                device_name[strcspn(device_name, "\n")] = 0; // remove newline
                add_device(home, device_name);
                break;
            }
            case 2: {
                char device_name[DEVICE_NAME_LENGTH];
                printf("Enter device name to toggle: ");
                fgets(device_name, DEVICE_NAME_LENGTH, stdin);
                device_name[strcspn(device_name, "\n")] = 0; // remove newline
                toggle_device(home, device_name);
                break;
            }
            case 3: {
                display_device_status(home);
                break;
            }
            case 4:
                free_smart_home(home);
                printf("Exiting Smart Home Automation. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
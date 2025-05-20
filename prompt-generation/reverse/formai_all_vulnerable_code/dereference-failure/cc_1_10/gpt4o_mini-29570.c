//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Structures to represent devices in the smart home system
typedef struct {
    char name[50];
    int status; // 0: off, 1: on
} Device;

typedef struct {
    Device *devices;
    int device_count;
} SmartHome;

// Function declarations
void init_home(SmartHome *home);
void add_device(SmartHome *home, const char *device_name);
void toggle_device(SmartHome *home, const char *device_name);
void list_devices(SmartHome *home);
void *monitor_devices(void *arg);

int main() {
    SmartHome home;
    init_home(&home);

    // Add smart devices
    add_device(&home, "Living Room Light");
    add_device(&home, "Kitchen Light");
    add_device(&home, "Thermostat");
    add_device(&home, "Smart Speaker");

    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitor_devices, (void *)&home);

    char command[50];

    while (1) {
        printf("\nCommand (toggle <device>|list|exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character
        
        if (strncmp(command, "toggle ", 7) == 0) {
            toggle_device(&home, command + 7);
        } else if (strcmp(command, "list") == 0) {
            list_devices(&home);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command!\n");
        }
    }

    // Clean up
    free(home.devices);
    pthread_cancel(monitor_thread);
    pthread_join(monitor_thread, NULL);
    
    return 0;
}

// Initialize the SmartHome structure
void init_home(SmartHome *home) {
    home->devices = NULL;
    home->device_count = 0;
}

// Add a new device to the SmartHome
void add_device(SmartHome *home, const char *device_name) {
    home->devices = realloc(home->devices, sizeof(Device) * (home->device_count + 1));
    strcpy(home->devices[home->device_count].name, device_name);
    home->devices[home->device_count].status = 0; // Initially turned off
    home->device_count++;
    printf("Added device: %s\n", device_name);
}

// Toggle the status of a device
void toggle_device(SmartHome *home, const char *device_name) {
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, device_name) == 0) {
            home->devices[i].status = !home->devices[i].status;
            printf("%s is now %s\n", device_name, home->devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device not found: %s\n", device_name);
}

// List all devices and their statuses
void list_devices(SmartHome *home) {
    printf("Smart Home Devices:\n");
    for (int i = 0; i < home->device_count; i++) {
        printf(" - %s: %s\n", home->devices[i].name, home->devices[i].status ? "ON" : "OFF");
    }
}

// Monitor device statuses in a separate thread
void *monitor_devices(void *arg) {
    SmartHome *home = (SmartHome *)arg;
    while (1) {
        sleep(5);
        for (int i = 0; i < home->device_count; i++) {
            if (home->devices[i].status == 1) {
                printf("Monitoring: %s is currently ON\n", home->devices[i].name);
            }
        }
    }
}
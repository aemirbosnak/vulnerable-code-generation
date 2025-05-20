//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 50

typedef struct Device {
    char name[MAX_NAME_LENGTH];
    struct Device* connections[MAX_DEVICES];
    int connection_count;
} Device;

Device* devices[MAX_DEVICES];
int device_count = 0;

Device* create_device(const char* name) {
    Device* device = (Device*)malloc(sizeof(Device));
    strncpy(device->name, name, MAX_NAME_LENGTH);
    device->connection_count = 0;
    return device;
}

void add_device(const char* name) {
    if (device_count < MAX_DEVICES) {
        devices[device_count++] = create_device(name);
        printf("Device '%s' added to the network.\n", name);
    } else {
        printf("Error: Maximum device limit reached.\n");
    }
}

void connect_devices(const char* name1, const char* name2) {
    Device* device1 = NULL;
    Device* device2 = NULL;
    
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i]->name, name1) == 0) {
            device1 = devices[i];
        }
        if (strcmp(devices[i]->name, name2) == 0) {
            device2 = devices[i];
        }
    }
    
    if (device1 && device2) {
        device1->connections[device1->connection_count++] = device2;
        device2->connections[device2->connection_count++] = device1;  // bidirectional
        printf("Connected '%s' to '%s'.\n", name1, name2);
    } else {
        printf("Error: One or both devices not found.\n");
    }
}

void display_topology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < device_count; i++) {
        Device* device = devices[i];
        printf("%s is connected to: ", device->name);
        for (int j = 0; j < device->connection_count; j++) {
            printf("%s ", device->connections[j]->name);
        }
        printf("\n");
    }
}

void cleanup() {
    for (int i = 0; i < device_count; i++) {
        free(devices[i]);
    }
}

int main() {
    int choice;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Device\n");
        printf("2. Connect Devices\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name1);
                add_device(name1);
                break;
            case 2:
                printf("Enter first device name: ");
                scanf("%s", name1);
                printf("Enter second device name: ");
                scanf("%s", name2);
                connect_devices(name1, name2);
                break;
            case 3:
                display_topology();
                break;
            case 4:
                cleanup();
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}
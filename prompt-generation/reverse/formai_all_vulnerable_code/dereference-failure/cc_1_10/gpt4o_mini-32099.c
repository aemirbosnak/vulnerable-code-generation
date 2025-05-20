//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a network device
typedef struct Device {
    char name[30];
    struct Device* next; // Pointer to the next device in the linked list
} Device;

// Structure to represent a connection between two devices
typedef struct Connection {
    char device1[30];
    char device2[30];
} Connection;

Device* head = NULL; // Head of the linked list of devices

// Function to add a new device to the topology
void addDevice(const char* deviceName) {
    Device* newDevice = (Device*)malloc(sizeof(Device));
    strcpy(newDevice->name, deviceName);
    newDevice->next = head; // Insert at the beginning
    head = newDevice;
    printf("Device '%s' added to the topology.\n", deviceName);
}

// Function to display all devices in the topology
void displayDevices() {
    Device* current = head;
    if (current == NULL) {
        printf("No devices in the topology.\n");
        return;
    }
    printf("Current devices in the topology:\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

// Function to create a connection between two devices
void createConnection(const char* device1, const char* device2) {
    printf("Connection established between '%s' and '%s'.\n", device1, device2);
}

// Function to release allocated memory for devices
void freeTopology() {
    Device* current = head;
    Device* nextDevice;

    while (current != NULL) {
        nextDevice = current->next;
        free(current);
        current = nextDevice;
    }
    head = NULL; // Reset head to NULL after freeing
}

int main() {
    int choice;
    char deviceName[30];
    char device1[30], device2[30];

    do {
        printf("\n=== Network Topology Mapper ===\n");
        printf("1. Add Device\n");
        printf("2. Display Devices\n");
        printf("3. Create Connection\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                fgets(deviceName, sizeof(deviceName), stdin);
                deviceName[strcspn(deviceName, "\n")] = 0; // Remove newline
                addDevice(deviceName);
                break;
            case 2:
                displayDevices();
                break;
            case 3:
                printf("Enter first device name: ");
                fgets(device1, sizeof(device1), stdin);
                device1[strcspn(device1, "\n")] = 0; // Remove newline
                printf("Enter second device name: ");
                fgets(device2, sizeof(device2), stdin);
                device2[strcspn(device2, "\n")] = 0; // Remove newline
                createConnection(device1, device2);
                break;
            case 4:
                printf("Exiting...\n");
                freeTopology();
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
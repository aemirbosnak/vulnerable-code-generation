//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_DEVICES 50
#define MAX_NAME_LENGTH 20

// Device structure
typedef struct Device {
    char name[MAX_NAME_LENGTH];
    struct Device* next;
    struct Connection* connections;
} Device;

// Connection structure
typedef struct Connection {
    Device* device;
    struct Connection* next;
} Connection;

// Head of the device list
Device* head = NULL;

// Function to create a new device
Device* create_device(const char* name) {
    Device* new_device = (Device*)malloc(sizeof(Device));
    strncpy(new_device->name, name, MAX_NAME_LENGTH);
    new_device->next = NULL;
    new_device->connections = NULL;
    return new_device;
}

// Function to add a device to the list
void add_device(const char* name) {
    Device* new_device = create_device(name);
    if (head == NULL) {
        head = new_device;
    } else {
        Device* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_device;
    }
}

// Function to connect two devices
void connect_devices(const char* name1, const char* name2) {
    Device* device1 = NULL;
    Device* device2 = NULL;

    // Find both devices
    Device* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name1) == 0) {
            device1 = current;
        }
        if (strcmp(current->name, name2) == 0) {
            device2 = current;
        }
        current = current->next;
    }

    if (device1 != NULL && device2 != NULL) {
        // Create connection from device1 to device2
        Connection* conn1 = (Connection*)malloc(sizeof(Connection));
        conn1->device = device2;
        conn1->next = device1->connections;
        device1->connections = conn1;

        // Create connection from device2 to device1
        Connection* conn2 = (Connection*)malloc(sizeof(Connection));
        conn2->device = device1;
        conn2->next = device2->connections;
        device2->connections = conn2;

        printf("Connected %s to %s\n", name1, name2);
    } else {
        printf("One or both devices not found!\n");
    }
}

// Function to print the network topology
void print_topology() {
    Device* current = head;
    while (current != NULL) {
        printf("%s is connected to: ", current->name);
        Connection* conn = current->connections;
        while (conn != NULL) {
            printf("%s ", conn->device->name);
            conn = conn->next;
        }
        printf("\n");
        current = current->next;
    }
}

// Function to free memory
void free_memory() {
    Device* current = head;
    while (current != NULL) {
        Connection* conn = current->connections;
        while (conn != NULL) {
            Connection* temp = conn;
            conn = conn->next;
            free(temp);
        }
        Device* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function
int main() {
    int choice;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    while (1) {
        printf("\nNetwork Topology Mapper:\n");
        printf("1. Add Device\n");
        printf("2. Connect Devices\n");
        printf("3. Print Topology\n");
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
                printf("Enter the first device name: ");
                scanf("%s", name1);
                printf("Enter the second device name: ");
                scanf("%s", name2);
                connect_devices(name1, name2);
                break;
            case 3:
                print_topology();
                break;
            case 4:
                free_memory();
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}
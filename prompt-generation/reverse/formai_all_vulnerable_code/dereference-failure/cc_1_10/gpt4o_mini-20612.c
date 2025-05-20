//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a network device
typedef struct Device {
    char name[50];
    char ip_address[16];
    struct Device *connections[10]; // A device can connect to up to 10 other devices
    int connection_count;
} Device;

// Function prototypes
Device* create_device(const char* name, const char* ip_address);
void add_connection(Device* dev1, Device* dev2);
void display_topology(Device* devices[], int count);
void free_memory(Device* devices[], int count);

int main() {
    // An array to hold devices
    Device* devices[10];
    int device_count = 0;
    
    // Sample input for the topology
    devices[device_count++] = create_device("Router", "192.168.1.1");
    devices[device_count++] = create_device("Switch", "192.168.1.2");
    devices[device_count++] = create_device("Server1", "192.168.1.10");
    devices[device_count++] = create_device("Server2", "192.168.1.11");
    devices[device_count++] = create_device("PC1", "192.168.1.20");
    
    // Adding connections
    add_connection(devices[0], devices[1]); // Router to Switch
    add_connection(devices[1], devices[2]); // Switch to Server1
    add_connection(devices[1], devices[3]); // Switch to Server2
    add_connection(devices[1], devices[4]); // Switch to PC1

    // Display the network topology
    printf("Welcome to the Curious Network Topology Mapper!\n");
    display_topology(devices, device_count);
    
    // Free allocated memory
    free_memory(devices, device_count);
    
    return 0;
}

// Function to create a new device
Device* create_device(const char* name, const char* ip_address) {
    Device* new_device = (Device*)malloc(sizeof(Device));
    strncpy(new_device->name, name, sizeof(new_device->name) - 1);
    strncpy(new_device->ip_address, ip_address, sizeof(new_device->ip_address) - 1);
    new_device->connection_count = 0;
    return new_device;
}

// Function to add connection between two devices
void add_connection(Device* dev1, Device* dev2) {
    if (dev1->connection_count < 10) {
        dev1->connections[dev1->connection_count++] = dev2;
    }
    if (dev2->connection_count < 10) {
        dev2->connections[dev2->connection_count++] = dev1;
    }
}

// Function to display the entire topology
void display_topology(Device* devices[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Device: %s (IP: %s)\n", devices[i]->name, devices[i]->ip_address);
        printf("  Connected to: ");
        for (int j = 0; j < devices[i]->connection_count; j++) {
            printf("%s (IP: %s)", devices[i]->connections[j]->name, devices[i]->connections[j]->ip_address);
            if (j < devices[i]->connection_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Function to free allocated memory for devices
void free_memory(Device* devices[], int count) {
    for (int i = 0; i < count; i++) {
        free(devices[i]);
    }
}
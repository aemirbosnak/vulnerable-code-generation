//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50
#define MAX_NAME_LENGTH 20

// Structure representing a device in the network
typedef struct Device {
    char name[MAX_NAME_LENGTH];
    int num_connections;
    struct Device* connections[MAX_DEVICES];
} Device;

// Structure representing the network topology
typedef struct Network {
    Device* devices[MAX_DEVICES];
    int num_devices;
} Network;

// Function to create a new device
Device* create_device(const char* name) {
    Device* new_device = (Device*)malloc(sizeof(Device));
    strncpy(new_device->name, name, MAX_NAME_LENGTH);
    new_device->num_connections = 0;
    return new_device;
}

// Function to create a new network
Network* create_network() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->num_devices = 0;
    return network;
}

// Function to add a device to the network
void add_device(Network* network, const char* name) {
    if (network->num_devices < MAX_DEVICES) {
        Device* device = create_device(name);
        network->devices[network->num_devices++] = device;
        printf("Device %s added to the network.\n", name);
    } else {
        printf("Network is full. Cannot add device %s.\n", name);
    }
}

// Function to connect two devices
void connect_devices(Network* network, const char* device1_name, const char* device2_name) {
    Device* device1 = NULL;
    Device* device2 = NULL;

    // Find the devices in the network
    for (int i = 0; i < network->num_devices; i++) {
        if (strcmp(network->devices[i]->name, device1_name) == 0) {
            device1 = network->devices[i];
        }
        if (strcmp(network->devices[i]->name, device2_name) == 0) {
            device2 = network->devices[i];
        }
    }

    // If both devices are found, connect them
    if (device1 && device2) {
        device1->connections[device1->num_connections++] = device2;
        device2->connections[device2->num_connections++] = device1; // Undirected connection
        printf("Connected %s to %s.\n", device1_name, device2_name);
    } else {
        printf("One or both devices not found in the network.\n");
    }
}

// Function to display the network topology
void display_network(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->num_devices; i++) {
        Device* device = network->devices[i];
        printf("%s:", device->name);
        for (int j = 0; j < device->num_connections; j++) {
            printf(" %s", device->connections[j]->name);
        }
        printf("\n");
    }
}

// Main function
int main() {
    Network* network = create_network();

    // Adding devices
    add_device(network, "Router");
    add_device(network, "Switch");
    add_device(network, "PC1");
    add_device(network, "PC2");
    add_device(network, "Server");

    // Establishing connections
    connect_devices(network, "Router", "Switch");
    connect_devices(network, "Switch", "PC1");
    connect_devices(network, "Switch", "PC2");
    connect_devices(network, "Switch", "Server");

    // Displaying network topology
    display_network(network);

    // Freeing allocated memory (not shown here for clarity)
    // ...

    return 0;
}
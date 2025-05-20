//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

// Custom data structure to represent a device in the network
typedef struct device {
    char name[256];
    char ip_address[256];
    int port;
    struct device *next;
} device;

// Custom data structure to represent the network topology
typedef struct network_topology {
    device *devices;
    int num_devices;
} network_topology;

// Function to create a new device
device *create_device(char *name, char *ip_address, int port) {
    device *new_device = malloc(sizeof(device));
    strcpy(new_device->name, name);
    strcpy(new_device->ip_address, ip_address);
    new_device->port = port;
    new_device->next = NULL;
    return new_device;
}

// Function to add a device to the network topology
void add_device(network_topology *network, device *new_device) {
    if (network->devices == NULL) {
        network->devices = new_device;
    } else {
        device *current_device = network->devices;
        while (current_device->next != NULL) {
            current_device = current_device->next;
        }
        current_device->next = new_device;
    }
    network->num_devices++;
}

// Function to print the network topology
void print_network_topology(network_topology *network) {
    printf("Network Topology:\n");
    printf("----------------\n");
    device *current_device = network->devices;
    while (current_device != NULL) {
        printf("Device Name: %s\n", current_device->name);
        printf("IP Address: %s\n", current_device->ip_address);
        printf("Port: %d\n", current_device->port);
        printf("\n");
        current_device = current_device->next;
    }
}

// Main function
int main() {
    // Create a new network topology
    network_topology *network = malloc(sizeof(network_topology));
    network->devices = NULL;
    network->num_devices = 0;

    // Add devices to the network topology
    device *device1 = create_device("Device 1", "192.168.1.100", 80);
    add_device(network, device1);

    device *device2 = create_device("Device 2", "192.168.1.101", 80);
    add_device(network, device2);

    device *device3 = create_device("Device 3", "192.168.1.102", 80);
    add_device(network, device3);

    // Print the network topology
    print_network_topology(network);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// A structure to represent a device
typedef struct device {
    char *ip_address;
    int port;
    char *vendor;
    char *model;
    struct device *next;
} device;

// A function to create a new device
device *create_device(char *ip_address, int port, char *vendor, char *model) {
    device *new_device = (device *)malloc(sizeof(device));
    new_device->ip_address = strdup(ip_address);
    new_device->port = port;
    new_device->vendor = strdup(vendor);
    new_device->model = strdup(model);
    new_device->next = NULL;
    return new_device;
}

// A function to add a device to the network topology
void add_device(device **network_topology, device *new_device) {
    if (*network_topology == NULL) {
        *network_topology = new_device;
    } else {
        device *current_device = *network_topology;
        while (current_device->next != NULL) {
            current_device = current_device->next;
        }
        current_device->next = new_device;
    }
}

// A function to print the network topology
void print_network_topology(device *network_topology) {
    device *current_device = network_topology;
    while (current_device != NULL) {
        printf("IP Address: %s\n", current_device->ip_address);
        printf("Port: %d\n", current_device->port);
        printf("Vendor: %s\n", current_device->vendor);
        printf("Model: %s\n\n", current_device->model);
        current_device = current_device->next;
    }
}

// A function to free the memory allocated for the network topology
void free_network_topology(device *network_topology) {
    device *current_device = network_topology;
    while (current_device != NULL) {
        device *next_device = current_device->next;
        free(current_device->ip_address);
        free(current_device->vendor);
        free(current_device->model);
        free(current_device);
        current_device = next_device;
    }
}

int main() {
    // Create a new network topology
    device *network_topology = NULL;

    // Add some devices to the network topology
    add_device(&network_topology, create_device("192.168.1.1", 5555, "Cisco", "3560"));
    add_device(&network_topology, create_device("192.168.1.2", 22, "Linux", "Desktop"));
    add_device(&network_topology, create_device("192.168.1.3", 5555, "Ubiquiti", "Unifi"));

    // Print the network topology
    print_network_topology(network_topology);

    // Free the memory allocated for the network topology
    free_network_topology(network_topology);

    return 0;
}
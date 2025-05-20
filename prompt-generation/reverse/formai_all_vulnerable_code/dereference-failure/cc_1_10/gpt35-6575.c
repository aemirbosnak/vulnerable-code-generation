//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a network device
typedef struct Device {
    char* name;
    int num_connections;
    struct Device** connections;
} Device;

// Define a function to create a new network device
Device* createDevice(char* name, int num_connections) {
    Device* device = malloc(sizeof(Device));
    device->name = strdup(name);
    device->num_connections = num_connections;
    device->connections = malloc(num_connections * sizeof(Device*));
    return device;
}

// Define a function to connect two network devices
void connectDevices(Device* device1, Device* device2) {
    device1->connections[device1->num_connections++] = device2;
    device2->connections[device2->num_connections++] = device1;
}

// Define a function to recursively print the network topology
void printTopology(Device* device, int level, Device* parent) {
    int i;
    
    // Print the device name with an indent based on the level
    for (i = 0; i < level; i++) {
        printf("    ");
    }
    
    // Print the device name with an indication of whether it is a parent or child device
    printf("%s", device->name);
    if (parent != NULL) {
        printf(" (connected to %s)", parent->name);
    }
    printf("\n");
    
    // Print the topology for each connected device
    for (i = 0; i < device->num_connections; i++) {
        if (device->connections[i] != parent) {
            printTopology(device->connections[i], level + 1, device);
        }
    }
}

int main() {
    // Create some sample network devices
    Device* hub = createDevice("Hub", 5);
    Device* router = createDevice("Router", 3);
    Device* pc1 = createDevice("PC1", 1);
    Device* pc2 = createDevice("PC2", 1);
    Device* printer = createDevice("Printer", 2);
    
    // Connect the network devices in the topology
    connectDevices(hub, router);
    connectDevices(hub, pc1);
    connectDevices(hub, pc2);
    connectDevices(router, printer);
    connectDevices(router, pc2);
    
    // Print the network topology
    printf("Network Topology:\n");
    printTopology(hub, 0, NULL);
    
    // Free the memory used by the network devices
    free(hub->connections);
    free(hub->name);
    free(router->connections);
    free(router->name);
    free(pc1->connections);
    free(pc1->name);
    free(pc2->connections);
    free(pc2->name);
    free(printer->connections);
    free(printer->name);
    free(hub);
    free(router);
    free(pc1);
    free(pc2);
    free(printer);
    
    return 0;
}
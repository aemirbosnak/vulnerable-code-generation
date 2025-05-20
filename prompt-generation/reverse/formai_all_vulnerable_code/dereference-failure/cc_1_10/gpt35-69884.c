//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define struct for network devices
typedef struct Device {
    char* name;
    int id;
    struct Device* neighbours[10]; // Each device can have up to 10 neighbours
} Device;

// Define struct for network topology
typedef struct Topology {
    Device** devices;
    int numDevices;
} Topology;

// Function to create a new device
Device* createDevice(char* name, int id) {
    Device* device = (Device*) malloc(sizeof(Device));
    device->name = name;
    device->id = id;
    return device;
}

// Function to add a new device to the topology
void addDevice(Topology* topology, Device* device) {
    topology->devices = (Device**) realloc(topology->devices, (topology->numDevices + 1) * sizeof(Device*));
    topology->devices[topology->numDevices] = device;
    topology->numDevices++;
}

// Function to find a device by its ID
Device* findDevice(Topology* topology, int id) {
    for (int i = 0; i < topology->numDevices; i++) {
        if (topology->devices[i]->id == id) {
            return topology->devices[i];
        }
    }
    return NULL;
}

// Function to add a neighbour to a device
void addNeighbour(Device* device, Device* neighbour) {
    for (int i = 0; i < 10; i++) {
        if (device->neighbours[i] == NULL) {
            device->neighbours[i] = neighbour;
            break;
        }
    }
}

// Function to print the topology
void printTopology(Topology* topology) {
    printf("Network Topology:\n");
    for (int i = 0; i < topology->numDevices; i++) {
        Device* device = topology->devices[i];
        printf("Device %d (%s) is connected to: ", device->id, device->name);
        for (int j = 0; j < 10; j++) {
            if (device->neighbours[j] != NULL) {
                printf("%d ", device->neighbours[j]->id);
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a new topology
    Topology* topology = (Topology*) malloc(sizeof(Topology));
    topology->devices = NULL;
    topology->numDevices = 0;

    // Create some devices
    Device* device1 = createDevice("Router", 1);
    Device* device2 = createDevice("Switch", 2);
    Device* device3 = createDevice("Firewall", 3);
    Device* device4 = createDevice("Server", 4);

    // Add the devices to the topology
    addDevice(topology, device1);
    addDevice(topology, device2);
    addDevice(topology, device3);
    addDevice(topology, device4);

    // Connect the devices
    addNeighbour(device1, device2);
    addNeighbour(device1, device3);
    addNeighbour(device2, device1);
    addNeighbour(device2, device4);
    addNeighbour(device3, device1);
    addNeighbour(device4, device2);

    // Print the topology
    printTopology(topology);

    // Clean up
    free(topology->devices);
    free(topology);

    return 0;
}
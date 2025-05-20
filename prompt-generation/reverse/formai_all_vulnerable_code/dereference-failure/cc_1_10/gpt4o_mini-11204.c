//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 50

typedef struct Device {
    char name[NAME_LENGTH];
    struct Device* connections[MAX_DEVICES];
    int connectionCount;
} Device;

Device* createDevice(const char* name) {
    Device* dev = (Device*)malloc(sizeof(Device));
    if (dev) {
        strncpy(dev->name, name, NAME_LENGTH);
        dev->connectionCount = 0;
        for (int i = 0; i < MAX_DEVICES; i++)
            dev->connections[i] = NULL;
    }
    return dev;
}

void connectDevices(Device* dev1, Device* dev2) {
    if (dev1->connectionCount < MAX_DEVICES && dev2->connectionCount < MAX_DEVICES) {
        dev1->connections[dev1->connectionCount++] = dev2;
        dev2->connections[dev2->connectionCount++] = dev1; // bidirectional
    }
}

void printNetwork(Device* device, int visited[], int *counter) {
    if (visited[device->name[0]]) return; // Simplistic visited check using ASCII value
    visited[device->name[0]] = 1;
    
    printf("Device %d: %s\n", (*counter)++, device->name);
    
    for (int i = 0; i < device->connectionCount; i++) {
        printNetwork(device->connections[i], visited, counter);
    }
}

void freeNetwork(Device* device) {
    if (device) {
        for (int i = 0; i < device->connectionCount; i++) {
            freeNetwork(device->connections[i]);
        }
        free(device);
    }
}

int main() {
    Device* devices[MAX_DEVICES];

    devices[0] = createDevice("Router");
    devices[1] = createDevice("Switch 1");
    devices[2] = createDevice("Switch 2");
    devices[3] = createDevice("PC 1");
    devices[4] = createDevice("PC 2");
    devices[5] = createDevice("Server 1");
    
    connectDevices(devices[0], devices[1]);
    connectDevices(devices[0], devices[2]);
    connectDevices(devices[1], devices[3]);
    connectDevices(devices[1], devices[4]);
    connectDevices(devices[2], devices[5]);

    printf("Network Topology:\n");
    int visited[128] = {0}; // For simplicity, ASCII range check
    int counter = 0;
    for (int i = 0; i < 6; i++) {
        if (devices[i]) {
            printNetwork(devices[i], visited, &counter);
        }
    }

    for (int i = 0; i < 6; i++) {
        freeNetwork(devices[i]);
    }

    return 0;
}
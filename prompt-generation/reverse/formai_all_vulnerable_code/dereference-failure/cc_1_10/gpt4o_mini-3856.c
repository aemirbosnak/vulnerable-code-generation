//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LEN 30

typedef struct Device {
    char name[MAX_NAME_LEN];
    struct Device* next;
} Device;

typedef struct Network {
    Device* devices[MAX_DEVICES];
    int deviceCount;
} Network;

Network* createNetwork() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->deviceCount = 0;
    for (int i = 0; i < MAX_DEVICES; i++) {
        network->devices[i] = NULL;
    }
    return network;
}

void addDevice(Network* network, const char* name) {
    if (network->deviceCount < MAX_DEVICES) {
        Device* newDevice = (Device*)malloc(sizeof(Device));
        strncpy(newDevice->name, name, MAX_NAME_LEN - 1);
        newDevice->name[MAX_NAME_LEN - 1] = '\0';
        newDevice->next = NULL;

        network->devices[network->deviceCount] = newDevice;
        network->deviceCount++;
        printf("🎉 Device %s added to the network! 🎉\n", name);
    } else {
        printf("🚫 Can't add more devices! Max limit reached. 🚫\n");
    }
}

void addConnection(Network* network, const char* name1, const char* name2) {
    Device* device1 = NULL;
    Device* device2 = NULL;

    for (int i = 0; i < network->deviceCount; i++) {
        if (strcmp(network->devices[i]->name, name1) == 0) {
            device1 = network->devices[i];
        }
        if (strcmp(network->devices[i]->name, name2) == 0) {
            device2 = network->devices[i];
        }
    }

    if (device1 && device2) {
        device1->next = device2;
        printf("🔗 Connection added between %s and %s! 🔗\n", name1, name2);
    } else {
        printf("😞 One of the devices was not found! Cannot add connection. 😞\n");
    }
}

void printNetwork(Network* network) {
    printf("🌈 Current Network Topology 🌈\n");
    for (int i = 0; i < network->deviceCount; i++) {
        Device* device = network->devices[i];
        printf("Device: %s", device->name);
        if (device->next) {
            printf(" -> Connected to: %s", device->next->name);
        }
        printf("\n");
    }
}

void freeNetwork(Network* network) {
    for (int i = 0; i < network->deviceCount; i++) {
        free(network->devices[i]);
    }
    free(network);
    printf("🎈 Memory freed. Goodbye, Network! 🎈\n");
}

int main() {
    Network* network = createNetwork();

    addDevice(network, "Router");
    addDevice(network, "PC_A");
    addDevice(network, "PC_B");
    addDevice(network, "Printer");
    
    addConnection(network, "Router", "PC_A");
    addConnection(network, "Router", "PC_B");
    addConnection(network, "PC_A", "Printer");

    printNetwork(network);

    freeNetwork(network);
    return 0;
}
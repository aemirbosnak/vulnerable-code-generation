//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 50

typedef struct Device {
    char name[MAX_NAME_LENGTH];
    struct Device* connections[MAX_DEVICES];
    int connectionCount;
} Device;

typedef struct Network {
    Device* devices[MAX_DEVICES];
    int deviceCount;
} Network;

Network* createNetwork();
Device* createDevice(const char* name);
void connectDevices(Device* device1, Device* device2);
void addDevice(Network* network, const char* name);
void displayTopology(Network* network);
void freeNetwork(Network* network);

int main() {
    Network* network = createNetwork();
    char input[100];
    char device1[MAX_NAME_LENGTH], device2[MAX_NAME_LENGTH];

    while (1) {
        printf("1. Add Device\n2. Connect Devices\n3. Display Topology\n4. Exit\n");
        printf("Choose an option: ");
        fgets(input, sizeof(input), stdin);
        int choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                fgets(device1, sizeof(device1), stdin);
                device1[strcspn(device1, "\n")] = 0; // Remove newline character
                addDevice(network, device1);
                break;
            case 2:
                printf("Enter the name of the first device: ");
                fgets(device1, sizeof(device1), stdin);
                device1[strcspn(device1, "\n")] = 0; // Remove newline character

                printf("Enter the name of the second device: ");
                fgets(device2, sizeof(device2), stdin);
                device2[strcspn(device2, "\n")] = 0; // Remove newline character

                Device* dev1 = NULL;
                Device* dev2 = NULL;

                for (int i = 0; i < network->deviceCount; i++) {
                    if (strcmp(network->devices[i]->name, device1) == 0) {
                        dev1 = network->devices[i];
                    }
                    if (strcmp(network->devices[i]->name, device2) == 0) {
                        dev2 = network->devices[i];
                    }
                }

                if (dev1 && dev2) {
                    connectDevices(dev1, dev2);
                    printf("%s connected to %s\n", dev1->name, dev2->name);
                } else {
                    printf("One or both devices not found!\n");
                }
                break;
            case 3:
                displayTopology(network);
                break;
            case 4:
                freeNetwork(network);
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

Network* createNetwork() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->deviceCount = 0;
    return network;
}

Device* createDevice(const char* name) {
    Device* device = (Device*)malloc(sizeof(Device));
    strncpy(device->name, name, MAX_NAME_LENGTH);
    device->connectionCount = 0;
    return device;
}

void connectDevices(Device* device1, Device* device2) {
    device1->connections[device1->connectionCount++] = device2;
    device2->connections[device2->connectionCount++] = device1; // Bi-directional connection
}

void addDevice(Network* network, const char* name) {
    if (network->deviceCount < MAX_DEVICES) {
        Device* newDevice = createDevice(name);
        network->devices[network->deviceCount++] = newDevice;
        printf("Device \"%s\" added to the network.\n", name);
    } else {
        printf("Maximum device limit reached! Cannot add more devices.\n");
    }
}

void displayTopology(Network* network) {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < network->deviceCount; i++) {
        Device* device = network->devices[i];
        printf("Device: %s is connected to: ", device->name);
        for (int j = 0; j < device->connectionCount; j++) {
            printf("%s", device->connections[j]->name);
            if (j < device->connectionCount - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

void freeNetwork(Network* network) {
    for (int i = 0; i < network->deviceCount; i++) {
        free(network->devices[i]);
    }
    free(network);
}
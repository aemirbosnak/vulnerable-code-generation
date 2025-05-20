//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct device {
    char name[20];
    char ip[15];
    bool connected;
};

void initializeDevices(struct device *devices, int numDevices) {
    for(int i = 0; i < numDevices; i++) {
        sprintf(devices[i].name, "Device %d", i+1);
        sprintf(devices[i].ip, "192.168.0.%d", i+1);
        devices[i].connected = false;
    }
}

void printDevices(struct device *devices, int numDevices) {
    printf("======= CONNECTED DEVICES =======\n");
    for(int i = 0; i < numDevices; i++) {
        if(devices[i].connected) {
            printf("%s - %s\n", devices[i].name, devices[i].ip);
        }
    }
    printf("=================================\n");
}

int main() {
    int numDevices = 10;
    struct device *devices = malloc(numDevices * sizeof(struct device));
    initializeDevices(devices, numDevices);

    // Simulated device connections
    for(int i = 0; i < numDevices; i++) {
        if(rand() % 2 == 0) {
            devices[i].connected = true;
        }
    }

    // Print out initial connected devices
    printDevices(devices, numDevices);

    // Simulate new devices connecting
    int numNewDevices = rand() % 4;
    for(int i = 0; i < numNewDevices; i++) {
        int index = rand() % numDevices;
        if(devices[index].connected) { // Device already connected, skip
            continue;
        }
        devices[index].connected = true;
        printf("New device connected: %s - %s\n", devices[index].name, devices[index].ip);
    }

    // Print out final connected devices
    printDevices(devices, numDevices);

    free(devices);
    return 0;
}
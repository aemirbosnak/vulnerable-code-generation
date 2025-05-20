//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DEVICES 10
#define MAX_CONNECTIONS 30
#define MAX_NAME_LENGTH 20

// Define a device structure
typedef struct device {
    char name[MAX_NAME_LENGTH];
    char ip_address[16];
    int num_connections;
    struct device *connections[MAX_DEVICES];
} Device;

// Initialize the device array and connection array
Device *devices[MAX_DEVICES];
int connections[MAX_CONNECTIONS][2];
int num_devices = 0;
int num_connections = 0;

// Function to add a device to the network
void add_device(char name[MAX_NAME_LENGTH], char ip_address[16]) {
    Device *new_device = (Device *) malloc(sizeof(Device));
    strcpy(new_device->name, name);
    strcpy(new_device->ip_address, ip_address);
    new_device->num_connections = 0;
    devices[num_devices] = new_device;
    num_devices++;
}

// Function to add a connection between two devices
void add_connection(int dev1, int dev2) {
    connections[num_connections][0] = dev1;
    connections[num_connections][1] = dev2;
    devices[dev1]->connections[devices[dev1]->num_connections] = devices[dev2];
    devices[dev1]->num_connections++;
    devices[dev2]->connections[devices[dev2]->num_connections] = devices[dev1];
    devices[dev2]->num_connections++;
    num_connections++;
}

int main() {
    add_device("Router", "192.168.1.1");
    add_device("PC", "192.168.1.2");
    add_device("Printer", "192.168.1.3");
    add_connection(0, 1);
    add_connection(0, 2);
    printf("Network Topology:\n");
    printf("------------------\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s) is connected to:\n", devices[i]->name, devices[i]->ip_address);
        for (int j = 0; j < devices[i]->num_connections; j++) {
            printf("- %s (%s)\n", devices[i]->connections[j]->name, devices[i]->connections[j]->ip_address);
        }
        printf("\n");
    }
    return 0;
}
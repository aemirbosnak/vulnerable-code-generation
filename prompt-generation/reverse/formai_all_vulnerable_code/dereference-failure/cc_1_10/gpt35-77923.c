//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 100

typedef struct Device {
    int id;
    char name[100];
    struct Connection *connections[MAX_CONNECTIONS];
    int num_connections;
} Device;

typedef struct Connection {
    struct Device *device;
    double bandwidth;
} Connection;

void add_device(Device *devices[], int *num_devices, char *name) {
    Device *device = (Device*) malloc(sizeof(Device));
    device->id = *num_devices;
    strcpy(device->name, name);
    device->num_connections = 0;
    devices[*num_devices] = device;
    *num_devices += 1;
}

void add_connection(Device *device, Device *connected_device, double bandwidth) {
    Connection *connection = (Connection*) malloc(sizeof(Connection));
    connection->device = connected_device;
    connection->bandwidth = bandwidth;
    device->connections[device->num_connections] = connection;
    device->num_connections += 1;
}

void print_topology(Device *devices[], int num_devices) {
    for (int i = 0; i < num_devices; i++) {
        Device *device = devices[i];
        printf("Device %d: %s\n", device->id, device->name);
        for (int j = 0; j < device->num_connections; j++) {
            Connection *connection = device->connections[j];
            printf("\tConnected to %s with bandwidth %f\n", connection->device->name, connection->bandwidth);
        }
    }
}

int main() {
    Device *devices[MAX_DEVICES];
    int num_devices = 0;

    // Add devices to the network
    add_device(devices, &num_devices, "Router A");
    add_device(devices, &num_devices, "Switch B");
    add_device(devices, &num_devices, "Server C");
    add_device(devices, &num_devices, "Firewall D");

    // Add connections between devices
    add_connection(devices[0], devices[1], 100.0);
    add_connection(devices[1], devices[0], 100.0);
    add_connection(devices[1], devices[2], 1000.0);
    add_connection(devices[2], devices[1], 1000.0);
    add_connection(devices[1], devices[3], 500.0);
    add_connection(devices[3], devices[1], 500.0);

    // Print the network topology
    print_topology(devices, num_devices);

    return 0;
}
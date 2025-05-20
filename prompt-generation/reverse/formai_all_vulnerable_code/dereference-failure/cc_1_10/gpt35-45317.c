//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 100

int device_count = 0;
int connection_count = 0;

typedef struct {
    char* name;
    char* ip;
    char* subnet_mask;
} device_t;

typedef struct {
    device_t* device1;
    device_t* device2;
} connection_t;

device_t* devices[MAX_DEVICES];
connection_t* connections[MAX_CONNECTIONS];

bool add_device(char* name, char* ip, char* subnet_mask) {
    if (device_count >= MAX_DEVICES) {
        return false;
    }

    device_t* device = (device_t*)malloc(sizeof(device_t));
    device->name = name;
    device->ip = ip;
    device->subnet_mask = subnet_mask;

    devices[device_count] = device;
    device_count++;

    return true;
}

bool add_connection(device_t* device1, device_t* device2) {
    if (connection_count >= MAX_CONNECTIONS) {
        return false;
    }

    connection_t* connection = (connection_t*)malloc(sizeof(connection_t));
    connection->device1 = device1;
    connection->device2 = device2;

    connections[connection_count] = connection;
    connection_count++;

    return true;
}

void print_devices() {
    printf("Devices:\n");

    for (int i = 0; i < device_count; i++) {
        device_t* device = devices[i];
        printf("%s - %s (%s)\n", device->name, device->ip, device->subnet_mask);
    }

    printf("\n");
}

void print_connections() {
    printf("Connections:\n");

    for (int i = 0; i < connection_count; i++) {
        connection_t* connection = connections[i];
        printf("%s (%s) -> %s (%s)\n", connection->device1->name, connection->device1->ip, connection->device2->name, connection->device2->ip);
    }

    printf("\n");
}

int main() {
    add_device("Router A", "192.168.0.1", "255.255.255.0");
    add_device("PC 1", "192.168.0.100", "255.255.255.0");
    add_device("PC 2", "192.168.0.101", "255.255.255.0");
    add_device("Server 1", "192.168.0.200", "255.255.255.0");
    add_device("Switch 1", "192.168.0.254", "255.255.255.0");

    add_connection(devices[0], devices[1]);
    add_connection(devices[0], devices[2]);
    add_connection(devices[0], devices[4]);
    add_connection(devices[3], devices[4]);

    print_devices();
    print_connections();

    return 0;
}
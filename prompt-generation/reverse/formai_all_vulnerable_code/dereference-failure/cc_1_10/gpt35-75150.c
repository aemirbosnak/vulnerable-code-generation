//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 50
#define MAX_CONNECTIONS 100

typedef struct {
    char *name;
    char *ip;
    bool connected;
} Device;

typedef struct {
    int from;
    int to;
} Connection;

Device devices[MAX_DEVICES];
Connection connections[MAX_CONNECTIONS];
int numDevices = 0;
int numConnections = 0;

void addDevice(char *name, char *ip) {
    if (numDevices >= MAX_DEVICES) {
        printf("Maximum number of devices reached!\n");
        return;
    }
    Device d;
    d.name = malloc(strlen(name) + 1);
    d.ip = malloc(strlen(ip) + 1);
    strcpy(d.name, name);
    strcpy(d.ip, ip);
    d.connected = false;
    devices[numDevices++] = d;
    printf("Added device: %s (%s)\n", name, ip);
}

void addConnection(int from, int to) {
    if (numConnections >= MAX_CONNECTIONS) {
        printf("Maximum number of connections reached!\n");
        return;
    }
    connections[numConnections++] = (Connection) {from, to};
    devices[from].connected = true;
    devices[to].connected = true;
    printf("Added connection: %s (%s) to %s (%s)\n", devices[from].name, devices[from].ip, devices[to].name, devices[to].ip);
}

void printDevices() {
    printf("Devices:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("%s (%s) %s\n", devices[i].name, devices[i].ip, devices[i].connected ? "CONNECTED" : "DISCONNECTED");
    }
}

void printConnections() {
    printf("Connections:\n");
    for (int i = 0; i < numConnections; i++) {
        printf("%s (%s) to %s (%s)\n", devices[connections[i].from].name, devices[connections[i].from].ip, devices[connections[i].to].name, devices[connections[i].to].ip);
    }
}

int main() {
    addDevice("Router", "192.168.1.1");
    addDevice("Switch", "192.168.1.2");
    addDevice("Computer", "192.168.1.3");
    addDevice("Printer", "192.168.1.4");
    addDevice("Server", "192.168.1.5");

    addConnection(0, 1);
    addConnection(1, 2);
    addConnection(1, 3);
    addConnection(2, 4);
    addConnection(3, 4);

    printDevices();
    printConnections();

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_CONNECTIONS 5
#define NAME_LEN 20

typedef struct Device {
    char name[NAME_LEN];
    int connection_count;
    struct Device *connections[MAX_CONNECTIONS];
} Device;

typedef struct NetworkTopology {
    Device *devices[MAX_DEVICES];
    int device_count;
} NetworkTopology;

void initialize_network(NetworkTopology *network) {
    network->device_count = 0;
    printf("Network Topology Initialized!\n");
}

Device* create_device(const char *name) {
    Device *new_device = (Device *)malloc(sizeof(Device));
    strncpy(new_device->name, name, NAME_LEN);
    new_device->connection_count = 0;
    printf("Device '%s' created!\n", new_device->name);
    return new_device;
}

void add_device(NetworkTopology *network, Device *device) {
    if (network->device_count < MAX_DEVICES) {
        network->devices[network->device_count++] = device;
        printf("Device '%s' added to the network!\n", device->name);
    } else {
        printf("Network is full! Can't add device '%s'.\n", device->name);
    }
}

void connect_devices(Device *dev1, Device *dev2) {
    if (dev1->connection_count < MAX_CONNECTIONS && dev2->connection_count < MAX_CONNECTIONS) {
        dev1->connections[dev1->connection_count++] = dev2;
        dev2->connections[dev2->connection_count++] = dev1; // bi-directional connection
        printf("Devices '%s' and '%s' are now connected!\n", dev1->name, dev2->name);
    } else {
        printf("Connection failed! One of the devices is at maximum connections.\n");
    }
}

void display_topology(NetworkTopology *network) {
    printf("\nCurrent Network Topology:\n");
    for (int i = 0; i < network->device_count; i++) {
        Device *device = network->devices[i];
        printf("Device: %s\n", device->name);
        printf("Connections: ");
        for (int j = 0; j < device->connection_count; j++) {
            printf("%s ", device->connections[j]->name);
        }
        printf("\n");
    }
}

void cleanup(NetworkTopology *network) {
    for (int i = 0; i < network->device_count; i++) {
        free(network->devices[i]);
    }
    printf("All devices cleaned up!\n");
}

int main() {
    NetworkTopology network;
    initialize_network(&network);

    Device *router = create_device("Router");
    Device *switch1 = create_device("Switch1");
    Device *switch2 = create_device("Switch2");
    Device *server = create_device("Server");

    add_device(&network, router);
    add_device(&network, switch1);
    add_device(&network, switch2);
    add_device(&network, server);

    connect_devices(router, switch1);
    connect_devices(switch1, switch2);
    connect_devices(switch2, server);
    connect_devices(router, server); // Let's connect router directly to server too!

    display_topology(&network);
    cleanup(&network);

    return 0;
}
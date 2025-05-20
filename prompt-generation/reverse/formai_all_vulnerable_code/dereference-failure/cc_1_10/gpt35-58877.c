//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struct to hold information about a device
struct Device {
    char* name;
    char* ip;
    int num_connections;
    struct Device** connections; // Array of pointers to connected devices
};

// Function to create a new device with a given name and IP
struct Device* create_device(char* name, char* ip) {
    struct Device* d = malloc(sizeof(struct Device));
    d->name = malloc(strlen(name) + 1);
    strcpy(d->name, name);
    d->ip = malloc(strlen(ip) + 1);
    strcpy(d->ip, ip);
    d->num_connections = 0;
    d->connections = malloc(sizeof(struct Device*) * MAX_SIZE);
    return d;
}

// Function to add a connection between two devices
void add_connection(struct Device* d1, struct Device* d2) {
    d1->connections[d1->num_connections++] = d2;
    d2->connections[d2->num_connections++] = d1;
}

// Function to print out information about a device and its connections
void print_device(struct Device* d) {
    printf("Device Name: %s\n", d->name);
    printf("IP Address: %s\n", d->ip);
    printf("Connections (%d):\n", d->num_connections);
    for (int i = 0; i < d->num_connections; i++) {
        printf("\t%s (%s)\n", d->connections[i]->name, d->connections[i]->ip);
    }
    printf("\n");
}

int main() {
    // Create devices and add connections
    struct Device* router = create_device("Router", "192.168.1.1");
    struct Device* switch1 = create_device("Switch 1", "192.168.1.2");
    struct Device* switch2 = create_device("Switch 2", "192.168.1.3");
    struct Device* pc1 = create_device("PC 1", "192.168.1.4");
    struct Device* pc2 = create_device("PC 2", "192.168.1.5");
    add_connection(router, switch1);
    add_connection(router, switch2);
    add_connection(switch1, pc1);
    add_connection(switch2, pc2);
    add_connection(switch2, pc1); // Switches connected through PC 1

    // Print out device information
    printf("Network Topology Map:\n\n");
    print_device(router);
    print_device(switch1);
    print_device(switch2);
    print_device(pc1);
    print_device(pc2);

    // Free memory
    free(router->name);
    free(router->ip);
    free(router->connections);
    free(router);
    free(switch1->name);
    free(switch1->ip);
    free(switch1->connections);
    free(switch1);
    free(switch2->name);
    free(switch2->ip);
    free(switch2->connections);
    free(switch2);
    free(pc1->name);
    free(pc1->ip);
    free(pc1->connections);
    free(pc1);
    free(pc2->name);
    free(pc2->ip);
    free(pc2->connections);
    free(pc2);

    return 0;
}
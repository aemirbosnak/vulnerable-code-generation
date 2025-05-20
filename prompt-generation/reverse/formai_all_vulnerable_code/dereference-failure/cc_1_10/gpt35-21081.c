//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_DEVICES 1000

struct connection {
    char *from_device;
    char *to_device;
    int port_number;
};

struct device {
    char *name;
    char *ip_address;
    int num_ports;
    struct connection *ports;
};

struct topology {
    int num_devices;
    struct device devices[MAX_DEVICES];
};

void add_device(struct topology* topo, char* name, char* ip_address, int num_ports) {
    struct device dev;
    dev.name = malloc(strlen(name) + 1);
    strcpy(dev.name, name);
    dev.ip_address = malloc(strlen(ip_address) + 1);
    strcpy(dev.ip_address, ip_address);
    dev.num_ports = num_ports;
    dev.ports = malloc(sizeof(struct connection) * num_ports);
    for (int i = 0; i < num_ports; i++) {
        dev.ports[i].from_device = NULL;
        dev.ports[i].to_device = NULL;
        dev.ports[i].port_number = i + 1;
    }
    topo->devices[topo->num_devices] = dev;
    topo->num_devices++;
}

void add_connection(struct topology* topo, char* from_device, int from_port, char* to_device, int to_port) {
    struct device *device1 = NULL;
    struct device *device2 = NULL;
    for (int i = 0; i < topo->num_devices; i++) {
        if (device1 && device2) {
            break;
        }
        if (strcmp(topo->devices[i].name, from_device) == 0) {
            device1 = &topo->devices[i];
        }
        else if (strcmp(topo->devices[i].name, to_device) == 0) {
            device2 = &topo->devices[i];
        }
    }
    if (!device1 || !device2) {
        printf("error: device not found");
        return;
    }
    device1->ports[from_port - 1].from_device = device1->name;
    device1->ports[from_port - 1].to_device = device2->name;
    device2->ports[to_port - 1].from_device = device1->name;
    device2->ports[to_port - 1].to_device = device2->name;
}

void print_topology(struct topology* topo) {
    for (int i = 0; i < topo->num_devices; i++) {
        printf("Device: %s\n", topo->devices[i].name);
        printf("IP Address: %s\n", topo->devices[i].ip_address);
        for (int j = 0; j < topo->devices[i].num_ports; j++) {
            if (topo->devices[i].ports[j].from_device && topo->devices[i].ports[j].to_device) {
                printf("Port %d: connected to %s on port %d\n", topo->devices[i].ports[j].port_number, topo->devices[i].ports[j].to_device, j + 1);
            }
            else {
                printf("Port %d: not connected\n", j + 1);
            }
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    struct topology topo;
    topo.num_devices = 0;

    add_device(&topo, "Router1", "192.168.1.1", 4);
    add_device(&topo, "Switch1", "192.168.1.2", 8);
    add_device(&topo, "PC1", "192.168.1.3", 1);
    add_device(&topo, "PC2", "192.168.1.4", 1);

    add_connection(&topo, "Router1", 1, "Switch1", 1);
    add_connection(&topo, "Router1", 2, "Switch1", 2);
    add_connection(&topo, "Router1", 3, "Switch1", 3);
    add_connection(&topo, "Router1", 4, "Switch1", 4);
    add_connection(&topo, "Switch1", 1, "Router1", 1);
    add_connection(&topo, "Switch1", 2, "Router1", 2);
    add_connection(&topo, "Switch1", 3, "PC1", 1);
    add_connection(&topo, "Switch1", 4, "PC2", 1);

    print_topology(&topo);

    return 0;
}
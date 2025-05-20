//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
/**
 * Network Topology Mapper 
 * 
 * This program maps the topology of a computer network by analyzing its IP addresses and
 * establishing connections. It outputs a list of connected devices and their relationships.
 * 
 * Written by [Your Name] in a Linus Torvalds style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 50

struct device {
    char name[MAX_NAME_LENGTH];
    char ip_address[INET_ADDRSTRLEN];
    struct device *connections[MAX_DEVICES];
    int num_connections;
};

void print_connection(struct device *d1, struct device *d2) {
    printf("%s is connected to %s\n", d1->name, d2->name);
}

void map_topology(struct device *devices[], int num_devices) {
    for (int i = 0; i < num_devices; i++) {
        for (int j = i+1; j < num_devices; j++) {
            if (strcmp(devices[i]->ip_address, devices[j]->ip_address) == 0) {
                devices[i]->connections[devices[i]->num_connections++] = devices[j];
                devices[j]->connections[devices[j]->num_connections++] = devices[i];
                print_connection(devices[i], devices[j]);
            }
        }
    }
}

int main() {
    printf("Welcome to Network Topology Mapper!\n");
    printf("Please enter the number of devices to map: ");
    int num_devices;
    scanf("%d", &num_devices);

    struct device *devices[num_devices];
    for (int i = 0; i < num_devices; i++) {
        devices[i] = malloc(sizeof(struct device));

        printf("Enter the name of device %d: ", i+1);
        scanf("%s", devices[i]->name);

        printf("Enter the IP address of device %d: ", i+1);
        scanf("%s", devices[i]->ip_address);

        devices[i]->num_connections = 0;
    }

    printf("\nMapping Topology...\n");
    map_topology(devices, num_devices);

    printf("\n\nTopology Map:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("\nDevice Name: %s\n", devices[i]->name);
        printf("IP Address: %s\n", devices[i]->ip_address);
        printf("Connections:\n");
        for (int j = 0; j < devices[i]->num_connections; j++) {
            printf("\t%s\n", devices[i]->connections[j]->name);
        }
        free(devices[i]);
    }

    printf("\nThank you for using Network Topology Mapper!\n");
    return 0;
}
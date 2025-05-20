//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_IP_LENGTH 16
#define MAX_NAME_LENGTH 100

typedef struct {
    char ip_address[MAX_IP_LENGTH];
    char device_name[MAX_NAME_LENGTH];
    int num_neighbors;
    int neighbors[MAX_DEVICES];
} Device;

int num_devices;
Device devices[MAX_DEVICES];

int main() {
    // read in device information from file
    FILE *fp;
    fp = fopen("network_topology.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *ip_address = strtok(line, ",");
        strcpy(devices[num_devices].ip_address, ip_address);

        char *device_name = strtok(NULL, ",");
        strcpy(devices[num_devices].device_name, device_name);

        char *neighbor = strtok(NULL, ",");
        while (neighbor != NULL) {
            devices[num_devices].neighbors[devices[num_devices].num_neighbors] = atoi(neighbor);
            devices[num_devices].num_neighbors++;
            neighbor = strtok(NULL, ",");
        }

        num_devices++;
    }

    // print out device information
    printf("Network Topology:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("Device %d:\n", i+1);
        printf("IP Address: %s\n", devices[i].ip_address);
        printf("Device Name: %s\n", devices[i].device_name);
        printf("Neighbors: ");
        for (int j = 0; j < devices[i].num_neighbors; j++) {
            printf("%d ", devices[i].neighbors[j]);
        }
        printf("\n\n");
    }

    // create adjacency matrix
    int adjacency_matrix[MAX_DEVICES][MAX_DEVICES];
    for (int i = 0; i < num_devices; i++) {
        for (int j = 0; j < num_devices; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < num_devices; i++) {
        for (int j = 0; j < devices[i].num_neighbors; j++) {
            adjacency_matrix[i][devices[i].neighbors[j]-1] = 1;
        }
    }

    // print out adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < num_devices; i++) {
        for (int j = 0; j < num_devices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
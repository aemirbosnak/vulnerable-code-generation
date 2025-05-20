//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 1000

struct Device {
    char name[50];
    char ip[20];
    char mac[20];
    int port;
};

struct Link {
    struct Device* device1;
    struct Device* device2;
    int bandwidth;
};

int find_device(char* name, struct Device* devices, int num_devices) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void read_topology(struct Device* devices, int* num_devices, struct Link* links, int* num_links) {
    char line[1000];
    char* token;
    char* delimiter = ", ";

    while (fgets(line, sizeof(line), stdin) != NULL) {
        token = strtok(line, delimiter);

        if (strcmp(token, "device") == 0) {
            token = strtok(NULL, delimiter);
            strncpy(devices[*num_devices].name, token, sizeof(devices[*num_devices].name) - 1);

            token = strtok(NULL, delimiter);
            strncpy(devices[*num_devices].ip, token, sizeof(devices[*num_devices].ip) - 1);

            token = strtok(NULL, delimiter);
            strncpy(devices[*num_devices].mac, token, sizeof(devices[*num_devices].mac) - 1);

            (*num_devices)++;
        } else if (strcmp(token, "link") == 0) {
            token = strtok(NULL, delimiter);
            int device1_index = find_device(token, devices, *num_devices);
            if (device1_index == -1) {
                fprintf(stderr, "Error: unknown device: %s\n", token);
                exit(1);
            }
            struct Device* device1 = &devices[device1_index];

            token = strtok(NULL, delimiter);
            int device2_index = find_device(token, devices, *num_devices);
            if (device2_index == -1) {
                fprintf(stderr, "Error: unknown device: %s\n", token);
                exit(1);
            }
            struct Device* device2 = &devices[device2_index];

            token = strtok(NULL, delimiter);
            int bandwidth = atoi(token);

            links[*num_links].device1 = device1;
            links[*num_links].device2 = device2;
            links[*num_links].bandwidth = bandwidth;
            (*num_links)++;
        } else {
            fprintf(stderr, "Error: unknown command: %s\n", token);
            exit(1);
        }
    }
}

void print_topology(struct Device* devices, int num_devices, struct Link* links, int num_links) {
    printf("Devices:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s, %s)\n", devices[i].name, devices[i].ip, devices[i].mac);
    }

    printf("Links:\n");
    for (int i = 0; i < num_links; i++) {
        printf("%s - %s (%d Mbps)\n", links[i].device1->name, links[i].device2->name, links[i].bandwidth);
    }
}

int main() {
    struct Device devices[MAX_DEVICES];
    int num_devices = 0;
    struct Link links[MAX_DEVICES];
    int num_links = 0;

    read_topology(devices, &num_devices, links, &num_links);
    print_topology(devices, num_devices, links, num_links);

    return 0;
}
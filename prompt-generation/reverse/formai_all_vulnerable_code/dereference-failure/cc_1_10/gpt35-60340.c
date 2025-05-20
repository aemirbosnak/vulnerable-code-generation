//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_DEVICES 100
#define MAX_TOPOLOGY 100

typedef struct {
    char ip_address[16];
    char hostname[256];
} device_t;

typedef struct {
    int device1_index;
    int device2_index;
} topology_t;

int num_devices = 0;
device_t devices[MAX_DEVICES];

int num_topologies = 0;
topology_t topologies[MAX_TOPOLOGY];

void add_device(char* ip_address, char* hostname) {
    if (num_devices == MAX_DEVICES) {
        printf("Error: Maximum number of devices reached.\n");
        return;
    }
    strcpy(devices[num_devices].ip_address, ip_address);
    strcpy(devices[num_devices].hostname, hostname);
    num_devices++;
}

void add_topology(int device1_index, int device2_index) {
    if (num_topologies == MAX_TOPOLOGY) {
        printf("Error: Maximum number of topologies reached.\n");
        return;
    }
    topologies[num_topologies].device1_index = device1_index;
    topologies[num_topologies].device2_index = device2_index;
    num_topologies++;
}

int get_device_index(char* ip_address) {
    int i;
    for (i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].ip_address, ip_address) == 0) {
            return i;
        }
    }
    return -1;
}

void parse_topology(char* line) {
    char* token;
    char* ip_address1;
    char* ip_address2;
    int device1_index;
    int device2_index;

    token = strtok(line, " ");
    ip_address1 = token;
    token = strtok(NULL, " ");
    ip_address2 = token;

    device1_index = get_device_index(ip_address1);
    device2_index = get_device_index(ip_address2);

    if (device1_index == -1) {
        printf("Error: Device with IP address %s not found.\n", ip_address1);
        return;
    }

    if (device2_index == -1) {
        printf("Error: Device with IP address %s not found.\n", ip_address2);
        return;
    }

    add_topology(device1_index, device2_index);
}

void print_topology() {
    printf("Network Topology:\n");
    int i;
    for (i = 0; i < num_topologies; i++) {
        printf("%s ---- %s\n", devices[topologies[i].device1_index].hostname, devices[topologies[i].device2_index].hostname);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Read input file
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        if (strstr(line, "#") == line) {
            continue;
        }
        else {
            char* token = strtok(line, " ");
            if (strcmp(token, "device") == 0) {
                char* ip_address = strtok(NULL, " ");
                char* hostname = strtok(NULL, " ");
                add_device(ip_address, hostname);
            }
            else if (strcmp(token, "topology") == 0) {
                parse_topology(line);
            }
            else {
                printf("Error: Invalid input format.\n");
                return 1;
            }
        }
    }

    fclose(file);

    // Print network topology
    print_topology();

    return 0;
}
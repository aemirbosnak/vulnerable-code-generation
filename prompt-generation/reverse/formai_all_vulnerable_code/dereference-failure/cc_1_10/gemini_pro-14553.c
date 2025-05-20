//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

typedef struct {
    char *name;
    char *ip;
    int port;
} Device;

typedef struct {
    Device *src;
    Device *dst;
    int weight;
} Link;

typedef struct {
    int num_devices;
    Device **devices;
    int num_links;
    Link **links;
} Network;

void print_network(Network *network) {
    printf("Network:\n");
    for (int i = 0; i < network->num_devices; i++) {
        printf("  %s: %s:%d\n", network->devices[i]->name, network->devices[i]->ip, network->devices[i]->port);
    }
    for (int i = 0; i < network->num_links; i++) {
        printf("  %s (%s:%d) ---%d---> %s (%s:%d)\n",
               network->links[i]->src->name, network->links[i]->src->ip, network->links[i]->src->port,
               network->links[i]->weight,
               network->links[i]->dst->name, network->links[i]->dst->ip, network->links[i]->dst->port);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <network file>\n", argv[0]);
        return 1;
    }

    FILE *network_file = fopen(argv[1], "r");
    if (network_file == NULL) {
        fprintf(stderr, "Error: Unable to open network file: %s\n", strerror(errno));
        return 1;
    }

    // Read the network configuration from the file
    char line[1024];
    Network network;
    network.devices = NULL;
    network.num_devices = 0;
    network.links = NULL;
    network.num_links = 0;
    while (fgets(line, sizeof(line), network_file)) {
        // Remove leading and trailing whitespace
        char *trimmed_line = strtok(line, " \t\r\n");
        if (trimmed_line == NULL) {
            continue;
        }

        // Parse the line
        char *type = strtok(trimmed_line, ":");
        if (strcmp(type, "device") == 0) {
            // Device entry
            char *name = strtok(NULL, ":");
            char *ip = strtok(NULL, ":");
            int port = atoi(strtok(NULL, ":"));
            Device *device = malloc(sizeof(Device));
            device->name = name;
            device->ip = ip;
            device->port = port;
            network.devices = realloc(network.devices, (network.num_devices + 1) * sizeof(Device *));
            network.devices[network.num_devices++] = device;
        } else if (strcmp(type, "link") == 0) {
            // Link entry
            char *src_name = strtok(NULL, ":");
            char *dst_name = strtok(NULL, ":");
            int weight = atoi(strtok(NULL, ":"));
            Device *src = NULL;
            Device *dst = NULL;
            for (int i = 0; i < network.num_devices; i++) {
                if (strcmp(network.devices[i]->name, src_name) == 0) {
                    src = network.devices[i];
                } else if (strcmp(network.devices[i]->name, dst_name) == 0) {
                    dst = network.devices[i];
                }
            }
            if (src == NULL || dst == NULL) {
                fprintf(stderr, "Error: Device not found: %s\n", src_name);
                return 1;
            }
            Link *link = malloc(sizeof(Link));
            link->src = src;
            link->dst = dst;
            link->weight = weight;
            network.links = realloc(network.links, (network.num_links + 1) * sizeof(Link *));
            network.links[network.num_links++] = link;
        } else {
            fprintf(stderr, "Error: Invalid line: %s\n", line);
            return 1;
        }
    }
    fclose(network_file);

    // Print the network
    print_network(&network);

    // Free the memory
    for (int i = 0; i < network.num_devices; i++) {
        free(network.devices[i]);
    }
    free(network.devices);
    for (int i = 0; i < network.num_links; i++) {
        free(network.links[i]);
    }
    free(network.links);

    return 0;
}
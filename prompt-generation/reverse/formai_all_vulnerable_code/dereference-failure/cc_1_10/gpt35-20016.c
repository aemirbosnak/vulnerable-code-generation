//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

// Structure to hold device information
struct device {
    char name[20];
    char ip_address[20];
    int port;
};

// Function to parse the input file and populate device information
void parse_input_file(struct device devices[], int *device_count) {
    FILE *fp;
    char line[100];
    char *token;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " ");
        strcpy(devices[*device_count].name, token);
        token = strtok(NULL, " ");
        strcpy(devices[*device_count].ip_address, token);
        token = strtok(NULL, " ");
        devices[*device_count].port = atoi(token);
        (*device_count)++;
    }

    fclose(fp);
}

// Function to map the network using the given topology
void map_network(struct device devices[], int device_count) {
    int i, j, sock;
    struct sockaddr_in server;

    for (i = 0; i < device_count; i++) {
        for (j = 0; j < device_count; j++) {
            if (i == j) {
                continue;
            }

            sock = socket(AF_INET, SOCK_STREAM, 0);

            if (sock < 0) {
                printf("Error creating socket for %s\n", devices[i].name);
                continue;
            }

            memset(&server, 0, sizeof(server));
            server.sin_family = AF_INET;
            server.sin_port = htons(devices[j].port);

            if (inet_pton(AF_INET, devices[j].ip_address, &server.sin_addr) <= 0) {
                printf("Invalid IP address for %s\n", devices[j].name);
                close(sock);
                continue;
            }

            if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
                printf("%s is not connected to %s\n", devices[i].name, devices[j].name);
            } else {
                printf("%s is connected to %s\n", devices[i].name, devices[j].name);
                close(sock);
            }
        }
    }
}

int main() {
    struct device devices[10];
    int device_count = 0;

    parse_input_file(devices, &device_count);

    map_network(devices, device_count);

    return 0;
}
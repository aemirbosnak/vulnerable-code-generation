//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DEVICES 10
#define BUFFER_SIZE 1024

struct device {
    char name[64];
    char ip_address[16];
    char mac_address[18];
    int signal_strength;
};

int main() {
    int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    printf("Scanning for wireless devices...\n");

    int num_devices = 0;
    struct device devices[MAX_DEVICES];

    while (num_devices < MAX_DEVICES) {
        if (recvfrom(server_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_size) == -1) {
            perror("recvfrom");
            exit(1);
        }

        char *token = strtok(buffer, ",");
        if (token == NULL) {
            continue;
        }

        strcpy(devices[num_devices].name, token);

        token = strtok(NULL, ",");
        strcpy(devices[num_devices].ip_address, token);

        token = strtok(NULL, ",");
        strcpy(devices[num_devices].mac_address, token);

        token = strtok(NULL, ",");
        devices[num_devices].signal_strength = atoi(token);

        num_devices++;
    }

    printf("Found %d devices:\n", num_devices);

    for (int i = 0; i < num_devices; i++) {
        printf("Device %d:\n", i + 1);
        printf("Name: %s\n", devices[i].name);
        printf("IP Address: %s\n", devices[i].ip_address);
        printf("MAC Address: %s\n", devices[i].mac_address);
        printf("Signal Strength: %d\n\n", devices[i].signal_strength);
    }

    close(server_socket);
    return 0;
}
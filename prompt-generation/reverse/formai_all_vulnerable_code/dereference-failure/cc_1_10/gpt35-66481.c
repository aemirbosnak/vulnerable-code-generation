//FormAI DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6
#define ALLOWED_IP "192.168.1.101"
#define ALLOWED_PORT "8080"

void process_packet(char *packet, struct sockaddr_in client_address) {
    char ip_address[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];

    inet_ntop(AF_INET, &(client_address.sin_addr), ip_address, MAX_IP_LENGTH);
    sprintf(port, "%d", ntohs(client_address.sin_port));

    if (strcmp(ip_address, ALLOWED_IP) != 0 || strcmp(port, ALLOWED_PORT) != 0) {
        printf("Blocked packet from %s:%s\n", ip_address, port);
        return;
    }

    printf("Allowed packet from %s:%s\n", ip_address, port);
    // Handle packet processing logic here...
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s PORT_NUMBER\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    // Create socket
    int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (fd == -1) {
        printf("Failed to create socket!\n");
        exit(1);
    }

    // Bind socket to port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(fd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        printf("Failed to bind socket to port %d!\n", port);
        exit(1);
    }

    printf("Firewall is active and listening on port %d...\n", port);

    // Start listening for packets
    char packet[MAX_BUFFER_SIZE];
    struct sockaddr_in client_address;
    socklen_t client_address_length;
    while (1) {
        memset(packet, 0, sizeof(packet));
        client_address_length = sizeof(client_address);
        if (recvfrom(fd, packet, sizeof(packet), 0, (struct sockaddr *) &client_address, &client_address_length) == -1) {
            printf("Failed to receive packet!\n");
            continue;
        }
        process_packet(packet, client_address);
    }

    // Close socket
    close(fd);

    return 0;
}
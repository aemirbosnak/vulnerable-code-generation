//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_RANGE 1024

struct host_info {
    int port;
    char ip[16];
};

void print_help() {
    printf("Usage: %s <IP_ADDRESS> <PORT_RANGE>\n", __func__);
    printf("Example: %s 192.168.1.1 1024-65535\n", __func__);
}

int main(int argc, char *argv[]) {
    int sock, port, i;
    struct host_info *host_info;
    char buffer[1024];

    if (argc < 3) {
        print_help();
        exit(1);
    }

    // Parse input parameters
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            print_help();
            exit(1);
        } else if (sscanf(argv[i], "%d.%d.%d.%d", &host_info->ip[0], &host_info->ip[1], &host_info->ip[2], &host_info->ip[3]) != 4) {
            printf("Invalid IP address format\n");
            exit(1);
        } else if (sscanf(argv[i + 1], "%d", &port) != 1) {
            printf("Invalid port number format\n");
            exit(1);
        }
        host_info->port = port;
        i++;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set address and port
    memset(&(host_info->ip), 0, sizeof(host_info->ip));
    inet_pton(AF_INET, host_info->ip, &(host_info->ip));
    host_info->port = htons(host_info->port);

    // Connect to the host
    if (connect(sock, (struct sockaddr *)&(host_info->ip), sizeof(host_info->ip)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send a SYN packet to the host
    sendto(sock, "SYN", 3, 0, (struct sockaddr *)&(host_info->ip), sizeof(host_info->ip));

    // Receive the SYN-ACK packet from the host
    recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&(host_info->ip), &port);

    // Check if the port is open
    if (ntohs(port) == host_info->port) {
        printf("Port %d is open\n", host_info->port);
    } else {
        printf("Port %d is closed\n", host_info->port);
    }

    // Close the socket
    close(sock);

    return 0;
}
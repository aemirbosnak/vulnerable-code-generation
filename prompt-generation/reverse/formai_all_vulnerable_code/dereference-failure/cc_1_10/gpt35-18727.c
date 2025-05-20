//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {

    // Set up a UDP socket for the scanner to broadcast on
    int udp_socket_fd;
    if ((udp_socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Failed to create UDP socket");
        exit(EXIT_FAILURE);
    }

    // Set socket to broadcast mode
    int broadcast_enabled = 1;
    if (setsockopt(udp_socket_fd, SOL_SOCKET, SO_BROADCAST, &broadcast_enabled,
                   sizeof(broadcast_enabled)) < 0) {
        perror("Failed to enable broadcast on socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in broadcast_address;
    memset(&broadcast_address, 0, sizeof(broadcast_address));

    broadcast_address.sin_family = AF_INET;
    broadcast_address.sin_port = htons(1024);
    inet_pton(AF_INET, "255.255.255.255", &broadcast_address.sin_addr);

    // Send broadcast packet
    if (sendto(udp_socket_fd, "Wireless Scanner", 17, 0, (struct sockaddr *) &broadcast_address,
               sizeof(broadcast_address)) < 0) {
        perror("Failed to broadcast message");
        exit(EXIT_FAILURE);
    }

    // Wait for responses from the network
    struct sockaddr_in receiving_address;
    memset(&receiving_address, 0, sizeof(receiving_address));
    socklen_t address_length = sizeof(receiving_address);

    int recv_socket_fd;
    if ((recv_socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Failed to create response socket");
        exit(EXIT_FAILURE);
    }

    // Bind to the receiving socket
    struct sockaddr_in local_address;
    memset(&local_address, 0, sizeof(local_address));

    local_address.sin_family = AF_INET;
    local_address.sin_port = htons(1024);
    inet_pton(AF_INET, "0.0.0.0", &local_address.sin_addr);

    if (bind(recv_socket_fd, (struct sockaddr *) &local_address, sizeof(local_address)) < 0) {
        perror("Failed to bind response socket");
        exit(EXIT_FAILURE);
    }

    char buf[256];
    bzero(buf, sizeof(buf));

    printf("Scanning...\n");

    while (recvfrom(recv_socket_fd, buf, sizeof(buf), 0, (struct sockaddr *) &receiving_address,
                    &address_length) != -1) {

        if (strcmp(buf, "Wireless Scanner") != 0) {

            struct hostent *host = gethostbyaddr(&(receiving_address.sin_addr), sizeof(struct in_addr), AF_INET);
            if (host != NULL) {
                printf("Device found: %s (%s)\n", host->h_name, inet_ntoa(receiving_address.sin_addr));
            } else {
                printf("Device found: %s\n", inet_ntoa(receiving_address.sin_addr));
            }
        }

        bzero(buf, sizeof(buf));
    }

    close(udp_socket_fd);
    close(recv_socket_fd);

    return 0;
}
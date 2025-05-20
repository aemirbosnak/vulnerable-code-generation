//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DRONE_CONTROL_PORT 49500
#define DRONE_CONTROL_ADDR "192.168.1.1"
#define DRONE_CONTROL_PACKET_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    unsigned char buf[DRONE_CONTROL_PACKET_SIZE];

    // Create a socket.
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket to non-blocking mode.
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    // Configure the server address.
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(DRONE_CONTROL_PORT);
    if (inet_pton(AF_INET, DRONE_CONTROL_ADDR, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Send a command packet to the drone.
    memset(buf, 0, sizeof(buf));
    buf[0] = 0x01; // Command code: takeoff
    if (sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    // Receive a response packet from the drone.
    memset(buf, 0, sizeof(buf));
    if ((n = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL)) < 0) {
        if (errno != EAGAIN) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
    }

    // Print the response packet.
    printf("Response: ");
    for (int i = 0; i < n; i++) {
        printf("%02X ", buf[i]);
    }
    printf("\n");

    // Close the socket.
    close(sockfd);

    return 0;
}
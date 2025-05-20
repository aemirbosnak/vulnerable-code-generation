//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname and port number
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *result, *rp;
    int err;

    if ((err = getaddrinfo(argv[1], "80", &hints, &result))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        if ((sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1) {
            perror("Socket creation failed");
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (rp == NULL) {
        fprintf(stderr, "getaddrinfo failed\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Receive and print packets
    char buffer[MAX_PACKET_SIZE];
    while (1) {
        int bytes_read = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);
        if (bytes_read < 0) {
            perror("Read error");
            exit(EXIT_FAILURE);
        }

        printf("Received packet of length %d:\n%s\n", bytes_read, buffer);
    }

    return 0;
}
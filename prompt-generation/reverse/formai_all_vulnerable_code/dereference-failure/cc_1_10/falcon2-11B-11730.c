//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    struct hostent *he;
    struct sockaddr_in sin;
    int sockfd;
    char buf[BUF_SIZE];

    // Resolve IP address to hostname
    he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "Error resolving hostname\n");
        return 1;
    }

    printf("Hostname: %s\n", he->h_name);

    // Connect to the resolved hostname
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("Error connecting to host");
        return 1;
    }

    // Send a message to the host
    if (send(sockfd, argv[1], strlen(argv[1]), 0) < 0) {
        perror("Error sending message");
        return 1;
    }

    // Receive a message from the host
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("Message from host: %s\n", buf);

    return 0;
}
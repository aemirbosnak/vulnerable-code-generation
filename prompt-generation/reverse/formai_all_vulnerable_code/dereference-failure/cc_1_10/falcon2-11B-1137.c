//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

/* Function to scan a single port */
void scanPort(int port) {
    struct sockaddr_in server;
    int sockfd, numbytes;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        exit(1);
    }

    int startPort = PORT_RANGE_START;
    int endPort = PORT_RANGE_END;

    if (argv[2][0] == '-') {
        if (strcmp(argv[2], "-s") == 0) {
            startPort = strtol(argv[2] + 1, NULL, 10);
        } else if (strcmp(argv[2], "-e") == 0) {
            endPort = strtol(argv[2] + 1, NULL, 10);
        }
    }

    if (startPort > endPort) {
        printf("Invalid port range\n");
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("Error resolving host");
        exit(1);
    }

    for (int i = startPort; i <= endPort; i++) {
        scanPort(i);
    }

    return 0;
}
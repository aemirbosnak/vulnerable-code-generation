//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// A journey through the digital abyss, weaving a tapestry of connections...

// Open a socket, like a gateway to the vast expanse of the network.
int open_socket(char *host, int port) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed!");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Connection failed!");
        return -1;
    }

    return sockfd;
}

// An enigmatic function, probing the depths of a digital domain...
int scan(char *host, int start, int end) {
    int i, sockfd;
    char **ports;

    // Craft a mystical array of ports, ready to explore the unknown.
    ports = (char **)malloc(sizeof(char *) * (end - start + 1));
    for (i = start; i <= end; i++) {
        ports[i - start] = (char *)malloc(sizeof(char) * 6);
        sprintf(ports[i - start], "%d", i);
    }

    // Embark on a daring quest, unlocking the secrets of each port.
    for (i = start; i <= end; i++) {
        sockfd = open_socket(host, atoi(ports[i - start]));
        if (sockfd != -1) {
            printf("Port %s is open!\n", ports[i - start]);
            close(sockfd);
        }
    }

    // Release the ethereal bonds, freeing the ports from our grasp.
    for (i = start; i <= end; i++) {
        free(ports[i - start]);
    }
    free(ports);

    return 0;
}

// A mesmerizing incantation, invoking the power of the cryptic abyss...
int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <host> <start> <end>\n", argv[0]);
        return 1;
    }

    // Unravel the mysteries of the digital realm, port by port.
    scan(argv[1], atoi(argv[2]), atoi(argv[3]));

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

// Function to scan for open ports on a given range of IP addresses
void scanPorts(int portRangeStart, int portRangeEnd) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Resolve IP address and port number
    server = gethostbyname("192.168.1.1");
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portRangeStart);

    // Send SYN packet to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    for (portno = portRangeStart; portno <= portRangeEnd; portno++) {
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }

        // Send SYN packet to the server
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect failed");
            exit(EXIT_FAILURE);
        }

        printf("%d : open\n", portno);

        if (close(sockfd) < 0) {
            perror("close failed");
            exit(EXIT_FAILURE);
        }
    }

    close(sockfd);
}

int main() {
    int portRangeStart = 1;
    int portRangeEnd = 1000;

    scanPorts(portRangeStart, portRangeEnd);

    return 0;
}
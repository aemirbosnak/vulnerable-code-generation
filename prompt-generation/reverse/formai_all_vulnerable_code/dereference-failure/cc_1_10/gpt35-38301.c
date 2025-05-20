//FormAI DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define PORTLOW 0
#define PORTHIGH 65535

// Function to scan the given host on specified port
void scanHost(char *ip, int port) {
    struct sockaddr_in addr;
    int sockfd, flags;
    char buf[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set the socket to non-blocking mode
    flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

    // Set the ip and port of the address structure
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);

    // Attempt to connect to the remote host
    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    // Check if the connection has been established
    fd_set write_set;
    FD_ZERO(&write_set);
    FD_SET(sockfd, &write_set);
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    select(sockfd + 1, NULL, &write_set, NULL, &timeout);
    if (FD_ISSET(sockfd, &write_set)) {
        sprintf(buf, "%d: OPEN\n", port);
        write(STDOUT_FILENO, buf, strlen(buf));
    } else {
        sprintf(buf, "%d: CLOSED\n", port);
        write(STDOUT_FILENO, buf, strlen(buf));
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    int i;
    char *ip;
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }
    ip = argv[1];
    printf("Scanning host %s:\n", ip);

    for (i = PORTLOW; i <= PORTHIGH; i++) {
        scanHost(ip, i);
    }
    return 0;
}
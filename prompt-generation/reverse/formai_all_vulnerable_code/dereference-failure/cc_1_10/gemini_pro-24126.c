//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

// Custom error handling function
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port1> [port2] ...\n", argv[0]);
        exit(1);
    }

    // Get the hostname and port numbers
    char *hostname = argv[1];
    int ports[] = { atoi(argv[2]) };
    int num_ports = argc - 2;

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        error("gethostbyname");
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket");
    }

    // Loop through the port numbers
    for (int i = 0; i < num_ports; i++) {
        // Create a sockaddr_in struct
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(ports[i]);
        addr.sin_addr = *(struct in_addr *) host->h_addr;

        // Connect to the port
        int connfd = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
        if (connfd < 0) {
            printf("Port %d: closed\n", ports[i]);
        } else {
            close(connfd);
            printf("Port %d: open\n", ports[i]);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}
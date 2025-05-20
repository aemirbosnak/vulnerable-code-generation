//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
// A ken thompson style program to print the topology of a network.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 80

int main(int argc, char **argv) {
    // Get the hostname of the target machine.
    char *hostname = argv[1];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname to an IP address.
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Create a sockaddr_in struct.
    struct sockaddr_in sockaddr_in;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(PORT);
    sockaddr_in.sin_addr = *(struct in_addr *) hostent->h_addr;

    // Connect to the target machine.
    if (connect(sockfd, (struct sockaddr *) &sockaddr_in, sizeof(sockaddr_in)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a message to the target machine.
    char *message = "GET / HTTP/1.1\nHost: ";
    message = realloc(message, strlen(message) + strlen(hostname) + 2);
    strcat(message, hostname);
    strcat(message, "\n\n");
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response from the target machine.
    char buffer[1024];
    int nbytes;
    while ((nbytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        write(1, buffer, nbytes);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}
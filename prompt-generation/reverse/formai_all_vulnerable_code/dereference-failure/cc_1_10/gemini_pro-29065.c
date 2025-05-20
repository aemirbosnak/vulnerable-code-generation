//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// A recursive function to map the network topology
void map_network(struct sockaddr_in *addr, int depth) {
    int sockfd;
    struct sockaddr_in their_addr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }

    // Connect to the server
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(55555);
    their_addr.sin_addr = addr->sin_addr;

    // Send a message to the server
    if (sendto(sockfd, "Hello", 5, 0, (struct sockaddr *)&their_addr, sizeof(their_addr)) == -1) {
        perror("sendto");
        return;
    }

    // Receive a response from the server
    if (recvfrom(sockfd, buffer, 1024, 0, NULL, NULL) == -1) {
        perror("recvfrom");
        return;
    }

    // Print the response from the server
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    // Recursively map the network topology
    if (depth > 0) {
        map_network(&their_addr, depth - 1);
    }
}

int main() {
    struct sockaddr_in addr;
    char hostname[1024];

    // Get the hostname of the local machine
    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("gethostname");
        return EXIT_FAILURE;
    }

    // Get the IP address of the local machine
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Initialize the sockaddr_in structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(55555);
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Map the network topology
    map_network(&addr, 10);

    return EXIT_SUCCESS;
}
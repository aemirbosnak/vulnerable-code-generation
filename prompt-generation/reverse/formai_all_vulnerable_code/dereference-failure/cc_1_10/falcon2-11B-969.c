//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Initialize the sockaddr_in structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(0);

    // Bind the socket to any available port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Get the local IP address
    struct hostent *host;
    host = gethostbyname("");
    if (host == NULL) {
        fprintf(stderr, "Error getting local IP address: %s\n", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }

    // Loop forever, waiting for a datagram to arrive
    for (;;) {
        // Receive a datagram from a client
        struct sockaddr_in client_addr;
        socklen_t addrlen = sizeof(client_addr);
        if (recvfrom(sockfd, &client_addr, sizeof(client_addr), 0, (struct sockaddr *)&client_addr, &addrlen) == -1) {
            fprintf(stderr, "Error receiving datagram: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Print the IP address of the client
        printf("Client IP address: %s\n", inet_ntoa(client_addr.sin_addr));

        // Close the socket
        close(sockfd);
        break;
    }

    // Success
    printf("Success\n");
    return 0;
}
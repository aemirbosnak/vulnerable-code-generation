//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to scan a single port on a single host
void scan_port(int port, char *host, int timeout) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Failed to create socket\n");
        return;
    }

    // Fill in the server address information
    server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: Host %s not found\n", host);
        return;
    }
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Failed to connect to port %d\n", port);
        return;
    }

    // Send data to the server
    char data[100];
    bzero(data, 100);
    send(sockfd, data, strlen(data), 0);

    // Receive response from the server
    char response[100];
    bzero(response, 100);
    recv(sockfd, response, sizeof(response), 0);

    // Check for response
    if (strcmp(response, "Open") == 0) {
        printf("Port %d on host %s is open\n", port, host);
    } else {
        printf("Port %d on host %s is closed\n", port, host);
    }

    // Close the socket
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    int port = 80;
    char host[100];
    int timeout = 5;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    if (argc > 2) {
        strncpy(host, argv[2], 99);
    }

    if (argc > 3) {
        timeout = atoi(argv[3]);
    }

    scan_port(port, host, timeout);

    return 0;
}
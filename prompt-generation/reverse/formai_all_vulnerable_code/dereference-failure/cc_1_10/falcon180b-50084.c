//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in serveraddr;
    char hostname[MAX_HOST_LEN];
    char buffer[BUFFER_SIZE];

    // Check if correct number of arguments are provided
    if (argc!= 2) {
        printf("Usage:./ping <hostname>\n");
        exit(1);
    }

    // Copy hostname to a character array
    strcpy(hostname, argv[1]);

    // Get the IP address of the hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    // Set up the server address structure
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(7);
    memcpy(&serveraddr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    // Send a ping message
    send(sockfd, "PING", strlen("PING"), 0);

    // Receive a response
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Print the response
    printf("Response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}
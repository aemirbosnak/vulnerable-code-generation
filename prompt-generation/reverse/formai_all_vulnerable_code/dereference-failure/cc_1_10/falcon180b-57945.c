//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER "127.0.0.1"

int main() {
    int sockfd, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Socket created\n");

    // Set server address
    server = gethostbyname(SERVER);
    if (server == NULL) {
        printf("Error getting server address\n");
        exit(1);
    }

    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    // Receive data from server
    addrlen = sizeof(cli_addr);
    memset(&buffer, 0, BUFFER_SIZE);
    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        printf("Received data: %s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}
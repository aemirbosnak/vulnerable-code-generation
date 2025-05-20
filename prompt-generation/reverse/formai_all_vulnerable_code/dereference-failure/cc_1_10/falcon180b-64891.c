//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 1024

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    int n, len;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    // Set server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error getting server address\n");
        exit(0);
    }
    bcopy(server->h_addr, &serv_addr.sin_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    // Receive data from server
    n = recv(sockfd, buffer, MAX, 0);
    if (n < 0) {
        printf("Error receiving data\n");
        exit(0);
    }
    buffer[n] = '\0';
    printf("Received data: %s\n", buffer);

    // Send data to server
    len = strlen("Hello, server!");
    send(sockfd, "Hello, server!", len, 0);

    // Close socket
    close(sockfd);
    exit(0);
}
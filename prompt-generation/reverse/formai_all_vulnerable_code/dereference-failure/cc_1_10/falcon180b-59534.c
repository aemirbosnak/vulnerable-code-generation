//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char *host;
    int port;

    if (argc!= 3) {
        printf("Usage:./ping_test <host> <port>\n");
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send ping request
    send(sockfd, "PING", strlen("PING"), 0);

    // Receive response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    // Check response
    if (strcmp(buffer, "PONG")!= 0) {
        printf("Error: Invalid response\n");
        exit(1);
    }

    printf("Ping successful\n");

    close(sockfd);
    return 0;
}
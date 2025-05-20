//Falcon-180B DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Set port number
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Set IP address

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send request to server
    char request[50] = "GET / HTTP/1.1\r\nHost: localhost:8080\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    // Receive response from server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    // Print response
    printf("Response:\n%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}
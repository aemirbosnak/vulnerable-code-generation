//Falcon-180B DATASET v1.0 Category: Networking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[BUFFER_SIZE];
    int len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    host = gethostbyname("localhost");
    if (host == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    strcpy(buffer, "Hello, world!");
    len = strlen(buffer);
    if (send(sockfd, buffer, len, 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive message from server
    len = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (len == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    buffer[len] = '\0';
    printf("Received message: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}
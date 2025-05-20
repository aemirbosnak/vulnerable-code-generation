//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char *server_ip = "127.0.0.1";
    int server_port = 8080;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Get server address
    server = gethostbyname(server_ip);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", server_ip);
        exit(EXIT_FAILURE);
    }

    // Fill server_addr structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send message to server
    char message[] = "Hello, world!";
    send(sockfd, message, strlen(message), 0);

    // Receive message from server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer + bytes_received, sizeof(buffer) - bytes_received, 0)) > 0) {
        if (bytes_received == 0) {
            break;
        }
        if (bytes_received == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("Message from server: %s\n", buffer);

    close(sockfd);
    return 0;
}
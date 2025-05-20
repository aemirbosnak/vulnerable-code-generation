//FormAI DATASET v1.0 Category: Socket programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 256

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd, port;
    struct sockaddr_in server, client;
    char buf[BUFSIZE];

    if(argc < 2) {
        printf("Usage: %s port\n", argv[0]);
        exit(1);
    }

    // Parse port argument
    port = atoi(argv[1]);

    // Create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create server socket");
        exit(1);
    }

    // Configure server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);

    // Bind socket to server address
    if(bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to bind server socket");
        close(sockfd);
        exit(1);
    }

    // Listen for incoming connections
    if(listen(sockfd, 10) < 0) {
        perror("Failed to listen for connections");
        close(sockfd);
        exit(1);
    }

    printf("Server listening on port %d!\n", port);

    // Accept incoming connection
    socklen_t client_len = sizeof(client);
    if((client_sockfd = accept(sockfd, (struct sockaddr *)&client, &client_len)) < 0) {
        perror("Failed to accept incoming connection");
        close(sockfd);
        exit(1);
    }

    printf("Accepted incoming connection from client %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    // Read message from client
    memset(buf, 0, sizeof(buf));
    if(read(client_sockfd, buf, BUFSIZE) < 0) {
        perror("Failed to read from client socket");
        close(sockfd);
        close(client_sockfd);
        exit(1);
    }

    printf("Received message from client: %s", buf);

    // Modify message and send back to client
    strcat(buf, "|| modified by server");
    if(write(client_sockfd, buf, strlen(buf)) < 0) {
        perror("Failed to write to client socket");
        close(sockfd);
        close(client_sockfd);
        exit(1);
    }

    printf("Sent modified message back to client: %s\n", buf);

    // Close sockets and exit program
    close(client_sockfd);
    close(sockfd);
    return 0;
}
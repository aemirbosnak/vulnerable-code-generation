//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd, bytesread;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    char buffer[MAXLINE];

    // Initialize the server address structure
    server = gethostbyname("localhost");
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(8080);

    // Create the server socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the server socket to the address
    if (bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listenfd, 5) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Chat server is listening on port 8080\n");

    while (1) {
        // Accept a new connection
        if ((connfd = accept(listenfd, (struct sockaddr *) &client_addr, (socklen_t *) &bytesread)) < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // Receive a message from the client
        bzero(buffer, MAXLINE);
        bytesread = recv(connfd, buffer, MAXLINE, 0);
        printf("%s\n", buffer);

        // Send a message back to the client
        bzero(buffer, MAXLINE);
        sprintf(buffer, "Message received: %s\n", buffer);
        bytesread = send(connfd, buffer, strlen(buffer), 0);

        // Close the connection
        close(connfd);
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxySession {
    int sockfd;
    struct ProxySession *next;
} ProxySession;

ProxySession *head = NULL;

void addProxySession(int sockfd) {
    ProxySession *newSession = malloc(sizeof(ProxySession));
    newSession->sockfd = sockfd;
    newSession->next = head;
    head = newSession;
}

void processRequest(ProxySession *session) {
    char buffer[MAX_BUFFER_SIZE];
    int bytesRead = read(session->sockfd, buffer, MAX_BUFFER_SIZE);
    if (bytesRead > 0) {
        printf("Client: %s\n", buffer);
        write(session->sockfd, buffer, bytesRead);
    } else {
        printf("Error reading from client.\n");
    }
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in clientSocket, serverSocket;
    char message[MAX_BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    if (sockfd == -1) {
        perror("Error creating socket.");
        exit(1);
    }

    // Bind the socket to a port
    serverSocket.sin_family = AF_INET;
    serverSocket.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&serverSocket, sizeof(serverSocket)) == -1) {
        perror("Error binding socket.");
        exit(1);
    }

    // Listen for connections
    while (1) {
        newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd == -1) {
            perror("Error accepting connection.");
            continue;
        }

        // Add the new session to the list
        addProxySession(newsockfd);

        // Process the request
        processRequest(head);

        // Close the connection
        close(newsockfd);
    }

    return 0;
}
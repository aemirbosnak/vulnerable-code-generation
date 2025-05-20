//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

typedef struct ClientConnection {
    int sockfd;
    struct ClientConnection* next;
} ClientConnection;

ClientConnection* insertClientConnection(ClientConnection* head, int sockfd);

void handleClientConnection(ClientConnection* connection);

int main() {
    int listenfd, sockfd, clientfd;
    struct sockaddr_in client_addr;
    struct ClientConnection* head = NULL;

    listenfd = socket(AF_INET, SOCK_STREAM, htons(80));
    bind(listenfd, (struct sockaddr*)&client_addr, sizeof(client_addr));

    while (1) {
        clientfd = accept(listenfd, NULL, NULL);
        insertClientConnection(head, clientfd);
        handleClientConnection(head);
    }

    return 0;
}

ClientConnection* insertClientConnection(ClientConnection* head, int sockfd) {
    ClientConnection* newConnection = malloc(sizeof(ClientConnection));
    newConnection->sockfd = sockfd;
    newConnection->next = head;
    head = newConnection;
    return head;
}

void handleClientConnection(ClientConnection* connection) {
    char buffer[BUFFER_SIZE];
    int readBytes, writeBytes;

    readBytes = read(connection->sockfd, buffer, BUFFER_SIZE);
    if (readBytes > 0) {
        writeBytes = write(connection->sockfd, buffer, readBytes);
        if (writeBytes < 0) {
            perror("Error writing to socket");
        }
    }

    close(connection->sockfd);
    free(connection);
}
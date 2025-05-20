//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ClientState {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct ClientState *next;
} ClientState;

ClientState *head = NULL;

void addClientState(int sockfd) {
    ClientState *newClientState = malloc(sizeof(ClientState));
    newClientState->sockfd = sockfd;
    newClientState->next = head;
    head = newClientState;
}

void handleClient(ClientState *clientState) {
    printf("Client connected: %d\n", clientState->sockfd);
    char *requestLine = malloc(MAX_BUFFER_SIZE);
    read(clientState->sockfd, requestLine, MAX_BUFFER_SIZE);
    printf("Request line: %s\n", requestLine);

    // Process request and send response
    char *responseLine = "HTTP/1.1 200 OK\r\n\r\nHello, world!";
    write(clientState->sockfd, responseLine, strlen(responseLine));
    free(requestLine);
    free(clientState);
}

int main() {
    int sockfd, clientsockfd;
    struct sockaddr_in sockAddr, clientAddr;
    sockAddr.sin_port = htons(8080);
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));

    while (1) {
        clientsockfd = accept(sockfd, (struct sockaddr *)&clientAddr, NULL);
        addClientState(clientsockfd);
        handleClient(head);
    }

    return 0;
}
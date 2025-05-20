//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyContext {
    int clientFd;
    int serverFd;
    char buffer[MAX_BUFFER_SIZE];
    struct ProxyContext* next;
} ProxyContext;

ProxyContext* proxyContextHead = NULL;

void proxyHandler(int clientFd) {
    ProxyContext* context = (ProxyContext*)malloc(sizeof(ProxyContext));
    context->clientFd = clientFd;
    context->serverFd = -1;
    context->next = proxyContextHead;
    proxyContextHead = context;

    // Read data from client
    int bytesRead = read(clientFd, context->buffer, MAX_BUFFER_SIZE);
    if (bytesRead > 0) {
        // Connect to server
        struct sockaddr_in serverSockAddr;
        serverSockAddr.sin_port = htons(8080);
        serverSockAddr.sin_family = AF_INET;
        context->serverFd = socket(AF_INET, SOCK_STREAM, htons(8080));
        connect(context->serverFd, (struct sockaddr*)&serverSockAddr, sizeof(serverSockAddr));

        // Send data to server
        write(context->serverFd, context->buffer, bytesRead);

        // Receive data from server
        bytesRead = read(context->serverFd, context->buffer, MAX_BUFFER_SIZE);

        // Send data to client
        write(clientFd, context->buffer, bytesRead);
    }

    // Free context
    free(context);
}

int main() {
    // Listen for client connections
    int clientFd = listen(8080, NULL);
    while (1) {
        // Accept client connection
        int newClientFd = accept(clientFd, NULL, NULL);
        proxyHandler(newClientFd);
    }

    return 0;
}
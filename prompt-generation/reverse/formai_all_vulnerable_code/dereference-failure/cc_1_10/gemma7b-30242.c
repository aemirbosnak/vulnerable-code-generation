//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ProxyClient {
    int sockfd;
    char hostname[256];
    char port;
    struct ProxyClient* next;
} ProxyClient;

ProxyClient* proxyClients = NULL;

void addProxyClient(char* hostname, int port) {
    ProxyClient* newClient = (ProxyClient*)malloc(sizeof(ProxyClient));
    newClient->sockfd = -1;
    strcpy(newClient->hostname, hostname);
    newClient->port = port;
    newClient->next = proxyClients;
    proxyClients = newClient;
}

int main() {
    addProxyClient("localhost", 8080);
    addProxyClient("localhost", 8081);

    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    struct sockaddr_in serverSockAddr;
    serverSockAddr.sin_family = AF_INET;
    serverSockAddr.sin_port = htons(80);
    serverSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr*)&serverSockAddr, sizeof(serverSockAddr));

    char buffer[MAX_BUFFER_SIZE];
    int clientSockfd;
    struct sockaddr_in clientSockAddr;
    socklen_t clientSockLen;

    while (1) {
        clientSockLen = sizeof(clientSockAddr);
        clientSockfd = accept(sockfd, (struct sockaddr*)&clientSockAddr, &clientSockLen);

        printf("Client connected: %s:%d\n", clientSockAddr.sin_addr.s_addr, clientSockAddr.sin_port);

        // Forward request to appropriate proxy client
        ProxyClient* currentClient = proxyClients;
        while (currentClient) {
            if (strcmp(clientSockAddr.sin_addr.s_addr, currentClient->hostname) == 0 && currentClient->port == clientSockAddr.sin_port) {
                break;
            }
            currentClient = currentClient->next;
        }

        if (currentClient) {
            // Connect to proxy client
            int proxySockfd = socket(AF_INET, SOCK_STREAM, htons(80));
            struct sockaddr_in proxySockAddr;
            proxySockAddr.sin_family = AF_INET;
            proxySockAddr.sin_port = htons(currentClient->port);
            proxySockAddr.sin_addr.s_addr = htonl(currentClient->hostname);

            connect(proxySockfd, (struct sockaddr*)&proxySockAddr, sizeof(proxySockAddr));

            // Forward data between client and proxy client
            char data[MAX_BUFFER_SIZE];
            int bytesRead, bytesWritten;

            while ((bytesRead = read(clientSockfd, data, MAX_BUFFER_SIZE)) > 0) {
                bytesWritten = write(proxySockfd, data, bytesRead);
            }

            close(proxySockfd);
        } else {
            printf("Error: No proxy client found.\n");
        }

        close(clientSockfd);
    }

    return 0;
}
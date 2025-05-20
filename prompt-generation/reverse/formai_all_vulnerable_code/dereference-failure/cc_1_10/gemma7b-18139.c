//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#define BUFFER_SIZE 4096

typedef struct ProxyData {
    int sockfd;
    char host[256];
    char port[256];
    struct ProxyData* next;
} ProxyData;

ProxyData* proxyList = NULL;

void addProxy(char* host, char* port) {
    ProxyData* newNode = malloc(sizeof(ProxyData));
    newNode->sockfd = -1;
    strcpy(newNode->host, host);
    strcpy(newNode->port, port);
    newNode->next = proxyList;
    proxyList = newNode;
}

int main() {
    addProxy("localhost", "8888");
    addProxy("localhost", "8889");

    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    bind(sockfd, NULL, 0);

    char buffer[BUFFER_SIZE];
    int clientSockfd;

    while (1) {
        clientSockfd = accept(sockfd, NULL, NULL);

        ProxyData* currentProxy = proxyList;

        while (currentProxy) {
            if (strcmp(currentProxy->host, "localhost") == 0 && strcmp(currentProxy->port, "8888") == 0) {
                break;
            }
            currentProxy = currentProxy->next;
        }

        if (currentProxy) {
            printf("Connecting to proxy: %s:%s\n", currentProxy->host, currentProxy->port);

            int proxySockfd = socket(AF_INET, SOCK_STREAM, htons(80));
            connect(proxySockfd, currentProxy->host, currentProxy->port);

            char data[BUFFER_SIZE];
            int readBytes, writeBytes;

            while ((readBytes = read(clientSockfd, data, BUFFER_SIZE)) > 0) {
                writeBytes = write(proxySockfd, data, readBytes);
                if (writeBytes < 0) {
                    perror("Error writing to proxy");
                    break;
                }
            }

            close(proxySockfd);
            close(clientSockfd);
        } else {
            printf("No proxy available\n");
            close(clientSockfd);
        }
    }

    return 0;
}
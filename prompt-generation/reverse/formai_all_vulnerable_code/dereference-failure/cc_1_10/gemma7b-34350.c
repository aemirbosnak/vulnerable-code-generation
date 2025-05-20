//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyClient {
    char hostname[256];
    int port;
    struct ProxyClient* next;
} ProxyClient;

ProxyClient* insertClient(ProxyClient* head, char* hostname, int port) {
    ProxyClient* newClient = malloc(sizeof(ProxyClient));
    strcpy(newClient->hostname, hostname);
    newClient->port = port;
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        ProxyClient* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newClient;
    }

    return head;
}

void proxy(ProxyClient* head) {
    int sockfd, clientfd, serverfd;
    struct sockaddr_in client_addr, server_addr;
    char buffer[MAX_BUFFER_SIZE];
    int nread, nwrite;

    while (1) {
        clientfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

        if (clientfd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        ProxyClient* client = insertClient(head, inet_ntoa(client_addr.sin_addr), client_addr.sin_port);

        serverfd = socket(AF_INET, SOCK_STREAM, htons(80));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(8080);
        inet_pton(AF_INET, client->hostname, &server_addr.sin_addr);

        nread = read(clientfd, buffer, MAX_BUFFER_SIZE);
        nwrite = write(serverfd, buffer, nread);

        close(clientfd);
        close(serverfd);
    }
}

int main() {
    ProxyClient* head = NULL;

    proxy(head);

    return 0;
}
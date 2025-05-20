//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SERVERS 3

#ifdef _CLIENT
#include <sys/socket.h>
#include <unistd.h>
#endif

#ifdef _SERVER
#include <sys/socket.h>
#include <pthread.h>
#endif

char **messages;

#ifdef _SERVER
void *handle_client(void *clientSock) {
    int clientSockfd = (int)clientSock;
    char message[1024];
    recv(clientSockfd, message, 1024, 0);
    printf("Client: %s\n", message);
    send(clientSockfd, message, strlen(message), 0);
    close(clientSockfd);
    return NULL;
}

void start_server() {
    int sockfd, clientSockfd;
    struct sockaddr_in serverSock, clientSock;
    pthread_t thread;

    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr *)&serverSock, sizeof(serverSock));

    while (1) {
        clientSockfd = accept(sockfd, (struct sockaddr *)&clientSock, NULL);
        pthread_create(&thread, NULL, handle_client, (void *)clientSockfd);
    }
}
#endif

#ifdef _CLIENT
void connect_to_server() {
    int sockfd;
    struct sockaddr_in serverSock;

    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(8080);
    connect(sockfd, (struct sockaddr *)&serverSock, sizeof(serverSock));

    char message[1024];
    printf("Enter your message: ");
    scanf("%s", message);
    send(sockfd, message, strlen(message), 0);
    recv(sockfd, message, 1024, 0);
    printf("Server: %s\n", message);
    close(sockfd);
}
#endif

int main() {
    messages = malloc(100 * sizeof(char *));
    for (int i = 0; i < 100; i++) {
        messages[i] = malloc(1024 * sizeof(char));
    }

    #ifdef _SERVER
    start_server();
    #endif

    #ifdef _CLIENT
    connect_to_server();
    #endif

    return 0;
}
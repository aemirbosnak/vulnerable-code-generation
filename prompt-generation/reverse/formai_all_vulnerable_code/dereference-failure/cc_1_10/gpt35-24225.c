//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAXBUFFER 1024

struct ProxyInfo { // struct to store client and server info
    int client_sockfd;
    char client_ip[16];
    int client_port;
    int server_sockfd;
    char server_ip[16];
    int server_port;
};

void *clientToServer(void *proxyInfo){
    struct ProxyInfo *info = proxyInfo;
    int clientfd = info->client_sockfd;
    int serverfd = info->server_sockfd;

    char buffer[MAXBUFFER];
    int numBytes;

    while ((numBytes = recv(clientfd, buffer, MAXBUFFER, 0)) > 0) { // read from client
        send(serverfd, buffer, numBytes, 0); // send to server
    }

    close(clientfd); // close client socket
    close(serverfd); // close server socket
    free(info); // free allocated memory for proxy info
    pthread_exit(NULL); // exit thread
}

void *serverToClient(void *proxyInfo){
    struct ProxyInfo *info = proxyInfo;
    int clientfd = info->client_sockfd;
    int serverfd = info->server_sockfd;

    char buffer[MAXBUFFER];
    int numBytes;

    while ((numBytes = recv(serverfd, buffer, MAXBUFFER, 0)) > 0) { // read from server
        send(clientfd, buffer, numBytes, 0); // send to client
    }

    close(clientfd); // close client socket
    close(serverfd); // close server socket
    free(info); // free allocated memory for proxy info
    pthread_exit(NULL); // exit thread
}

int main(int argc, char *argv[]) {
    if (argc != 2) { // check for proper arguments
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]); // convert port from string to integer

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Unable to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) { // 5 maximum clients can connect
        perror("Error: Unable to listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len); // accept client connection
        if (clientfd < 0) {
            perror("Error: Unable to accept client connection");
            continue;
        }

        struct ProxyInfo *info = malloc(sizeof(struct ProxyInfo)); // allocate memory for proxy info
        info->client_sockfd = clientfd;
        strncpy(info->client_ip, inet_ntoa(client_addr.sin_addr), 16);
        info->client_port = ntohs(client_addr.sin_port);

        printf("Client (%s:%d) connected...\n", info->client_ip, info->client_port);

        struct sockaddr_in server_addr;
        socklen_t server_len = sizeof(server_addr);
        int serverfd = socket(AF_INET, SOCK_STREAM, 0); // create socket for server

        if (serverfd < 0) {
            perror("Error: Unable to create server socket");
            close(clientfd);
            continue;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80); // port for HTTP server
        server_addr.sin_addr.s_addr = inet_addr("216.58.194.174"); // IP for Google.com

        int status = connect(serverfd, (struct sockaddr *)&server_addr, server_len); // connect to HTTP server
        if (status < 0) {
            perror("Error: Unable to connect to server");
            close(clientfd);
            close(serverfd);
            continue;
        }

        info->server_sockfd = serverfd;
        strncpy(info->server_ip, inet_ntoa(server_addr.sin_addr), 16);
        info->server_port = ntohs(server_addr.sin_port);

        printf("Server (%s:%d) connected...\n", info->server_ip, info->server_port);

        pthread_t clientThread, serverThread; // create threads for client and server communication

        if (pthread_create(&clientThread, NULL, clientToServer, (void *)info) < 0) {
            perror("Error: Unable to create client thread");
            close(clientfd);
            close(serverfd);
            continue;
        }

        if (pthread_create(&serverThread, NULL, serverToClient, (void *)info) < 0) {
            perror("Error: Unable to create server thread");
            close(clientfd);
            close(serverfd);
            continue;
        }

        pthread_join(clientThread, NULL); // wait for threads to finish
        pthread_join(serverThread, NULL);
    }

    close(sockfd); // close socket
    return 0;
}
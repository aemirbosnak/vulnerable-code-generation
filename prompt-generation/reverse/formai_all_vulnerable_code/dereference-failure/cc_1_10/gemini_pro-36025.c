//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

typedef struct client_info {
    int sockfd;
    struct sockaddr_in addr;
} client_info;

typedef struct proxy_info {
    int listenfd;
    struct sockaddr_in addr;
} proxy_info;

void *client_handler(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[MAX_BUFFER_SIZE];
    while (1) {
        // Receive request from client
        bzero(buffer, MAX_BUFFER_SIZE);
        int n = read(client->sockfd, buffer, MAX_BUFFER_SIZE);
        if (n < 0) {
            perror("Error reading from client");
            close(client->sockfd);
            pthread_exit(NULL);
        } else if (n == 0) {
            printf("Client closed connection\n");
            close(client->sockfd);
            pthread_exit(NULL);
        }

        // Parse request
        char *host, *path;
        if (sscanf(buffer, "GET %s %s\r\n", &host, &path) != 2) {
            printf("Invalid request from client\n");
            close(client->sockfd);
            pthread_exit(NULL);
        }

        // Connect to destination server
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error creating socket");
            close(client->sockfd);
            pthread_exit(NULL);
        }
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
            perror("Error converting host to IP address");
            close(client->sockfd);
            close(sockfd);
            pthread_exit(NULL);
        }
        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Error connecting to server");
            close(client->sockfd);
            close(sockfd);
            pthread_exit(NULL);
        }

        // Send request to server
        write(sockfd, buffer, n);

        // Receive response from server
        bzero(buffer, MAX_BUFFER_SIZE);
        n = read(sockfd, buffer, MAX_BUFFER_SIZE);
        if (n < 0) {
            perror("Error reading from server");
            close(client->sockfd);
            close(sockfd);
            pthread_exit(NULL);
        }

        // Send response to client
        write(client->sockfd, buffer, n);

        // Close connections
        close(client->sockfd);
        close(sockfd);
        pthread_exit(NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create proxy info
    proxy_info proxy;
    proxy.addr.sin_family = AF_INET;
    proxy.addr.sin_port = htons(atoi(argv[1]));
    proxy.addr.sin_addr.s_addr = INADDR_ANY;

    // Create listen socket
    proxy.listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy.listenfd < 0) {
        perror("Error creating listen socket");
        return 1;
    }

    // Bind listen socket
    if (bind(proxy.listenfd, (struct sockaddr *)&proxy.addr, sizeof(proxy.addr)) < 0) {
        perror("Error binding listen socket");
        close(proxy.listenfd);
        return 1;
    }

    // Listen on listen socket
    if (listen(proxy.listenfd, MAX_CLIENTS) < 0) {
        perror("Error listening on listen socket");
        close(proxy.listenfd);
        return 1;
    }

    printf("Proxy is listening on port %d\n", proxy.addr.sin_port);

    // Create thread pool
    pthread_t threads[MAX_CLIENTS];
    int i = 0;

    while (1) {
        // Accept client connection
        client_info client;
        socklen_t addrlen = sizeof(client.addr);
        client.sockfd = accept(proxy.listenfd, (struct sockaddr *)&client.addr, &addrlen);
        if (client.sockfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Create client handler thread
        if (pthread_create(&threads[i++], NULL, client_handler, &client) != 0) {
            perror("Error creating client handler thread");
            close(client.sockfd);
            continue;
        }

        // Join client handler thread
        if (pthread_join(threads[i--], NULL) != 0) {
            perror("Error joining client handler thread");
            close(client.sockfd);
            continue;
        }
    }

    // Close listen socket
    close(proxy.listenfd);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_REQUEST_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char request[MAX_REQUEST_SIZE];
    int n;

    // Read the request from the client
    n = read(client->sockfd, request, MAX_REQUEST_SIZE);
    if (n < 0) {
        perror("read");
        close(client->sockfd);
        free(client);
        pthread_exit(NULL);
    }

    // Parse the request
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0) {
        // Send a 405 Method Not Allowed response
        char response[] = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        write(client->sockfd, response, strlen(response));
        close(client->sockfd);
        free(client);
        pthread_exit(NULL);
    }

    // Open a connection to the remote server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        close(client->sockfd);
        free(client);
        pthread_exit(NULL);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        close(client->sockfd);
        free(client);
        pthread_exit(NULL);
    }

    // Send the request to the remote server
    write(sockfd, request, strlen(request));

    // Read the response from the remote server
    char response[MAX_REQUEST_SIZE];
    int m;

    while ((m = read(sockfd, response, MAX_REQUEST_SIZE)) > 0) {
        // Write the response to the client
        write(client->sockfd, response, m);
    }

    // Close the connections
    close(sockfd);
    close(client->sockfd);
    free(client);
    pthread_exit(NULL);
}

int main() {
    // Create a socket for listening
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listenfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listenfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections and handle them in a separate thread
    while (1) {
        client_t *client = malloc(sizeof(client_t));
        client->sockfd = accept(listenfd, (struct sockaddr *)&client->addr, (socklen_t *)sizeof(client->addr));
        if (client->sockfd < 0) {
            perror("accept");
            continue;
        }

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *)client);
    }

    // Close the listening socket
    close(listenfd);

    return 0;
}
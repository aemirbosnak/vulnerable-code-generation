//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_BUF_SIZE 1024

struct client_info {
    int sockfd;
    struct sockaddr_in addr;
};

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buf[MAX_BUF_SIZE];

    // Receive XML data from client
    int bytes_recv = recv(client->sockfd, buf, MAX_BUF_SIZE, 0);
    if (bytes_recv <= 0) {
        perror("Error receiving XML data");
        goto cleanup;
    }

    // Parse XML data
    // ... (parse XML data using your chosen XML parser) ...

    // Send parsing results back to client
    if (send(client->sockfd, "Parsing complete", strlen("Parsing complete"), 0) < 0) {
        perror("Error sending parsing results");
    }

cleanup:
    close(client->sockfd);
    free(client);
    pthread_exit(NULL);
}

int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t tid;

    // Create server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(5000);

    // Bind server socket to address and port
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("Error listening for client connections");
        exit(1);
    }

    // Accept client connections and handle them in separate threads
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Create a new thread to handle the client
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sockfd = client_sockfd;
        client->addr = client_addr;
        pthread_create(&tid, NULL, handle_client, (void *)client);
    }

    // Close server socket
    close(server_sockfd);

    return 0;
}
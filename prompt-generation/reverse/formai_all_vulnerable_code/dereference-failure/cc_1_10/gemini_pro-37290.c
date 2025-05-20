//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

typedef struct client {
    int sockfd;
    char name[256];
} client;

void *handle_client(void *arg) {
    client *c = (client *)arg;
    int sockfd = c->sockfd;
    char name[256];
    strcpy(name, c->name);

    while (1) {
        // Receive message from client
        char buffer[256];
        int n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("Client %s disconnected\n", name);
            close(sockfd);
            free(c);
            pthread_exit(NULL);
        }

        // Print message to server console
        printf("%s: %s\n", name, buffer);

        // Send message back to client
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n <= 0) {
            printf("Error sending message to client %s\n", name);
            close(sockfd);
            free(c);
            pthread_exit(NULL);
        }
    }

    return NULL;
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    while (1) {
        // Accept incoming connection
        client_addr_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (newsockfd < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        // Create new thread to handle client
        pthread_t tid;
        client *c = malloc(sizeof(client));
        c->sockfd = newsockfd;
        strcpy(c->name, inet_ntoa(client_addr.sin_addr));
        if (pthread_create(&tid, NULL, handle_client, (void *)c) != 0) {
            perror("Error creating thread to handle client");
            close(newsockfd);
            free(c);
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define BUFFER_SIZE 1024

struct client_info {
    int sockfd;
    struct sockaddr_in addr;
};

void *client_handler(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(client->sockfd, buffer, BUFFER_SIZE)) > 0) {
        // Process the received data here
        
        // Send a response to the client
        write(client->sockfd, "Received", strlen("Received"));
    }

    if (n == 0) {
        printf("Client disconnected\n");
    } else {
        perror("Error reading from client");
    }

    close(client->sockfd);
    free(client);

    return NULL;
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    pthread_t thread;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        return EXIT_FAILURE;
    }

    listen(sockfd, 5);

    while (1) {
        client_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        struct client_info *client = malloc(sizeof(struct client_info));
        client->sockfd = newsockfd;
        client->addr = client_addr;

        // Create a new thread to handle the client
        if (pthread_create(&thread, NULL, client_handler, (void *)client) < 0) {
            perror("Error creating thread");
            close(newsockfd);
            free(client);
            continue;
        }

        // Detach the thread so that it can run independently
        pthread_detach(thread);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}
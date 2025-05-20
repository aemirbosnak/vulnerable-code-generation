//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

#define PORT 8080

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_info;

void *client_handler(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[1024];
    int n;

    while ((n = read(client->sockfd, buffer, 1024)) > 0) {
        buffer[n] = '\0';
        printf("Received from client: %s\n", buffer);

        // Send the message back to the client
        write(client->sockfd, buffer, n);
    }

    // Close the client socket
    close(client->sockfd);

    // Free the client info
    free(client);

    return NULL;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept a connection
        client_info *client = malloc(sizeof(client_info));
        client->sockfd = accept(sockfd, (struct sockaddr *)&client->addr, (socklen_t *)sizeof(client->addr));
        if (client->sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, client) != 0) {
            perror("pthread_create");
            close(client->sockfd);
            free(client);
            continue;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}
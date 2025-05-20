//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10

typedef struct client {
    int sockfd;
    char *name;
} client;

void handle_client(client *c) {
    char buffer[1024];
    int n;

    while ((n = read(c->sockfd, buffer, sizeof(buffer))) > 0) {
        buffer[n] = '\0';
        printf("%s: %s\n", c->name, buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Client %s disconnected.\n", c->name);
            close(c->sockfd);
            free(c->name);
            free(c);
            return;
        }

        // Echo the message back to the client
        write(c->sockfd, buffer, n);
    }

    if (n == 0) {
        printf("Client %s disconnected.\n", c->name);
        close(c->sockfd);
        free(c->name);
        free(c);
        return;
    } else {
        perror("read");
        exit(1);
    }
}

void accept_clients(int sockfd) {
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int newsockfd;

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        // Create a new client thread
        client *c = malloc(sizeof(client));
        c->sockfd = newsockfd;
        c->name = malloc(1024);
        read(newsockfd, c->name, 1024);

        printf("Client %s connected.\n", c->name);

        // Start the client thread
        handle_client(c);
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    // Bind the socket to the port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept clients
    accept_clients(sockfd);

    return 0;
}
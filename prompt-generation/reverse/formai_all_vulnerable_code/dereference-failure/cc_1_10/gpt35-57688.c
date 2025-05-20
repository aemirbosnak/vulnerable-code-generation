//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

void *client_handler(void *);

int main(int argc, char *argv[])
{
    int server_fd, client_fd, port, opt = 1;
    struct sockaddr_in sockaddr;
    pthread_t thread_id;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address
    port = atoi(argv[1]);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *) &sockaddr, sizeof(sockaddr)) < 0) {
        perror("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_fd, 5) < 0) {
        perror("Failed to listen for client connections");
        exit(EXIT_FAILURE);
    }

    // Accept client connections and spawn handler threads
    printf("Server listening on port %d...\n", port);
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *) &sockaddr, (socklen_t *) &sockaddr)) < 0) {
            perror("Failed to accept client connection");
            continue;
        }
        if (pthread_create(&thread_id, NULL, client_handler, (void *) &client_fd) < 0) {
            perror("Failed to create client handler thread");
            close(client_fd);
            continue;
        }
    }

    return 0;
}

void *client_handler(void *arg)
{
    int client_fd = *(int *) arg;
    char buffer[1024] = {0};
    while (1) {
        if (read(client_fd, buffer, 1024) <= 0) {
            break;
        }
        printf("Received message from client: %s", buffer);
        if (write(client_fd, buffer, strlen(buffer)) <= 0) {
            break;
        }
        memset(buffer, 0, 1024);
    }
    close(client_fd);
    printf("Client disconnected\n");
    pthread_exit(NULL);
}
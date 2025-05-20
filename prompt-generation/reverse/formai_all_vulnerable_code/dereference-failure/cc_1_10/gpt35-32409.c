//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080

void *connection_handler(void *);

int main(int argc, char *argv[]) {
    int sock_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Server address configuration
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attaching socket to the port
    if (bind(sock_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(sock_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accepting connections in a new thread
    while ((new_socket = accept(sock_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen))) {
        pthread_t sniffer_thread;
        int *new_sock = malloc(1);
        *new_sock = new_socket;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) new_sock) < 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection accepted!\n");
    }

    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void *connection_handler(void *socket_fd) {
    int sock_fd = *(int *) socket_fd;
    char buffer[1024] = {0};
    int valread;

    // Receiving message from client
    valread = read(sock_fd, buffer, 1024);
    printf("Message received: %s\n", buffer);

    // Sending response to client
    const char *message = "Hello from server!";
    send(sock_fd, message, strlen(message), 0);
    printf("Response sent: %s\n", message);

    free(socket_fd);
    return 0;
}
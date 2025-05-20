//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *new_socket) {
    int socket = *(int *)new_socket;
    free(new_socket);
    char buffer[BUFFER_SIZE];

    while (1) {
        int valread = read(socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("Client disconnected or error occurred.\n");
            close(socket);
            return NULL;
        }

        int number = atoi(buffer);
        int result = number * number;
        
        sprintf(buffer, "%d", result);
        send(socket, buffer, strlen(buffer), 0);
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        int *new_socket = malloc(sizeof(int));
        if ((*new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            free(new_socket);
            continue;
        }
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, new_socket);
        pthread_detach(thread_id);
    }
    
    return 0;
}
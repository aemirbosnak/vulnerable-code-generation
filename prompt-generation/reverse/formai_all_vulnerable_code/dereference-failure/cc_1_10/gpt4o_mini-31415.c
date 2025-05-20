//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 256

double total = 0;
int count = 0;
pthread_mutex_t lock;

void* client_handler(void* arg) {
    int new_socket = *(int*)arg;
    free(arg);
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = recv(new_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_read <= 0) {
            break; // Connection closed
        }
        
        double num = atof(buffer);
        pthread_mutex_lock(&lock);
        total += num;
        count++;
        double average = total / count;
        pthread_mutex_unlock(&lock);

        sprintf(buffer, "Current Average: %.2f\n", average);
        send(new_socket, buffer, strlen(buffer), 0);
    }
    close(new_socket);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    pthread_mutex_init(&lock, NULL);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Accepted a connection\n");

        // Create a new thread for the client
        pthread_t tid;
        int* pclient = malloc(sizeof(int));
        *pclient = new_socket;
        if (pthread_create(&tid, NULL, client_handler, pclient) != 0) {
            perror("Thread creation failed");
        }
    }

    pthread_mutex_destroy(&lock);
    close(server_fd);
    return 0;
}
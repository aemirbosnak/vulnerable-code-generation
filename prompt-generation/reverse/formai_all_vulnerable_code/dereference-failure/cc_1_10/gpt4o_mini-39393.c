//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    double sum;
    int count;
} Statistics;

Statistics stats;
pthread_mutex_t lock;

void *handle_client(void *new_sock) {
    int sock = *(int*)new_sock;
    free(new_sock);
    double value;
    char buffer[BUFFER_SIZE];

    while (recv(sock, &value, sizeof(value), 0) > 0) {
        pthread_mutex_lock(&lock);
        stats.sum += value;
        stats.count++;
        pthread_mutex_unlock(&lock);
    }

    close(sock);
    return NULL;
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("New client connected.\n");
        pthread_t thread_id;
        int *client_sock = malloc(sizeof(int));
        *client_sock = new_socket;
        pthread_create(&thread_id, NULL, handle_client, client_sock);
        pthread_detach(thread_id);
    }

    close(server_fd);
}

void print_statistics() {
    pthread_mutex_lock(&lock);
    if (stats.count > 0) {
        printf("Statistics: Count = %d, Sum = %f, Mean = %f\n", stats.count, stats.sum, stats.sum / stats.count);
    } else {
        printf("No data received yet.\n");
    }
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_mutex_init(&lock, NULL);
    stats.sum = 0.0;
    stats.count = 0;

    // Start the server in a separate thread to allow continuous operation
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, (void *)start_server, NULL);

    // Loop to print statistics every 10 seconds
    while (1) {
        sleep(10);
        print_statistics();
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
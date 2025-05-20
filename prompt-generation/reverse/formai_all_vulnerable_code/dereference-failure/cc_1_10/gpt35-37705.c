//FormAI DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_LENGTH 1000
#define MAX_CLIENTS 5

int num_clients = 0;
int clients[MAX_CLIENTS];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int *client_fd = (int *) arg;
    char message[MAX_LENGTH];
    
    while (true) {
        memset(message, 0, MAX_LENGTH);
        if (recv(*client_fd, message, MAX_LENGTH, 0) == 0) {
            break;
        }
        printf("Message Received: %s", message);
        pthread_mutex_lock(&lock);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i] != *client_fd) {
                send(clients[i], message, strlen(message), 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }
    
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i] == *client_fd) {
            for (int j = i; j < num_clients-1; j++) {
                clients[j] = clients[j+1];
            }
            break;
        }
    }
    num_clients--;
    close(*client_fd);
    pthread_mutex_unlock(&lock);
    free(client_fd);
    pthread_exit(NULL);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        return -1;
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return -1;
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return -1;
    }
    
    printf("Server listening on port %d...\n", PORT);
    
    while (true) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        if (num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached. Connection rejected.\n");
            close(client_fd);
            continue;
        }
        
        int *new_client = malloc(sizeof(int));
        *new_client = client_fd;
        clients[num_clients] = client_fd;
        num_clients++;
        
        pthread_t tid;
        if ((pthread_create(&tid, NULL, handle_client, (void *)new_client)) < 0) {
            perror("Thread creation failed");
            return -1;
        }
        printf("New client connected. Client ID: %d\n", client_fd);
    }
    
    close(server_fd);
    return 0;
}
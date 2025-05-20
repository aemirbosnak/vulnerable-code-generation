//FormAI DATASET v1.0 Category: Client Server Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

pthread_mutex_t mutex;

struct client {
    int fd;
    char name[20];
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void send_to_all(char *message, int sender_fd) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].fd != sender_fd) {
            write(clients[i].fd, message, strlen(message));
        }
    }
    pthread_mutex_unlock(&mutex);
}

void *handle_client(void *arg) {
    struct client cl = *(struct client *)arg;
    char message[1024];
    while (true) {
        memset(message, '\0', sizeof(message));
        read(cl.fd, message, sizeof(message));
        if (strlen(message) == 0) {
            printf("%s disconnected\n", cl.name);
            close(cl.fd);
            pthread_exit(NULL);
        }
        printf("%s: %s", cl.name, message);
        send_to_all(message, cl.fd);
    }
}

bool check_name_unique(char *name) {
    for (int i = 0; i < num_clients; i++) {
        if (strcmp(clients[i].name, name) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char name[20];
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Attach socket to given port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the given address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started on port %d\n", PORT);
    
    while (true) {
        // Wait for a client to connect
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        
        memset(name, '\0', sizeof(name));
        read(new_socket, name, sizeof(name));
        
        // Check if name is unique
        if (!check_name_unique(name)) {
            write(new_socket, "Name already taken\n", strlen("Name already taken\n"));
            close(new_socket);
            continue;
        }
        
        // Add new client
        printf("%s connected\n", name);
        struct client cl = {new_socket};
        strcpy(cl.name, name);
        clients[num_clients++] = cl;
        
        write(new_socket, "Welcome to the chat!\n", strlen("Welcome to the chat!\n"));
        
        // Start client handling thread
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, &cl);
    }
    
    return 0;
}
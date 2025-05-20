//FormAI DATASET v1.0 Category: Client Server Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

// Define a struct to hold client information
typedef struct {
    int sock_fd;
    char* name;
} client_info;

// Define a function to handle client messages
void* handle_client(void* arg) {
    client_info* info = (client_info*) arg;
    int sock_fd = info->sock_fd;
    char buffer[1024] = {0};
    while(1) {
        int read_val = read(sock_fd, buffer, 1024);
        if (read_val == 0) {
            printf("%s has left the chat.\n", info->name);
            break;
        }
        printf("%s: %s", info->name, buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    close(sock_fd);
    free(info->name);
    free(info);
    return NULL;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set server socket address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d.\n", PORT);

    // Accept incoming connections in a loop
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Get client name and create new thread to handle client messages
        client_info* info = (client_info*) malloc(sizeof(client_info));
        info->sock_fd = new_socket;
        int read_val = read(new_socket, buffer, 1024);
        info->name = strdup(buffer);
        memset(buffer, 0, sizeof(buffer));
        printf("%s has joined the chat.\n", info->name);
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, (void*) info);
        pthread_detach(tid);
    }

    return 0;
}
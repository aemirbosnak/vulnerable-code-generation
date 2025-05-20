//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

// Function to handle client connections
void *clientHandler(void *client_socket) {
    int sock = *(int *)client_socket;
    char message[] = "Hello, Client! Welcome to our Message of the Day Service.";
    send(sock, message, strlen(message), 0);
    printf("Sent message to client: %s\n", message);
    close(sock);
    free(client_socket);
    return NULL;
}

// Server function
void startServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set sock opt failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, clientHandler, (void*)new_sock);
        pthread_detach(thread_id);
    }
}

// Client function
void startClient() {
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    int sock;
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection to server failed \n");
        return;
    }

    read(sock, buffer, BUFFER_SIZE);
    printf("Received from server: %s\n", buffer);
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <mode>\n<mode> 1 for server, 2 for client\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "1") == 0) {
        startServer();
    } else if (strcmp(argv[1], "2") == 0) {
        sleep(1); // Ensure the server starts first
        startClient();
    } else {
        fprintf(stderr, "Invalid mode. Use 1 for server or 2 for client.\n");
    }

    return 0;
}
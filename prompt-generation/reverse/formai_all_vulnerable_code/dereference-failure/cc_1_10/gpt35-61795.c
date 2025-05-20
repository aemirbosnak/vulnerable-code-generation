//FormAI DATASET v1.0 Category: Networking ; Style: Ken Thompson
/* A simple chat application in C using sockets */
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

/* client thread function */
void *client_thread(void *client_socket) {

    int sock_fd = *(int *)client_socket;
    char message[1024];

    while(1) {
        memset(message, 0, 1024);
        read(sock_fd, message, sizeof(message));   // read message from client

        if(strncmp(message, "quit", 4) == 0) {      // check if client wants to quit
            printf("Client disconnected\n");
            close(sock_fd);             // close socket connection
            pthread_exit(NULL);         // exit thread
        }

        printf("Client says: %s\n", message);
        write(sock_fd, message, strlen(message));  // send message back to client
    }
}

int main() {

    int server_fd, new_socket;
    socklen_t addrlen;
    struct sockaddr_in address, client_addr;
    pthread_t threads[MAX_CLIENTS];

    char *welcome_message = "Welcome to the chat app!";
    char message[1024];

    /* create socket */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    /* configure server address */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(PORT);

    /* bind socket */
    if(bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    /* listen for connections */
    if(listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while(1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addrlen);  // accept client connection

        if(new_socket == -1) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_create(&threads[MAX_CLIENTS], NULL, client_thread, (void *)&new_socket);   // create new thread for client

        write(new_socket, welcome_message, strlen(welcome_message));   // send welcome message to client
    }

    return 0;
}
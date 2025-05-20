//FormAI DATASET v1.0 Category: Networking ; Style: brave
/* This is a networking program that creates a brave chatroom where users can communicate in real-time */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket_ptr) {
    int client_socket = *(int*)client_socket_ptr;
    char buffer[BUFFER_SIZE];
    char user_msg[BUFFER_SIZE];
    ssize_t read_bytes;

    while ((read_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_bytes] = '\0';
        printf("Client says: %s", buffer);

        printf("Enter message to send: ");
        fgets(user_msg, BUFFER_SIZE, stdin);

        send(client_socket, user_msg, strlen(user_msg), 0);
    }

    if (read_bytes == 0) {
        puts("Client disconnected");
    } else {
        perror("recv error");
    }

    close(client_socket);
    free(client_socket_ptr);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);

    /* create server socket */
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    /* fill server address structure */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);

    /* bind the socket to the specified port */
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    /* listen for incoming connections */
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    puts("Server is listening for connections...");

    while (1) {
        /* accept incoming connection */
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size)) == -1) {
            perror("accept error");
            continue;
        }

        /* create a new thread to handle the client connection */
        pthread_t client_thread;
        int *new_socket = malloc(sizeof(int));
        *new_socket = client_socket;

        if (pthread_create(&client_thread, NULL, handle_client, (void*) new_socket) != 0) {
            perror("pthread create error");
            continue;
        }
    }

    return 0;
}
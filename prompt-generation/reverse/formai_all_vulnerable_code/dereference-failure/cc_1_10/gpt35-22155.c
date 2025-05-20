//FormAI DATASET v1.0 Category: Chat server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

void *client_handler(void *socket_desc){

    // Get the socket descriptor of the client
    int client_socket = *(int*)socket_desc;
    int read_size;
    char client_message[2000];

    // Send welcome message to client
    char *server_message = "Welcome to the Chat Server!";
    write(client_socket, server_message, strlen(server_message));

    // Receive messages from client
    while((read_size = recv(client_socket, client_message, 2000, 0)) > 0) {
        printf("Client message: %s\n", client_message);
        // Reply to client
        write(client_socket, client_message, strlen(client_message));
        memset(client_message, 0, sizeof(client_message));
    }

    // Close the socket descriptor
    close(client_socket);

    return 0;
}

int main(int argc, char *argv[]) {

    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;
    pthread_t thread_id;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind socket
    if(bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    puts("Bind done");

    // Listen for incoming connections
    listen(socket_desc, 5);

    // Accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");

        // Create new thread for each client
        new_sock = malloc(1);
        *new_sock = client_sock;
        if(pthread_create(&thread_id, NULL, client_handler, (void*)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }

        puts("Thread created for incoming client");

        // Detach thread to free up resources
        pthread_detach(thread_id);
    }

    if(client_sock < 0) {
        perror("Accept failed");
        return 1;
    }

    return 0;
}
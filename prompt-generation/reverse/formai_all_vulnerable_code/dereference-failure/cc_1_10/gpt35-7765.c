//FormAI DATASET v1.0 Category: Client Server Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *connection_handler(void *);

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket.\n");
        return 1;
    }
    printf("Socket created.\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind failed. Error");
        return 1;
    }
    printf("Bind done.\n");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("Connection accepted.\n");

        new_sock = malloc(1);
        *new_sock = client_sock;

        // Create thread for each client connection
        pthread_t sniffer_thread;
        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) new_sock) < 0) {
            perror("Could not create thread.\n");
            return 1;
        }
    }

    if (client_sock < 0) {
        perror("Accept failed.\n");
        return 1;
    }

    return 0;
}

void *connection_handler(void *sock) {
    int client_sock = *(int *) sock;
    char client_message[2000];

    // Receive message from client
    while (recv(client_sock, client_message, 2000, 0) > 0) {
        printf("Client says: %s\n", client_message);

        // Send message back to client
        write(client_sock, "I AM SHOCKED TOO! WHAT IS HAPPENING?!", strlen("I AM SHOCKED TOO! WHAT IS HAPPENING?!"));
    }

    if (recv(client_sock, client_message, 2000, 0) == 0) {
        puts("Client disconnected.\n");
        fflush(stdout);
    } else if (recv(client_sock, client_message, 2000, 0) < 0) {
        perror("Receive failed.\n");
    }

    // Free socket pointer
    free(sock);

    // Close socket
    close(client_sock);

    return 0;
}
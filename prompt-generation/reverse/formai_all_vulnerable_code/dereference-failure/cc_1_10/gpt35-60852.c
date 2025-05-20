//FormAI DATASET v1.0 Category: Chat server ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *client_handler(void *sock_desc) {

    int sock = *(int*)sock_desc;
    int read_size;
    char client_message[2000];

    while((read_size = recv(sock, client_message, 2000, 0)) > 0 ) {
        // Send the message back to client
        write(sock, client_message, strlen(client_message));
        memset(client_message, 0, sizeof(client_message));
    }
    if(read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if(read_size == -1) {
        perror("recv failed");
    }
    // Free the socket pointer
    free(sock_desc);

    return 0;
}

int main(int argc, char *argv[]) {

    int socket_desc, new_socket, port_number, c, *new_sock;
    struct sockaddr_in server, client;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Set socket to reuse address
    int enable = 1;
    if(setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port_number);

    // Bind
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        return 1;
    }

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    while((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {

        puts("Connection accepted");

        pthread_t sniffer_thread;
        new_sock = malloc(sizeof(int));
        *new_sock = new_socket;

        if(pthread_create(&sniffer_thread, NULL, client_handler, (void*)new_sock) < 0) {
            perror("could not create thread");
            return 1;
        }

        // Join the thread when it is done
        pthread_join(sniffer_thread, NULL);
    }

    if(new_socket < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}
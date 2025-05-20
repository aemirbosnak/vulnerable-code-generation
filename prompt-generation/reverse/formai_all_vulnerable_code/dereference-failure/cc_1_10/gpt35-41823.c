//FormAI DATASET v1.0 Category: Networking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Function to handle incoming connections
void *handle_connection(void *socket_desc) {
    int sock = *(int *)socket_desc;
    int read_size;
    char message[2000] = {0};
    while ((read_size = recv(sock, message, 2000, 0)) > 0) {
        // Echo message back to client
        write(sock, message, strlen(message));
        memset(message, 0, 2000); // Clear message buffer
    }
    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }
    free(socket_desc);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
    // Prepare socket structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    // Bind socket
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        // print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
    // Listen for incoming connections
    listen(socket_desc, 3);
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");
        pthread_t thread_id;
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        // Create thread to handle connection
        if (pthread_create(&thread_id, NULL, handle_connection, (void *)new_sock) < 0) {
            perror("could not create thread");
            return 1;
        }
        pthread_detach(thread_id);
    }
    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }
    return 0;
}
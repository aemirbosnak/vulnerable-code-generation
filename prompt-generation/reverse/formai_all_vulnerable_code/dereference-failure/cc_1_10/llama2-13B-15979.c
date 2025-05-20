//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_info {
    int sock;
    char buffer[BUFFER_SIZE];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    int num_clients = 0;

    // Create the listen socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the listen socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        // Spawn a new process to handle the client
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            close(listen_sock);
            char *message = "Hello, client!";
            send(client_sock, message, strlen(message), 0);
            recv(client_sock, buffer, BUFFER_SIZE, 0);
            printf("Client said: %s\n", buffer);
            exit(0);
        } else {
            // Parent process
            num_clients++;
            struct client_info *client_info = malloc(sizeof(struct client_info));
            client_info->sock = client_sock;
            client_info->buffer[0] = '\0';
            printf("Client %d connected\n", num_clients);
        }
    }

    return 0;
}
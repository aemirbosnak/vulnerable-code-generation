//FormAI DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10

int recursive_listen(int sock, struct sockaddr_in server_addr)
{
    int client_sock;
    pid_t pid;
    socklen_t client_addr_len;
    struct sockaddr_in client_addr;
    char client_ip[INET_ADDRSTRLEN];
    char buffer[1024];

    // Listen for incoming connections
    if (listen(sock, MAX_CONNECTIONS) < 0) {
        perror("Error: could not listen on socket");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening for incoming connections...\n");

    // Accept incoming connections
    client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock < 0) {
        perror("Error: could not accept incoming connection");
        exit(EXIT_FAILURE);
    }

    // Print client IP address and port number
    inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
    printf("Client connected from %s:%d\n", client_ip, ntohs(client_addr.sin_port));

    // Spawn a child process to handle this connection
    pid = fork();
    if (pid < 0) {
        perror("Error: could not create child process");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        close(sock);
        // Read data from client
        while (recv(client_sock, buffer, 1024, 0) > 0) {
            printf("Received message from client: %s", buffer);
            memset(buffer, 0, sizeof(buffer));
            // Echo data back to client
            if (send(client_sock, buffer, strlen(buffer), 0) < 0) {
                perror("Error: could not send message back to client");
            }
        }
        // Close the client socket
        close(client_sock);
        // Exit child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(client_sock);
        // Recursive call to handle next incoming connection
        recursive_listen(sock, server_addr);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    int port = atoi(argv[1]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error: could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address values
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket to server address
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: could not bind socket");
        exit(EXIT_FAILURE);
    }

    // Run recursive listen function to handle incoming connections
    recursive_listen(sock, server_addr);

    // Close the socket
    close(sock);

    return 0;
}
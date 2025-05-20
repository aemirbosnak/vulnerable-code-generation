//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define PORT 8080

typedef struct {
    int sock;
    char name[50];
} client_t;

int main() {
    int listen_sock, conn_sock;
    struct sockaddr_in listen_addr, conn_addr;
    socklen_t client_len = sizeof(listen_addr);
    char buffer[256];

    // Create a listen socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the listen address
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(PORT);

    // Bind the listen socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        client_len = sizeof(conn_addr);
        conn_sock = accept(listen_sock, (struct sockaddr *)&conn_addr, &client_len);
        if (conn_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new process to handle the connection
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            close(listen_sock);
            client_t *client = malloc(sizeof(client_t));
            client->sock = conn_sock;
            client->name[0] = '\0';

            // Read the client's name from the socket
            read(conn_sock, buffer, 255);
            printf("Client %s has connected.\n", buffer);

            // Send a message back to the client
            char *message = "Hello, client!";
            send(conn_sock, message, strlen(message), 0);

            // Close the socket and exit
            close(conn_sock);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            close(conn_sock);
            wait(NULL);
        }
    }

    return 0;
}
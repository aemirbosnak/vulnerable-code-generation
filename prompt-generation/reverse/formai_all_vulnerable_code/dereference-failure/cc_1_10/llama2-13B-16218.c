//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

struct user {
    char *name;
    char *message;
};

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[BUFFER_SIZE];
    struct user *users = NULL;
    int num_users = 0;

    // Create the server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // Add the client to the list of users
        users = realloc(users, (num_users + 1) * sizeof(struct user));
        users[num_users].name = malloc(strlen(client.sin_addr.s_addr) + 1);
        users[num_users].message = malloc(BUFFER_SIZE);
        strcpy(users[num_users].name, inet_ntoa(client.sin_addr));
        memset(users[num_users].message, 0, BUFFER_SIZE);
        num_users++;

        // Loop until the client sends a message or closes the connection
        while (1) {
            // Receive a message from the client
            recv(client_fd, buffer, BUFFER_SIZE, 0);

            // Print the message to the console
            printf("Received message from %s: %s\n", users[num_users - 1].name, buffer);

            // Send the message to all other clients
            for (int i = 0; i < num_users; i++) {
                if (i != num_users - 1) {
                    send(users[i].name, strlen(users[i].name) + 1, 0, users[num_users - 1].name);
                }
            }

            // Check if the client wants to close the connection
            if (strcmp(buffer, "QUIT") == 0) {
                break;
            }
        }

        // Remove the client from the list of users
        num_users--;
        free(users[num_users].name);
        free(users[num_users].message);
        users = realloc(users, num_users * sizeof(struct user));

        // Close the client socket
        close(client_fd);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}
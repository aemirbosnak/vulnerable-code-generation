//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char name[50];
};

int main() {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        new_client->name[0] = '\0';

        // Receive client name
        recv(client_sock, new_client->name, 50, 0);
        printf("New client connected: %s\n", new_client->name);

        // Handle client messages
        while (1) {
            char message[BUFFER_SIZE];
            recv(client_sock, message, BUFFER_SIZE, 0);
            if (message[0] == '/') {
                // Command message
                char *command = message + 1;
                if (strcmp(command, "say") == 0) {
                    char *message = new_client->name;
                    send(client_sock, message, strlen(message), 0);
                } else if (strcmp(command, "hello") == 0) {
                    send(client_sock, "Hello, client!", 13, 0);
                }
            } else {
                // Regular message
                send(client_sock, message, strlen(message), 0);
            }
        }

        // Close client socket
        close(client_sock);
        free(new_client);
    }

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char name[50];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, MAX_CLIENTS);

    while (1) {
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = accept(sock, NULL, NULL);
        printf("New client connected: %s\n", new_client->name);

        // Handle client messages
        while (1) {
            char message[BUFFER_SIZE];
            int bytes_read = read(new_client->sock, message, BUFFER_SIZE);
            if (bytes_read <= 0) break;
            printf("Client message: %s\n", message);

            // Send response to client
            char response[BUFFER_SIZE];
            strcpy(response, "Hello, client!");
            send(new_client->sock, response, strlen(response), 0);
        }

        // Close client socket
        close(new_client->sock);
        free(new_client);
    }

    return 0;
}
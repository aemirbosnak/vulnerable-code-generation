//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LEN 256

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the server socket to all available network interfaces
    bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(listen_sock, MAX_CLIENTS);

    // Accept and create a new socket for each incoming connection
    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        getnameinfo((struct sockaddr *)&client_sock, sizeof(client_sock), new_client->name, sizeof(new_client->name), NULL, 0, NULL);
        printf("New client connected: %s\n", new_client->name);

        // Handle incoming messages from clients
        while (1) {
            char message[MAX_MESSAGE_LEN];
            recv(client_sock, message, MAX_MESSAGE_LEN, 0);
            printf("Received message from %s: %s\n", new_client->name, message);

            // Broadcast the message to all other clients
            int broadcast_sock = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in broadcast_addr = {
                .sin_family = AF_INET,
                .sin_port = htons(1234),
                .sin_addr.s_addr = INADDR_BROADCAST
            };
            connect(broadcast_sock, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr));
            send(broadcast_sock, message, strlen(message), 0);
            close(broadcast_sock);
        }

        // Close the client socket when done
        close(client_sock);
    }

    return 0;
}
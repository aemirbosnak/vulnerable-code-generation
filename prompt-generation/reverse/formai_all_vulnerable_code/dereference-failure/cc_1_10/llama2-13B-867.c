//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MESSAGE_LEN 256

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

    while (1) {
        struct client *client = malloc(sizeof(struct client));
        client->sock = accept(listen_sock, NULL, NULL);
        printf("Client connected: %s\n", client->name);

        while (1) {
            char message[MAX_MESSAGE_LEN];
            read(client->sock, message, MAX_MESSAGE_LEN);
            printf("Received message from %s: %s\n", client->name, message);

            char *message_to_send = "Hello, this is the server!";
            send(client->sock, message_to_send, strlen(message_to_send), 0);
        }

        free(client);
    }

    return 0;
}
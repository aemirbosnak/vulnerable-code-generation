//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 256

struct client {
    int sock;
    char name[50];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    struct client *clients = calloc(MAX_CLIENTS, sizeof(struct client));
    if (!clients) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        struct client *new_client = calloc(1, sizeof(struct client));
        if (!new_client) {
            perror("calloc failed");
            exit(EXIT_FAILURE);
        }

        new_client->sock = client_sock;
        new_client->name[0] = '\0';

        printf("New client connected: %s\n", new_client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int len = read(client_sock, message, MAX_MESSAGE_LENGTH);
            if (len < 0) {
                perror("read failed");
                exit(EXIT_FAILURE);
            }

            message[len] = '\0';

            printf("Received message from %s: %s\n", new_client->name, message);

            if (strcmp(message, "QUIT") == 0) {
                break;
            }

            send(client_sock, "Hello, client!", 13, 0);
        }

        close(client_sock);
        free(new_client);
    }

    return 0;
}
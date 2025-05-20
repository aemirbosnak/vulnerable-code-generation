//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MESSAGE_LENGTH 1024

struct client_t {
    int sock;
    char name[50];
};

int main(void) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
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
        struct client_t *client;
        int client_sock = accept(listen_sock, NULL, NULL);

        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        client = malloc(sizeof(struct client_t));
        client->sock = client_sock;

        printf("New client connected: %s\n", client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int len = recv(client->sock, message, MAX_MESSAGE_LENGTH, 0);

            if (len < 0) {
                perror("recv failed");
                break;
            }

            printf("Received message from %s: %s\n", client->name, message);

            // Process message here...

            send(client->sock, "Hello, client!", 13, 0);
        }

        close(client->sock);
        free(client);
    }

    return 0;
}
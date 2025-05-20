//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1024

struct client {
    int sock;
    char name[50];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct client *client = malloc(sizeof(struct client));

        if ((client->sock = accept(sock, NULL, NULL)) < 0) {
            perror("accept failed");
            free(client);
            continue;
        }

        printf("New client connected (%s)...\n", client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int bytes_read = read(client->sock, message, MAX_MESSAGE_LENGTH);

            if (bytes_read <= 0) {
                break;
            }

            printf("Received message from client: %s\n", message);

            char *message_to_send = "Hello, client!";
            send(client->sock, message_to_send, strlen(message_to_send), 0);
        }

        close(client->sock);
        free(client);
    }

    return 0;
}
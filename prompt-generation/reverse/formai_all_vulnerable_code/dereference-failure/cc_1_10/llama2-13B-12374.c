//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MESSAGE_LENGTH 1024

struct client {
    int sock;
    char name[50];
};

int main(void) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    if (listen(listen_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(1);
    }

    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        new_client->name[0] = '\0';

        printf("New client connected! Name: %s\n", new_client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int len = read(client_sock, message, MAX_MESSAGE_LENGTH);
            if (len < 0) {
                perror("Read failed");
                break;
            }

            printf("Received message from %s: %s\n", new_client->name, message);

            if (strcmp(message, "QUIT") == 0) {
                break;
            }

            char *message_copy = malloc(len + 1);
            strcpy(message_copy, message);
            send(client_sock, message_copy, len, 0);
            free(message_copy);
        }

        close(client_sock);
        free(new_client);
    }

    return 0;
}
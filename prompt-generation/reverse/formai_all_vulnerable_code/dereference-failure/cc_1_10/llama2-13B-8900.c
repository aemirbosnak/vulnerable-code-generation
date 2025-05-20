//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1024

struct client {
    int sock;
    char name[50];
};

int main(void) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    if (listen(listen_sock, 3) < 0) {
        perror("listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", ntohs(server_addr.sin_port));

    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        new_client->name[0] = '\0';

        printf("New client connected: %s\n", new_client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int recv_len = read(new_client->sock, message, MAX_MESSAGE_LENGTH);

            if (recv_len < 0) {
                perror("reading failed");
                break;
            }

            printf("Received message from client: %s\n", message);

            char *message_ptr = message;
            char *message_end = message + recv_len;

            while (message_ptr < message_end) {
                char current_char = *message_ptr;

                if (current_char == '\n') {
                    char *message_part = message_ptr + 1;
                    printf("Part of message: %s\n", message_part);
                    message_ptr = message_part;
                }

                message_ptr++;
            }

            if (message_ptr == message_end) {
                printf("Client disconnected\n");
                break;
            }
        }

        close(new_client->sock);
        free(new_client);
    }

    close(listen_sock);
    return 0;
}
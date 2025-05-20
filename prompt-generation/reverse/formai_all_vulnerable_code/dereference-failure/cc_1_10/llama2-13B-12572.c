//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 256

struct client {
    int sock;
    char name[50];
};

int main(void) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        new_client->name[0] = '\0';

        printf("New client connected! (%s)\n", inet_ntoa(server_addr.sin_addr));

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int recv_len = read(client_sock, message, MAX_MESSAGE_LENGTH);
            if (recv_len < 0) {
                perror("read failed");
                break;
            }
            message[recv_len] = '\0';

            printf("Received message from %s: %s\n", new_client->name, message);

            // Handle the message here, for example:
            // if (strcmp(message, "Hello, server!") == 0) {
            //     printf("Hello, client!%s", new_client->name);
            // }

            send(client_sock, "Hello, client!", 13, 0);
        }

        close(client_sock);
        free(new_client);
    }

    return 0;
}
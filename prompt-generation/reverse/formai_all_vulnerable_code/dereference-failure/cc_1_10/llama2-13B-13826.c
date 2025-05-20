//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MESSAGE_LEN 1024

struct client {
    int sock;
    char name[50];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listening failed");
        exit(1);
    }

    printf("Server started. Listening for clients...\n");

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        struct client *new_client = malloc(sizeof(struct client));

        new_client->sock = client_sock;
        new_client->name[0] = '\0';

        printf("New client connected! Name: %s\n", new_client->name);

        while (1) {
            char message[MAX_MESSAGE_LEN];
            int recv_len = recv(client_sock, message, MAX_MESSAGE_LEN, 0);

            if (recv_len < 0) {
                perror("recv failed");
                break;
            }

            printf("Received message from %s: %s\n", new_client->name, message);

            if (strcmp(message, "QUIT") == 0) {
                break;
            }

            send(client_sock, "Hello, client! :D\n", 13, 0);
        }

        close(client_sock);
        free(new_client);
    }

    close(sock);
    return 0;
}
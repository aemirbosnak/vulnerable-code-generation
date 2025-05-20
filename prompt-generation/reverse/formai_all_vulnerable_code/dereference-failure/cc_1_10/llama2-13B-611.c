//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: brave
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
        perror("Binding failed");
        exit(1);
    }

    if (listen(listen_sock, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Listening for connections...\n");

    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        char name[50];
        printf("New client connected! Name: ");
        fgets(name, 50, stdin);
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        strcpy(new_client->name, name);
        printf("Client %s connected\n", new_client->name);

        while (1) {
            char message[1024];
            printf("Client %s: ", new_client->name);
            fgets(message, 1024, stdin);
            send(new_client->sock, message, strlen(message), 0);

            char buffer[1024];
            recv(new_client->sock, buffer, 1024, 0);
            printf("Client %s: %s\n", new_client->name, buffer);
        }
    }

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MESSAGE_SIZE 1024

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        struct client *client = malloc(sizeof(struct client));
        client->sock = client_sock;

        printf("New client connected! Name: %s\n", client->name);

        while (1) {
            char message[MESSAGE_SIZE];
            int bytes_read = read(client->sock, message, MESSAGE_SIZE);
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

    close(server_sock);
    return 0;
}
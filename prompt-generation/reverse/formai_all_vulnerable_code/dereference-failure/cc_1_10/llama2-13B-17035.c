//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

#define MAX_MESSAGE_LENGTH 1024
#define MAX_CLIENTS 5

struct client_t {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        struct client_t *client = malloc(sizeof(struct client_t));
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("New client connected: %s\n", client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int bytes_read = read(client_sock, message, MAX_MESSAGE_LENGTH);
            if (bytes_read < 0) {
                perror("read failed");
                exit(1);
            }

            if (bytes_read == 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received message from %s: %s\n", client->name, message);

            char send_message[MAX_MESSAGE_LENGTH];
            printf("Sending message to %s: %s\n", client->name, send_message);
            write(client_sock, send_message, strlen(send_message));
        }

        free(client);
    }

    return 0;
}
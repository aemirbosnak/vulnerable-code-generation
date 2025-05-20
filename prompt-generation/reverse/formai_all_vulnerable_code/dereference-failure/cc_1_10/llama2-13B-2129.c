//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

#define MAX_CLIENT_LENGTH 1024
#define MAX_MESSAGE_LENGTH 512

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    listen(server_sock, 3);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Accept failed");
            exit(1);
        }

        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        new_client->name[0] = '\0';

        printf("New client connected! Name: %s\n", new_client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int len = recv(client_sock, message, MAX_MESSAGE_LENGTH, 0);
            if (len < 0) {
                perror("Recv failed");
                exit(1);
            }

            if (strcmp(message, "QUIT") == 0) {
                printf("Client disconnected: %s\n", new_client->name);
                break;
            }

            printf("Client said: %s\n", message);

            char *p = message;
            while (*p != '\0') {
                printf("%c", *p);
                p++;
            }

            printf("\n");

            send(client_sock, "Hello, client!", 13, 0);
        }

        close(client_sock);
        free(new_client);
    }

    return 0;
}
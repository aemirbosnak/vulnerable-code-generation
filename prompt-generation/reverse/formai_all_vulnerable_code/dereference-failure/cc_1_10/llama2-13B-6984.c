//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENT_LENGTH 1024
#define MAX_MESSAGE_LENGTH 256

struct client {
    int sock;
    char name[50];
};

void handle_client(int sock);
void handle_message(int sock, char *message);

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    printf("Listening for clients...\n");

    while (1) {
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = accept(sock, NULL, NULL);
        if (new_client->sock < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("New client connected: %s\n", new_client->name);

        handle_client(new_client->sock);

        free(new_client);
    }

    close(sock);
    return 0;
}

void handle_client(int sock) {
    char name[50];
    char message[MAX_MESSAGE_LENGTH];

    printf("Client connected: %s\n", name);

    while (1) {
        recv(sock, name, 50, 0);
        recv(sock, message, MAX_MESSAGE_LENGTH, 0);

        printf("Client said: %s\n", message);

        handle_message(sock, message);
    }
}

void handle_message(int sock, char *message) {
    char *message_parts[5];
    int i;

    // Parse message into parts
    message_parts[0] = strtok(message, " ");
    for (i = 1; i < 5; i++) {
        message_parts[i] = strtok(NULL, " ");
    }

    // Check if message is a command
    if (strcmp(message_parts[0], "/greet") == 0) {
        printf("Hello, %s!%s\n", message_parts[1], message_parts[2]);
    } else if (strcmp(message_parts[0], "/join") == 0) {
        printf("Welcome to the party, %s!%s\n", message_parts[1], message_parts[2]);
    } else {
        printf("Invalid command. Try /greet or /join.\n");
    }
}
//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_MESSAGE_LENGTH 512

struct client_info {
    int sock;
    char name[MAX_CLIENT_LENGTH];
};

void recv_message(int sock, char *buffer, int buffer_size);
void send_message(int sock, char *message);
void handle_client(int sock);
void handle_message(int sock, char *message);

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 3);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sock = client_sock;

        printf("New client connected: %s\n", client->name);

        while (1) {
            recv_message(client->sock, client->name, MAX_CLIENT_LENGTH);
            handle_message(client->sock, client->name);
        }

        free(client);
    }

    return 0;
}

void recv_message(int sock, char *buffer, int buffer_size) {
    int bytes_received = recv(sock, buffer, buffer_size, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(1);
    }

    char *message = strtok(buffer, "\n");
    while (message != NULL) {
        handle_message(sock, message);
        message = strtok(NULL, "\n");
    }
}

void send_message(int sock, char *message) {
    int bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(1);
    }
}

void handle_client(int sock) {
    char name[MAX_CLIENT_LENGTH];
    recv_message(sock, name, MAX_CLIENT_LENGTH);
    printf("Client %s connected\n", name);
}

void handle_message(int sock, char *message) {
    if (strcmp(message, "QUIT") == 0) {
        printf("Client %s disconnected\n", sock);
        close(sock);
    } else {
        char *message_to_send = malloc(strlen(message) + 1);
        strcpy(message_to_send, message);
        send_message(sock, message_to_send);
    }
}
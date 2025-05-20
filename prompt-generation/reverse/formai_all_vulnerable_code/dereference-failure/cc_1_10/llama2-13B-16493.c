//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_MESSAGE_LENGTH 1024

struct client_info {
    int sock;
    char name[50];
};

void handle_client(int sock);
void handle_message(int sock, char *message);
void accept_client(int listen_sock);
void send_message(int sock, char *message);

int main(int argc, char *argv[]) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(listen_sock, MAX_CLIENT_CONNECTIONS);

    while (1) {
        int client_sock = accept(listen_sock, NULL, NULL);
        struct client_info *client_info = malloc(sizeof(struct client_info));
        client_info->sock = client_sock;
        recvfrom(client_sock, client_info->name, sizeof(client_info->name), 0, NULL, NULL);
        handle_client(client_sock);
        free(client_info);
    }

    return 0;
}

void handle_client(int sock) {
    char message[MAX_MESSAGE_LENGTH];
    int num_bytes = recv(sock, message, MAX_MESSAGE_LENGTH, 0);
    if (num_bytes > 0) {
        handle_message(sock, message);
    }
}

void handle_message(int sock, char *message) {
    char *message_ptr = message;
    char *message_end = message + strlen(message);

    while (message_ptr < message_end) {
        char c = *message_ptr;
        if (c == '>') {
            message_ptr++;
            char *next_message = message_ptr;
            while (message_ptr < message_end && *message_ptr != '>') {
                message_ptr++;
            }
            if (message_ptr < message_end) {
                message_ptr++;
            }
            send_message(sock, next_message);
        } else {
            send_message(sock, message_ptr);
        }
    }
}

void send_message(int sock, char *message) {
    send(sock, message, strlen(message), 0);
}
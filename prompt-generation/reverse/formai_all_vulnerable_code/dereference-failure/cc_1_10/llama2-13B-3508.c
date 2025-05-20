//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_SERVER_LENGTH 2048

struct server_context {
    int sock;
    char buffer[MAX_CLIENT_LENGTH];
};

void handle_client(int sock) {
    char buffer[MAX_SERVER_LENGTH];
    int len = recv(sock, buffer, MAX_SERVER_LENGTH, 0);
    if (len > 0) {
        printf("Client said: %s\n", buffer);
        send(sock, "Hello, client!", 13, 0);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    printf("Listening for incoming connections...\n");

    struct server_context *context = malloc(sizeof(struct server_context));
    context->sock = sock;

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_client(client_sock);
        close(client_sock);
    }

    return 0;
}
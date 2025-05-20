//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct server_info {
    int sock;
    char buffer[1024];
};

void start_server(int sock) {
    char *message = "Welcome to my artistic network!";
    send(sock, message, strlen(message), 0);
}

void handle_client(int sock) {
    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("Client said: %s\n", buffer);
    send(sock, "Thank you for your message!", 14, 0);
}

int main() {
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

    listen(sock, 3);

    struct server_info *server_info = malloc(sizeof(struct server_info));
    server_info->sock = sock;

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_client(client_sock);
        free(server_info);
    }

    return 0;
}
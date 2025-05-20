//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 1024
#define MAX_MESSAGE_LENGTH 1024

struct client_connection {
    int sock;
    char client_ip[16];
    char client_port[6];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, MAX_CLIENT_CONNECTIONS);

    struct client_connection *clients = calloc(MAX_CLIENT_CONNECTIONS, sizeof(struct client_connection));

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        getpeername(client_sock, (struct sockaddr *)&client_addr, &client_len);

        char client_ip[16];
        char client_port[6];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
        strncpy(client_port, &client_addr.sin_port, sizeof(client_port));

        clients = realloc(clients, (MAX_CLIENT_CONNECTIONS + 1) * sizeof(struct client_connection));
        clients[MAX_CLIENT_CONNECTIONS].sock = client_sock;
        strcpy(clients[MAX_CLIENT_CONNECTIONS].client_ip, client_ip);
        strcpy(clients[MAX_CLIENT_CONNECTIONS].client_port, client_port);

        printf("Client connected: %s:%s\n", client_ip, client_port);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            read(client_sock, message, MAX_MESSAGE_LENGTH);
            printf("Received message: %s\n", message);

            char send_message[MAX_MESSAGE_LENGTH];
            strcpy(send_message, "Hello, client!");
            send(client_sock, send_message, strlen(send_message), 0);
        }

        close(client_sock);
    }

    return 0;
}
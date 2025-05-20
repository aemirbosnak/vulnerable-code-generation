//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct client_info {
    int socket;
    char username[256];
};

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[256];
    int n;
    while ((n = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("%s: %s\n", client->username, buffer);
        for (int i = 0; i < 10; i++) {
            if (i == client->socket) {
                continue;
            }
            send(i, buffer, n, 0);
        }
    }
    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_socket, 10) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        char username[256];
        int n = recv(client_socket, username, sizeof(username), 0);
        if (n <= 0) {
            close(client_socket);
            continue;
        }

        struct client_info *client = malloc(sizeof(struct client_info));
        client->socket = client_socket;
        strcpy(client->username, username);

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, client);
    }

    close(server_socket);
    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1024

struct client_data {
    int sock;
    char message[MAX_MESSAGE_LENGTH];
};

void handle_client(int sock) {
    char message[MAX_MESSAGE_LENGTH];
    recv(sock, message, MAX_MESSAGE_LENGTH, 0);
    printf("Client %d said: %s\n", sock, message);

    if (strcmp(message, "QUIT") == 0) {
        close(sock);
        return;
    }

    // Send a response to the client
    char *response = "Hello, client!";
    send(sock, response, strlen(response), 0);

    // Recursively handle more clients
    handle_client(sock);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, MAX_CLIENTS);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        struct client_data *client_data = malloc(sizeof(struct client_data));
        client_data->sock = client_sock;
        handle_client(client_sock);
    }

    return 0;
}
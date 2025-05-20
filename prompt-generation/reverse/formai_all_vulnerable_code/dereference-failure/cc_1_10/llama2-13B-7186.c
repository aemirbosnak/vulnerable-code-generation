//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <net/if.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_MESSAGE_LENGTH 1024

struct client_data {
    int sock;
    char message[MAX_MESSAGE_LENGTH];
};

int main(void) {
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
        struct client_data *client_data = malloc(sizeof(struct client_data));
        client_data->sock = client_sock;

        // Receive message from client
        recv(client_sock, client_data->message, MAX_MESSAGE_LENGTH, 0);

        // Convert message to binary
        char *binary = (char *)malloc(strlen(client_data->message) + 1);
        for (int i = 0; i < strlen(client_data->message); i++) {
            binary[i] = client_data->message[i] - '0';
        }
        binary[strlen(client_data->message)] = '\0';

        // Send binary message to client
        send(client_sock, binary, strlen(binary), 0);

        free(client_data);
    }

    return 0;
}
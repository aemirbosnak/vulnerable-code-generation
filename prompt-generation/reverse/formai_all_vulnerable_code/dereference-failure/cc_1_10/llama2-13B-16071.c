//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_MESSAGE_LENGTH 1024

struct client_data {
    int sock;
    char username[50];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 5);

    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept failed");
        exit(1);
    }

    struct client_data *client_data = malloc(sizeof(struct client_data));
    client_data->sock = client_sock;

    // Read username from client
    char buffer[1024];
    read(client_sock, buffer, 50);
    strcpy(client_data->username, buffer);

    // Echo back the username
    char *username = client_data->username;
    send(client_sock, username, strlen(username), 0);

    // Close the client socket
    close(client_sock);

    // Wait for next client connection
    listen(sock, 5);

    return 0;
}
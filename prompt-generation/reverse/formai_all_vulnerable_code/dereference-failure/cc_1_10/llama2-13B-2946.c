//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MESSAGE_LENGTH 256

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening for clients...\n");

    while (1) {
        struct client *new_client;
        socklen_t client_len = sizeof(struct sockaddr_in);
        int client_sock = accept(sock, (struct sockaddr *)NULL, &client_len);

        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        inet_pton(AF_INET, getnameinfo((struct sockaddr *)&client_sock, sizeof(struct sockaddr_in), NULL, 0, NULL, 0, NULL, 0), new_client->name);

        printf("New client connected: %s\n", new_client->name);

        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int recv_len = recv(new_client->sock, message, MAX_MESSAGE_LENGTH, 0);

            if (recv_len < 0) {
                perror("recv failed");
                break;
            }

            printf("Received message from %s: %s\n", new_client->name, message);

            // Send message to all clients
            int send_len = send(sock, message, recv_len, 0);

            if (send_len < 0) {
                perror("send failed");
                break;
            }
        }

        // Close client socket and free memory
        close(new_client->sock);
        free(new_client);
    }

    return 0;
}
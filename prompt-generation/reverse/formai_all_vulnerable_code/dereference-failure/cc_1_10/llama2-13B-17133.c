//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LEN 1024
#define MAX_PACKET_LEN 512

struct client {
    int sock;
    char name[MAX_CLIENT_LEN];
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
        perror("binding failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    while (1) {
        struct client *client = malloc(sizeof(struct client));
        client->sock = accept(sock, NULL, NULL);
        if (client->sock < 0) {
            perror("accept failed");
            free(client);
            continue;
        }

        char buffer[MAX_PACKET_LEN];
        int bytes_read = read(client->sock, buffer, MAX_PACKET_LEN);
        if (bytes_read < 0) {
            perror("read failed");
            close(client->sock);
            free(client);
            continue;
        }

        printf("Received message from client: %s\n", buffer);

        char *message = "Hello, client!";
        send(client->sock, message, strlen(message), 0);

        free(client);
    }

    close(sock);
    return 0;
}
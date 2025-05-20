//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 100

struct client {
    int sock;
    char name[50];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, MAX_CLIENTS);

    while (1) {
        struct client *new_client;
        new_client = malloc(sizeof(struct client));

        if (accept(sock, (struct sockaddr *)NULL, NULL) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        new_client->sock = sock;
        recvfrom(new_client->sock, (void *)new_client->name, 50, 0, (struct sockaddr *)NULL, NULL);

        printf("New client connected: %s\n", new_client->name);

        while (1) {
            char message[100];
            recvfrom(new_client->sock, message, 100, 0, (struct sockaddr *)NULL, NULL);

            if (strcmp(message, "QUIT") == 0) {
                printf("Client %s disconnected\n", new_client->name);
                break;
            }

            sendto(new_client->sock, message, strlen(message), 0, (struct sockaddr *)NULL, NULL);
        }

        free(new_client);
    }

    return 0;
}
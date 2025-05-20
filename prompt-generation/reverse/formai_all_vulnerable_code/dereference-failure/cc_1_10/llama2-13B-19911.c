//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>

#define PORT 25
#define MAX_CLIENT_LEN 1024
#define MAX_MESSAGE_LEN 512

struct client_info {
    int sock;
    char ip[16];
    char name[64];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    struct client_info *clients = malloc(sizeof(struct client_info) * MAX_CLIENT_LEN);
    int client_count = 0;

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        struct sockaddr_in client_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(PORT),
            .sin_addr.s_addr = getpeername(client_sock, NULL, NULL)
        };

        char message[MAX_MESSAGE_LEN];
        printf("Received message from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle message here

        send(client_sock, "Hello, client!", 13, 0);

        close(client_sock);
    }

    return 0;
}
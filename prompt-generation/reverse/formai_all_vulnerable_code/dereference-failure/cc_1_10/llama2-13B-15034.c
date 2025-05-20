//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define PORT 8080

struct client {
    int sock;
    char name[50];
};

void create_socket(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }
}

void handle_client(int sock) {
    char buffer[256];
    struct client *client = malloc(sizeof(struct client));
    client->sock = sock;
    printf("New client connected! Name: ");
    fgets(client->name, 50, stdin);
    printf("Welcome, %s!\n", client->name);

    while (1) {
        read(sock, buffer, 256);
        printf("%s", buffer);
        if (strcmp(buffer, "QUIT") == 0) {
            break;
        }
        send(sock, "Hello, I received your message!", 22, 0);
    }

    close(sock);
    free(client);
}

void listen_for_clients(void) {
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

    if (listen(sock, 3) < 0) {
        perror("listening failed");
        exit(1);
    }

    printf("Listening for clients...\n");

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_client(client_sock);
    }
}

int main(void) {
    create_socket();
    listen_for_clients();
    return 0;
}
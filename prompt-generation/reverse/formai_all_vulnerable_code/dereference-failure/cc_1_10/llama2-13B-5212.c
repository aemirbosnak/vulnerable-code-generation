//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int sock;
    char *message;
    struct node *next;
};

void create_server(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", port);
}

void handle_client(int sock) {
    char buffer[1024];
    struct node *head = NULL, *curr = NULL;

    while (1) {
        int len = recv(sock, buffer, 1024, 0);
        if (len < 0) {
            perror("recv failed");
            break;
        }

        if (len == 0) {
            break;
        }

        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->sock = sock;
        new_node->message = buffer;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            curr->next = new_node;
            curr = new_node;
        }

        printf("Client message: %s\n", buffer);
    }

    printf("Client disconnected.\n");
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in client_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    create_server(PORT);

    while (1) {
        handle_client(sock);
    }

    return 0;
}
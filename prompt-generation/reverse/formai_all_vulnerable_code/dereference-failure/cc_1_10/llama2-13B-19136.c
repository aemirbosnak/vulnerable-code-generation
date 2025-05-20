//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    char *name;
    char *message;
    struct node *next;
};

struct node *root;

void create_node(char *name, char *message) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->name = name;
    new_node->message = message;
    new_node->next = NULL;
    if (root == NULL) {
        root = new_node;
    } else {
        struct node *current = root;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_node(struct node *node) {
    printf("%s: %s\n", node->name, node->message);
    if (node->next != NULL) {
        print_node(node->next);
    }
}

void chat_server(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];

    while (1) {
        recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&client_addr, &client_len);
        char *message = buffer;
        char *name = strtok(message, " ");
        char *message_rest = strtok(NULL, " ");
        create_node(name, message_rest);
        print_node(root);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock, 3);
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        chat_server(client_sock);
    }
    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int sock;
    char *data;
    size_t len;
    struct node *next;
};

struct node *head = NULL;

void add_node(struct node *node) {
    node->next = head;
    head = node;
}

void remove_node(struct node *node) {
    if (head == node) {
        head = head->next;
    } else {
        struct node *prev = head;
        while (prev->next != node) {
            prev = prev->next;
        }
        prev->next = node->next;
    }
}

int main(int argc, char **argv) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    while (1) {
        struct node *node = malloc(sizeof(struct node));
        node->sock = accept(sock, NULL, NULL);
        if (node->sock < 0) {
            perror("accept failed");
            free(node);
            continue;
        }

        node->data = malloc(1024);
        node->len = read(node->sock, node->data, 1024);
        if (node->len < 0) {
            perror("read failed");
            free(node);
            continue;
        }

        add_node(node);

        // Compression logic goes here
        // ...

        remove_node(node);
        free(node);
    }

    return 0;
}
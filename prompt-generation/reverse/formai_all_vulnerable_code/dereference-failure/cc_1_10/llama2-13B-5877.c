//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

struct node {
    char *name;
    unsigned long long used_ram;
    struct node *next;
};

struct node *head = NULL;

void *malloc_node(size_t size) {
    void *ptr = malloc(size);
    struct node *new_node = (struct node *)ptr;
    new_node->name = (char *)(ptr + size);
    new_node->used_ram = size;
    new_node->next = head;
    head = new_node;
    return ptr;
}

void free_node(void *ptr) {
    struct node *node = (struct node *)ptr;
    node->used_ram = 0;
    node->next = NULL;
    free(node);
}

void *malloc(size_t size) {
    void *ptr = malloc_node(size);
    return ptr;
}

void free(void *ptr) {
    free_node(ptr);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    struct node *node;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    while (1) {
        char buffer[BUFFER_SIZE];
        recv(sock, buffer, BUFFER_SIZE, 0);

        char *token = strtok(buffer, " ");
        long long int ram_used;
        char *end;
        ram_used = strtol(token, &end, 10);

        node = malloc_node(ram_used);
        node->name = token;

        send(sock, node->name, strlen(node->name), 0);

        free(node);
    }

    return 0;
}
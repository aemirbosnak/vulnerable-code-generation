//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyHandler {
    int fd;
    struct ProxyHandler* next;
} ProxyHandler;

ProxyHandler* proxy_handler_insert(int fd, ProxyHandler* head) {
    ProxyHandler* new_handler = malloc(sizeof(ProxyHandler));
    new_handler->fd = fd;
    new_handler->next = head;
    return new_handler;
}

void proxy_handler_remove(ProxyHandler* handler) {
    free(handler);
}

void proxy_handler_process(ProxyHandler* handler) {
    char buffer[MAX_BUFFER_SIZE];
    int read_size, write_size;

    // Read data from client
    read_size = read(handler->fd, buffer, MAX_BUFFER_SIZE);

    // If read successful, write data to server
    if (read_size > 0) {
        write_size = write(handler->fd, buffer, read_size);
        if (write_size < read_size) {
            perror("Error writing to server");
        }
    } else {
        perror("Error reading from client");
    }

    // Close client connection
    close(handler->fd);
    proxy_handler_remove(handler);
}

int main() {
    int listen_fd, client_fd;
    struct sockaddr_in sock_addr;
    ProxyHandler* head = NULL;

    // Listen for client connections
    listen_fd = socket(AF_INET, SOCK_STREAM, htons(8080));
    bind(listen_fd, (struct sockaddr*)&sock_addr, sizeof(sock_addr));

    // Accept client connections
    while (1) {
        client_fd = accept(listen_fd, NULL, NULL);
        proxy_handler_insert(client_fd, head);
        proxy_handler_process(head);
    }

    return 0;
}
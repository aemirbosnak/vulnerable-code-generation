//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct proxy_data {
    int client_sockfd;
    int server_sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct proxy_data *next;
} proxy_data;

proxy_data *proxy_head = NULL;

void add_proxy_data(int client_sockfd, int server_sockfd) {
    proxy_data *new_data = malloc(sizeof(proxy_data));
    new_data->client_sockfd = client_sockfd;
    new_data->server_sockfd = server_sockfd;
    new_data->next = proxy_head;
    proxy_head = new_data;
}

void handle_proxy() {
    proxy_data *current_data = proxy_head;
    while (current_data) {
        // Read data from client
        int client_read_size = read(current_data->client_sockfd, current_data->buffer, MAX_BUFFER_SIZE);

        // If client has closed connection, remove data from list
        if (client_read_size == 0) {
            proxy_data *prev_data = NULL;
            for (proxy_data *iter_data = proxy_head; iter_data; iter_data = iter_data->next) {
                if (iter_data == current_data) {
                    if (prev_data) {
                        prev_data->next = current_data->next;
                    } else {
                        proxy_head = current_data->next;
                    }
                    free(current_data);
                    break;
                }
                prev_data = iter_data;
            }
        } else {
            // Write data to server
            int server_write_size = write(current_data->server_sockfd, current_data->buffer, client_read_size);

            // If server has closed connection, remove data from list
            if (server_write_size == -1) {
                proxy_data *prev_data = NULL;
                for (proxy_data *iter_data = proxy_head; iter_data; iter_data = iter_data->next) {
                    if (iter_data == current_data) {
                        if (prev_data) {
                            prev_data->next = current_data->next;
                        } else {
                            proxy_head = current_data->next;
                        }
                        free(current_data);
                        break;
                    }
                    prev_data = iter_data;
                }
            }
        }
        current_data = current_data->next;
    }
}

int main() {
    // Listen for client connections
    int client_sockfd = listen(8888, 10);

    // Accept client connections
    while (1) {
        int server_sockfd = accept(client_sockfd, NULL, NULL);

        // Add data to list
        add_proxy_data(client_sockfd, server_sockfd);

        // Handle proxy requests
        handle_proxy();
    }

    return 0;
}
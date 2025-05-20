//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct proxy_data {
    int listen_port;
    char *hostname;
    struct proxy_data *next;
} proxy_data;

proxy_data *create_proxy_node(int listen_port, char *hostname) {
    proxy_data *node = malloc(sizeof(proxy_data));
    node->listen_port = listen_port;
    node->hostname = strdup(hostname);
    node->next = NULL;
    return node;
}

void proxy_handler(proxy_data *node, int client_sock) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read = read(client_sock, buffer, MAX_BUFFER_SIZE);
    if (bytes_read > 0) {
        // Forward the request to the backend server
        int server_sock = socket(AF_INET, SOCK_STREAM, htons(80));
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(node->listen_port);
        server_addr.sin_addr.s_addr = inet_addr(node->hostname);

        connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        write(server_sock, buffer, bytes_read);
        read(server_sock, buffer, MAX_BUFFER_SIZE);
        write(client_sock, buffer, bytes_read);

        close(server_sock);
    }
}

int main() {
    // Create a list of proxy nodes
    proxy_data *head = create_proxy_node(8080, "localhost");
    head->next = create_proxy_node(8081, "localhost");

    // Listen for connections on the proxy port
    int listen_sock = socket(AF_INET, SOCK_STREAM, htons(80));
    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(head->listen_port);
    listen_addr.sin_addr.s_addr = htons(INADDR_ANY);

    bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr));

    // Accept connections
    for (;;) {
        int client_sock = accept(listen_sock, NULL, NULL);
        proxy_handler(head, client_sock);
        close(client_sock);
    }

    return 0;
}
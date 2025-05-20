//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CONNECTIONS 10
#define MAX_MESSAGE_LENGTH 256

struct connection {
    int sock;
    char *message;
    struct connection *next;
};

struct server {
    int sock;
    struct connection *connections;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct server *server = malloc(sizeof(struct server));
    server->sock = sock;
    server->connections = NULL;

    // Start listening for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Add the new connection to the list
        struct connection *new_conn = malloc(sizeof(struct connection));
        new_conn->sock = client_sock;
        new_conn->message = malloc(MAX_MESSAGE_LENGTH);
        new_conn->next = NULL;
        if (server->connections == NULL) {
            server->connections = new_conn;
        } else {
            struct connection *last = server->connections;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = new_conn;
        }

        // Handle incoming messages
        while (1) {
            int bytes_read = read(client_sock, new_conn->message, MAX_MESSAGE_LENGTH);
            if (bytes_read < 0) {
                perror("read failed");
                break;
            }
            if (bytes_read == 0) {
                printf("Connection closed by client\n");
                break;
            }
            printf("Received message: %s\n", new_conn->message);

            // Send a response back to the client
            char *response = "Hello, client!";
            send(client_sock, response, strlen(response), 0);
        }

        // Close the connection
        close(client_sock);
    }

    return 0;
}
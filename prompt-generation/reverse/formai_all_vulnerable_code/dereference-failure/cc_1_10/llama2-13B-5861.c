//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONN 1024
#define MAX_PKT 1024

struct conn {
    int sock;
    struct sockaddr_in client_addr;
    char client_name[100];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_PKT];

    // Create the listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the listening address and port
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(8080);

    // Bind the listening socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", listen_addr.sin_port);

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Print the client address and port
        printf("Connected by %s on port %d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new connection structure
        struct conn *conn = (struct conn *)malloc(sizeof(struct conn));
        conn->sock = client_sock;
        conn->client_addr = client_addr;
        strcpy(conn->client_name, "Unknown");

        // Read data from the client
        recv(client_sock, buffer, MAX_PKT, 0);
        printf("Received message from client: %s\n", buffer);

        // Check if the client's message is "HELLO"
        if (strcmp(buffer, "HELLO") == 0) {
            // If the message is "HELLO", allow the connection
            printf("Client %s is allowed to connect\n", conn->client_name);
        } else {
            // If the message is not "HELLO", drop the connection
            printf("Client %s is not allowed to connect\n", conn->client_name);
            close(client_sock);
            free(conn);
        }
    }

    return 0;
}
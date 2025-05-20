//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>

#define PORT 25
#define MAX_CLIENTS 10
#define MAX_MESSAGE_SIZE 1024

struct client_info {
    int sock;
    char name[50];
    char email[50];
};

int main(int argc, char *argv[]) {
    int sock = 0;
    struct client_info clients[MAX_CLIENTS];
    int client_count = 0;

    // Create the email server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific address and port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Email server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Get the client's name and email address
        char *name = NULL;
        char *email = NULL;
        read(client_sock, &name, 50);
        read(client_sock, &email, 50);

        // Add the client to the list of connected clients
        clients[client_count].sock = client_sock;
        strcpy(clients[client_count].name, name);
        strcpy(clients[client_count].email, email);
        client_count++;

        // Handle incoming messages from clients
        while (1) {
            // Receive a message from the client
            char message[1024];
            read(client_sock, message, 1024);

            // Send the message to all connected clients
            for (int i = 0; i < client_count; i++) {
                if (clients[i].sock != client_sock) {
                    send(clients[i].sock, message, strlen(message), 0);
                }
            }
        }
    }

    return 0;
}
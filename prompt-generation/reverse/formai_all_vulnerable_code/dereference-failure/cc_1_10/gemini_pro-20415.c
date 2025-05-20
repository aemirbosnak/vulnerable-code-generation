//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100

struct client_info {
    int socket;
    char name[100];
};

struct client_info clients[MAX_CLIENTS];
int num_clients = 0;

void *client_thread(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[1024];

    while (1) {
        // Receive message from client
        int len = recv(client->socket, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            // Client disconnected
            printf("Client %s disconnected\n", client->name);
            close(client->socket);
            num_clients--;
            break;
        }

        // Process message
        buffer[len] = '\0';
        char *command = strtok(buffer, " ");
        char *message = strtok(NULL, "\0");

        // Handle commands
        if (strcmp(command, "/join") == 0) {
            // Client is joining the chat
            strcpy(client->name, message);
            printf("Client %s joined the chat\n", client->name);
        } else if (strcmp(command, "/leave") == 0) {
            // Client is leaving the chat
            printf("Client %s left the chat\n", client->name);
            close(client->socket);
            num_clients--;
            break;
        } else if (strcmp(command, "/msg") == 0) {
            // Client is sending a message to another client
            char *recipient = strtok(message, " ");
            char *msg = strtok(NULL, "\0");

            // Find the recipient client
            int i;
            for (i = 0; i < num_clients; i++) {
                if (strcmp(clients[i].name, recipient) == 0) {
                    break;
                }
            }

            if (i == num_clients) {
                // Recipient not found
                send(client->socket, "Recipient not found\n", strlen("Recipient not found\n"), 0);
            } else {
                // Send message to recipient
                char buf[1024];
                sprintf(buf, "%s: %s\n", client->name, msg);
                send(clients[i].socket, buf, strlen(buf), 0);
            }
        } else if (strcmp(command, "/list") == 0) {
            // Client is requesting a list of clients
            char buf[1024];
            strcpy(buf, "Clients:\n");

            int i;
            for (i = 0; i < num_clients; i++) {
                strcat(buf, clients[i].name);
                strcat(buf, "\n");
            }

            send(client->socket, buf, strlen(buf), 0);
        } else {
            // Unknown command
            send(client->socket, "Unknown command\n", strlen("Unknown command\n"), 0);
        }
    }

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept incoming connection
        addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a new client thread
        pthread_t thread;
        struct client_info *client = malloc(sizeof(struct client_info));
        client->socket = client_socket;
        pthread_create(&thread, NULL, client_thread, (void *)client);

        // Increment number of clients
        num_clients++;
    }

    // Close server socket
    close(server_socket);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    client_t *cli = (client_t *)arg;

    while ((bytes_received = recv(cli->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received from %s: %s", inet_ntoa(cli->address.sin_addr), buffer);
        
        // Simple Firewall Logic: Block specific messages
        if (strstr(buffer, "BLOCKED") != NULL) {
            printf("Blocked message from %s\n", inet_ntoa(cli->address.sin_addr));
            const char *response = "Your message was blocked.\n";
            send(cli->socket, response, strlen(response), 0);
        } else {
            const char *response = "Message received.\n";
            send(cli->socket, response, strlen(response), 0);
        }
    }

    if (bytes_received == 0) {
        printf("Client %s disconnected.\n", inet_ntoa(cli->address.sin_addr));
    } else if (bytes_received < 0) {
        perror("recv failed");
    }

    close(cli->socket);
    free(cli);
    return NULL;
}

void add_client(client_t *cli) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = cli;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int opt = 1;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_t *cli = malloc(sizeof(client_t));
        socklen_t addr_len = sizeof(cli->address);
        cli->socket = accept(server_socket, (struct sockaddr *)&cli->address, &addr_len);

        if (cli->socket < 0) {
            perror("Accept failed");
            free(cli);
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(cli->address.sin_addr));
        add_client(cli);

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, cli) != 0) {
            perror("Thread creation failed");
            free(cli);
        } else {
            pthread_detach(tid);
        }
    }

    close(server_socket);
    return 0;
}
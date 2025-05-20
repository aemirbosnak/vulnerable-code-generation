//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define QUEUE_SIZE 5
#define BUFFER_SIZE 1024

// Simple structure to hold client information
typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

// Function to determine whether to echo or block message
int check_firewall_rules(char *msg) {
    // Example rule: block messages containing "BLOCK"
    if (strstr(msg, "BLOCK") != NULL) {
        return 0;  // block
    }
    return 1;  // allow
}

// Thread function to handle each client
void *handle_client(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    printf("Connection accepted from %s:%d\n", inet_ntoa(cli->addr.sin_addr), ntohs(cli->addr.sin_port));

    // Handle incoming messages
    while ((read_size = recv(cli->sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';  // Null terminate the received string

        // Check firewall rules
        if (check_firewall_rules(buffer)) {
            printf("Received (Allowed): %s\n", buffer);
            send(cli->sockfd, buffer, read_size, 0);  // Echo the allowed message
        } else {
            printf("Received (Blocked): %s\n", buffer);
        }
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv failed");
    }

    close(cli->sockfd);
    free(cli);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;         // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accepts incoming connections from any IP
    server_addr.sin_port = htons(PORT);        // Port number

    // Bind
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_socket, QUEUE_SIZE) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Firewall listening on port %d...\n", PORT);

    // Accept incoming connections
    while (1) {
        client_t *cli = malloc(sizeof(client_t));
        if ((cli->sockfd = accept(server_socket, (struct sockaddr *)&cli->addr, &client_len)) < 0) {
            perror("Accept failed");
            free(cli);
            continue;
        }

        // Create a thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, cli) != 0) {
            perror("Thread creation failed");
            close(cli->sockfd);
            free(cli);
        } else {
            pthread_detach(thread_id);  // We do not need to join this thread
        }
    }

    close(server_socket);
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 100
#define BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in client_addr;
} client_t;

void *handle_client(void *arg);
void logIP(const char *ip);
int is_allowed_ip(const char *ip);

const char *allowed_ip_list[] = {
    "192.168.1.10",
    "192.168.1.11",
    NULL
};

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                                  (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Create a new thread to handle the client
        client_t *client = malloc(sizeof(client_t));
        client->sockfd = new_socket;
        client->client_addr = address;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)client) != 0) {
            perror("Thread creation failed");
            close(new_socket);
            free(client);
        } else {
            pthread_detach(thread_id); // Automatically reclaim thread resources when done
        }
    }

    close(server_fd);
    return 0;
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE] = {0};
    char client_ip[INET_ADDRSTRLEN];

    // Convert client's IP address to string
    inet_ntop(AF_INET, &(client->client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
    
    // Log the client's IP address
    logIP(client_ip);

    // Check if the client's IP is allowed
    if (!is_allowed_ip(client_ip)) {
        printf("Access denied for IP: %s\n", client_ip);
        const char *message = "HTTP/1.1 403 Forbidden\r\n\r\nAccess Denied.\n";
        send(client->sockfd, message, strlen(message), 0);
        close(client->sockfd);
        free(client);
        return NULL;
    }

    // Accept communication
    const char *welcome_msg = "HTTP/1.1 200 OK\r\n\r\nWelcome to the server!\n";
    send(client->sockfd, welcome_msg, strlen(welcome_msg), 0);

    // Read data from client
    read(client->sockfd, buffer, BUFFER_SIZE);
    printf("Received from %s: %s\n", client_ip, buffer);

    close(client->sockfd);
    free(client);
    return NULL;
}

void logIP(const char *ip) {
    FILE *log_file = fopen("blocked_ips.log", "a");
    if (log_file) {
        fprintf(log_file, "Received connection from: %s\n", ip);
        fclose(log_file);
    }
}

int is_allowed_ip(const char *ip) {
    for (int i = 0; allowed_ip_list[i] != NULL; i++) {
        if (strcmp(ip, allowed_ip_list[i]) == 0) {
            return 1; // IP is allowed
        }
    }
    return 0; // IP is not allowed
}
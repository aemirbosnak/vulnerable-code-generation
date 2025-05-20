//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define IP_BLOCK_LIST_SIZE 10

char *blocked_ips[IP_BLOCK_LIST_SIZE];
int block_count = 0;

pthread_mutex_t block_list_mutex;

void add_to_blocked_ips(const char *ip) {
    pthread_mutex_lock(&block_list_mutex);
    if (block_count < IP_BLOCK_LIST_SIZE) {
        blocked_ips[block_count++] = strdup(ip);
        printf("IP %s added to block list.\n", ip);
    } else {
        printf("Block list is full. Cannot add IP %s.\n", ip);
    }
    pthread_mutex_unlock(&block_list_mutex);
}

int is_ip_blocked(const char *ip) {
    int is_blocked = 0;
    pthread_mutex_lock(&block_list_mutex);
    for (int i = 0; i < block_count; i++) {
        if (strcmp(blocked_ips[i], ip) == 0) {
            is_blocked = 1;
            break;
        }
    }
    pthread_mutex_unlock(&block_list_mutex);
    return is_blocked;
}

void handle_client(int client_socket, struct sockaddr_in client) {
    char buffer[BUFFER_SIZE];
    int read_size;
    char client_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &client.sin_addr, client_ip, sizeof(client_ip));
    printf("Client connected: %s\n", client_ip);

    if (is_ip_blocked(client_ip)) {
        printf("Blocked access to IP: %s\n", client_ip);
        close(client_socket);
        return;
    }

    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received from %s: %s", client_ip, buffer);

        if (strstr(buffer, "BLOCK") != NULL) {
            add_to_blocked_ips(client_ip);
            strcpy(buffer, "You have been blocked!\n");
            send(client_socket, buffer, strlen(buffer), 0);
            break;
        } else {
            send(client_socket, buffer, strlen(buffer), 0); // Echo back
        }
    }

    if (read_size == 0) {
        printf("Client disconnected: %s\n", client_ip);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    pthread_t thread_id;

    // Initialize the mutex
    pthread_mutex_init(&block_list_mutex, NULL);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        return 1;
    }
    printf("Socket created.\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    printf("Bind successful.\n");

    // Listen
    listen(server_socket, MAX_CLIENTS);
    printf("Listening for incoming connections...\n");

    // Accept incoming connections
    while ((client_socket = accept(server_socket, (struct sockaddr*)&client, &client_len))) {
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        if (pthread_create(&thread_id, NULL, (void*)handle_client, (void*)(intptr_t)client_socket) < 0) {
            perror("Could not create thread");
            return 1;
        }
        pthread_detach(thread_id); // Automatically reclaim resources
    }

    if (client_socket < 0) {
        perror("Accept failed");
        return 1;
    }

    close(server_socket);
    pthread_mutex_destroy(&block_list_mutex);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>

// Maximum number of clients to handle at a time
#define MAX_CLIENTS 10

// Structure to store client information
typedef struct client_info {
    int sockfd;
    struct sockaddr_in addr;
} client_info;

// Mutex to protect the shared client list
pthread_mutex_t client_list_mutex = PTHREAD_MUTEX_INITIALIZER;

// List of connected clients
client_info client_list[MAX_CLIENTS];

// Function to handle client connections
void* handle_client(void* arg) {
    client_info* client = (client_info*)arg;

    // Print client information
    char* ip_addr = inet_ntoa(client->addr.sin_addr);
    printf("Client connected: %s:%d\n", ip_addr, ntohs(client->addr.sin_port));

    // Loop until client disconnects
    while (1) {
        // Receive data from client
        char buffer[1024];
        int bytes_received = recv(client->sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            // Client disconnected
            break;
        }

        // Process client data
        time_t current_time = time(NULL);
        char* time_str = ctime(&current_time);
        send(client->sockfd, time_str, strlen(time_str), 0);
    }

    // Close client socket
    close(client->sockfd);

    // Remove client from list
    pthread_mutex_lock(&client_list_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_list[i].sockfd == client->sockfd) {
            client_list[i].sockfd = 0;
            break;
        }
    }
    pthread_mutex_unlock(&client_list_mutex);

    // Print client disconnect message
    printf("Client disconnected: %s:%d\n", ip_addr, ntohs(client->addr.sin_port));

    return NULL;
}

int main(int argc, char** argv) {
    // Create server socket
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server socket options
    int opt = 1;
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind server socket to address
    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    printf("Server listening on port 8080\n");

    // Main server loop
    while (1) {
        // Accept new client connections
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("accept");
            return EXIT_FAILURE;
        }

        // Add client to list
        pthread_mutex_lock(&client_list_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_list[i].sockfd == 0) {
                client_list[i].sockfd = client_sockfd;
                client_list[i].addr = client_addr;
                break;
            }
        }
        pthread_mutex_unlock(&client_list_mutex);

        // Create thread to handle client
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &client_list[client_sockfd]);
    }

    return 0;
}
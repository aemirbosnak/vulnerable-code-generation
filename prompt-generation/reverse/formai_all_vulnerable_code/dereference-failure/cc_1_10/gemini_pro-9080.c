//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10

// Thread argument structure
typedef struct {
    int client_fd;
    char client_name[32];
} thread_arg_t;

// Global variables
int server_fd;
pthread_t client_threads[MAX_CLIENTS];
pthread_mutex_t mutex;

// Function to handle client connections
void *handle_client(void *arg) {
    thread_arg_t *t_arg = (thread_arg_t *)arg;
    int client_fd = t_arg->client_fd;
    char client_name[32] = {0};
    strcpy(client_name, t_arg->client_name);

    // Receive client name
    recv(client_fd, client_name, sizeof(client_name), 0);

    // Send welcome message
    char welcome_msg[128] = {0};
    sprintf(welcome_msg, "Welcome to the server, %s!", client_name);
    send(client_fd, welcome_msg, strlen(welcome_msg), 0);

    // Spam detection loop
    while (1) {
        // Receive message from client
        char msg[1024] = {0};
        recv(client_fd, msg, sizeof(msg), 0);

        // Check for spam
        int is_spam = 0;
        if (strlen(msg) > 100 || strstr(msg, "free money") || strstr(msg, "click here")) {
            is_spam = 1;
        }

        // Send spam status to client
        send(client_fd, &is_spam, sizeof(is_spam), 0);

        // If spam, disconnect client
        if (is_spam) {
            pthread_mutex_lock(&mutex);
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_threads[i] == pthread_self()) {
                    client_threads[i] = 0;
                    break;
                }
            }
            pthread_mutex_unlock(&mutex);
            close(client_fd);
            return NULL;
        }
    }

    return NULL;
}

int main() {
    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind server socket to address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for client connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Main loop
    while (1) {
        // Accept client connection
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        // Find empty thread slot
        int thread_slot = -1;
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_threads[i] == 0) {
                thread_slot = i;
                break;
            }
        }
        pthread_mutex_unlock(&mutex);

        // If no empty thread slot, disconnect client
        if (thread_slot == -1) {
            close(client_fd);
            continue;
        }

        // Create client thread
        thread_arg_t t_arg;
        t_arg.client_fd = client_fd;
        pthread_create(&client_threads[thread_slot], NULL, handle_client, &t_arg);
    }

    // Close server socket
    close(server_fd);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}
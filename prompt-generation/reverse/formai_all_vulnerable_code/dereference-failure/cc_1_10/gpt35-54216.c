//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define MAX_THREADS 10

// Function prototypes
void *client_handler(void *);

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[MAX_THREADS];
    int thread_index = 0;

    // Check if port number is provided
    if (argc < 2) {
        printf("Usage: %s [port]\n", argv[0]);
        return 1;
    }

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    // Set server address
    bzero(&server_addr, sizeof(server_addr));
    port = atoi(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not bind socket to address.\n");
        return 1;
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    printf("Server running on port %d.\n", port);

    while (1) {
        socklen_t client_len = sizeof(client_addr);

        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            printf("Error: Could not accept incoming connection.\n");
            continue;
        }

        // Start new thread for client
        if (pthread_create(&threads[thread_index], NULL, client_handler, (void *)&client_socket) != 0) {
            printf("Error: Failed to create thread for client.\n");
            close(client_socket);
        }

        // Increase thread index
        thread_index++;

        // Check if maximum threads reached
        if (thread_index >= MAX_THREADS) {
            thread_index = 0;
            while (pthread_join(threads[thread_index], NULL) != 0) {
                thread_index++;
                if (thread_index >= MAX_THREADS) {
                    thread_index = 0;
                }
            }
        }
    }

    return 0;
}

void *client_handler(void *arg) {
    int socket = *(int *)arg;
    char buffer[MAX_BUFFER];
    char response[] = "OK\n";
    int n;

    printf("Handling client on thread %ld\n", pthread_self());

    // Communicate with client
    while ((n = read(socket, buffer, MAX_BUFFER)) > 0) {
        buffer[n] = '\0';
        printf("Received message: %s", buffer);
        write(socket, response, strlen(response));
    }

    // Close socket
    close(socket);

    return NULL;
}
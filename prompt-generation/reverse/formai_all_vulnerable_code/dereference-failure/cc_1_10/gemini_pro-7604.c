//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

// Thread argument structure
struct thread_args {
    int sockfd;
    struct sockaddr_in client_addr;
};

// Thread function to handle client connections
void* handle_client(void* arg) {
    struct thread_args* args = (struct thread_args*)arg;
    int sockfd = args->sockfd;
    struct sockaddr_in client_addr = args->client_addr;

    // Receive message from client
    char buffer[1024];
    int recv_len = recv(sockfd, buffer, sizeof(buffer), 0);
    if (recv_len < 0) {
        perror("Receive failed");
        close(sockfd);
        free(args);
        pthread_exit(NULL);
    }

    // Process message
    printf("Received message from client: %s\n", buffer);
    char response[] = "Hello from server";

    // Send response to client
    int send_len = send(sockfd, response, sizeof(response), 0);
    if (send_len < 0) {
        perror("Send failed");
        close(sockfd);
        free(args);
        pthread_exit(NULL);
    }

    // Close client socket
    close(sockfd);
    free(args);
    pthread_exit(NULL);
}

int main() {
    int serverfd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[MAX_CONNECTIONS];
    int num_connections = 0;

    // Create server socket
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    int opt = 1;
    if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(serverfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(serverfd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept client connections in a loop
    while (1) {
        int addr_len = sizeof(client_addr);
        int clientfd = accept(serverfd, (struct sockaddr*)&client_addr, &addr_len);
        if (clientfd < 0) {
            perror("Accept failed");
            continue;
        }

        // Create thread to handle client connection
        if (num_connections < MAX_CONNECTIONS) {
            pthread_t thread;
            struct thread_args* args = malloc(sizeof(struct thread_args));
            args->sockfd = clientfd;
            args->client_addr = client_addr;
            if (pthread_create(&thread, NULL, handle_client, (void*)args) < 0) {
                perror("Thread creation failed");
                close(clientfd);
                continue;
            }
            pthread_join(thread, NULL);
            num_connections--;
        } else {
            // Send error message to client
            char error[] = "Server is busy. Please try again later.";
            send(clientfd, error, sizeof(error), 0);
            close(clientfd);
        }
    }

    close(serverfd);
    return 0;
}
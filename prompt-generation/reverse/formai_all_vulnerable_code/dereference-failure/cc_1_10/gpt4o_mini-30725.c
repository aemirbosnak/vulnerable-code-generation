//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define BUF_SIZE 1024
#define MAX_CONNECTIONS 10

// Structure to hold the IP address and the count of requests
typedef struct {
    char ip[INET_ADDRSTRLEN];
    int count;
} Request;

// Creating a global array to track requests
Request requestLog[MAX_CONNECTIONS];
int requestCount = 0;
pthread_mutex_t lock;

// Function to log requests
void log_request(const char *ip) {
    pthread_mutex_lock(&lock);
    int found = 0;

    // Check if IP is already logged
    for (int i = 0; i < requestCount; i++) {
        if (strcmp(requestLog[i].ip, ip) == 0) {
            requestLog[i].count++;
            found = 1;
            break;
        }
    }

    // If the IP is not found, add it to the log
    if (!found && requestCount < MAX_CONNECTIONS) {
        strcpy(requestLog[requestCount].ip, ip);
        requestLog[requestCount].count = 1;
        requestCount++;
    }

    // Simple detection: Block IP if requests exceed a threshold
    if (requestCount > 0) {
        for (int i = 0; i < requestCount; i++) {
            if (requestLog[i].count > 5) { // Threshold
                printf("Warning: IP %s has exceeded the request limit.\n", requestLog[i].ip);
            }
        }
    }
    pthread_mutex_unlock(&lock);
}

// Function to handle each incoming connection
void *handle_connection(void *arg) {
    int new_socket = *((int *)arg);
    free(arg);
    
    char buffer[BUF_SIZE] = {0};
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    // Get client IP addr
    getpeername(new_socket, (struct sockaddr *)&addr, &addr_len);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &addr.sin_addr, ip, sizeof(ip));

    // Log the request
    log_request(ip);

    // Respond to the client
    const char *message = "Hello from the Intrusion Detection System!";
    send(new_socket, message, strlen(message), 0);
    
    // Close the connection
    close(new_socket);
    return NULL;
}

int main() {
    int server_fd, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        int *new_socket = malloc(sizeof(int));
        if ((*new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept");
            free(new_socket);
            continue;
        }
        
        // Create a new thread for each connection
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_connection, new_socket) != 0) {
            perror("Failed to create thread");
            free(new_socket);
        }
        pthread_detach(thread_id); // Detach thread to reclaim resources on termination
    }

    // Cleanup (not reachable in this code)
    pthread_mutex_destroy(&lock);
    close(server_fd);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
// Building a Decentralized HTTP Client using C Threads and Sockets

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define thread arguments
typedef struct thread_args {
    char *hostname;
    int port;
    char *path;
} thread_args_t;

// Forward declarations
void *client_thread(void *arg);

// Main function
int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <path> [num-threads]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *path = argv[3];
    int num_threads = (argc >= 5) ? atoi(argv[4]) : 1;

    // Create thread pool
    pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));

    // Create thread arguments
    thread_args_t *args = (thread_args_t *)malloc(num_threads * sizeof(thread_args_t));
    for (int i = 0; i < num_threads; i++) {
        args[i].hostname = hostname;
        args[i].port = port;
        args[i].path = path;
    }

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, client_thread, &args[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}

// Client thread function
void *client_thread(void *arg) {
    // Cast argument
    thread_args_t *args = (thread_args_t *)arg;

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(args->port);
    servaddr.sin_addr.s_addr = inet_addr(args->hostname);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Prepare request
    char request[512];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", args->path, args->hostname);

    // Send request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response
    char response[4096];
    memset(response, 0, sizeof(response));
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print response
    printf("%s\n", response);

    // Close socket
    close(sockfd);

    return NULL;
}
//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

// HTTP request header template
#define HTTP_REQUEST "GET /%s HTTP/1.1\r\n" \
                     "Host: %s\r\n" \
                     "Connection: close\r\n" \
                     "\r\n"

// Maximum number of concurrent connections
#define MAX_CONNECTIONS 10

// Thread data structure
typedef struct {
    int sockfd;
    char *host;
    char *path;
} thread_data;

// Function to send HTTP request
void send_request(int sockfd, char *host, char *path) {
    // Create HTTP request header
    char request[512];
    snprintf(request, sizeof(request), HTTP_REQUEST, path, host);

    // Send HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        close(sockfd);
        return;
    }
}

// Function to receive HTTP response
void receive_response(int sockfd) {
    // Buffer for HTTP response
    char buffer[1024];

    // Receive HTTP response
    while (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        // Print HTTP response
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);
}

// Thread function
void *thread_function(void *arg) {
    // Get thread data
    thread_data *data = (thread_data *)arg;

    // Send HTTP request
    send_request(data->sockfd, data->host, data->path);

    // Receive HTTP response
    receive_response(data->sockfd);

    // Free thread data
    free(data);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s host path\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get host and path from command line arguments
    char *host = argv[1];
    char *path = argv[2];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve host name
    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Connect to host
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *(struct in_addr *)host_entry->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Create thread pool
    pthread_t threads[MAX_CONNECTIONS];
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        // Create thread data
        thread_data *data = malloc(sizeof(thread_data));
        data->sockfd = sockfd;
        data->host = host;
        data->path = path;

        // Create thread
        if (pthread_create(&threads[i], NULL, thread_function, data) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}
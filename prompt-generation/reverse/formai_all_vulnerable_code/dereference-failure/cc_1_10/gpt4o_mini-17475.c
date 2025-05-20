//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define BUFFER_SIZE 4096

void *send_request(void *url) {
    char *whole_url = (char *)url;
    char hostname[1024], path[1024];
    int port = 80;
    
    // Parse the URL
    if (sscanf(whole_url, "http://%1023[^/]/%1023[^\n]", hostname, path) != 2) {
        fprintf(stderr, "Failed to parse URL: %s\n", whole_url);
        return NULL;
    }

    struct sockaddr_in server_addr;
    struct hostent *host_info = gethostbyname(hostname);
    
    if (!host_info) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", hostname);
        return NULL;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return NULL;
    }

    // Send HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    send(sockfd, request, strlen(request), 0);

    // Receive the response
    char response[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate received data
        printf("%s", response); // Print response to standard output
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    }

    close(sockfd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <http://hostname/path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, send_request, (void *)argv[1]) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }

    // Wait for the thread to finish
    pthread_join(thread_id, NULL);
    return 0;
}
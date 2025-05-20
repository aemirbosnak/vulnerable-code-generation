//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 4096

void draw_header(const char *title) {
    printf("\n");
    printf("=======================================\n");
    printf("           %s            \n", title);
    printf("=======================================\n");
}

void http_client(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_entry;
    char request[MAX_BUFFER];
    char response[MAX_BUFFER];
    
    // Getting the server IP address
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Filling server information
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr, host_entry->h_length);
    server_addr.sin_port = htons(80);

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Crafting the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    // Sending request
    send(sockfd, request, strlen(request), 0);
    
    draw_header("HTTP Response");
    // Receiving the response
    int total_bytes_received = 0;
    int bytes_received;
    
    while ((bytes_received = recv(sockfd, response + total_bytes_received, MAX_BUFFER - total_bytes_received - 1, 0)) > 0) {
        total_bytes_received += bytes_received;
    }
    
    if (bytes_received < 0) {
        perror("Error in receiving response");
    }

    // Null-terminate the response
    response[total_bytes_received] = '\0';

    // Printing the response
    printf("%s\n", response);

    // Cleanup
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    http_client(hostname, path);
    
    return EXIT_SUCCESS;
}
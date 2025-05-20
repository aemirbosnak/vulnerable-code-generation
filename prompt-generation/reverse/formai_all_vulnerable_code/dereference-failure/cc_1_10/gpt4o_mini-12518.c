//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define PORT 80
#define MAX_URL_LENGTH 256
#define METHOD "GET"

void print_http_response(const char *response) {
    printf("\n--- HTTP RESPONSE ---\n");
    printf("%s\n", response);
    printf("----------------------\n");
}

char *get_http_response(int sock) {
    char *response = malloc(BUFFER_SIZE);
    if (response == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    ssize_t bytes_received;
    size_t total_received = 0;

    while ((bytes_received = recv(sock, response + total_received, BUFFER_SIZE - total_received - 1, 0)) > 0) {
        total_received += bytes_received;
        if (total_received >= BUFFER_SIZE - 1) {
            break; // Buffer is full
        }
    }

    if (bytes_received < 0) {
        perror("Error receiving data");
    }
    
    response[total_received] = '\0'; // Null-terminate the string
    return response;
}

void send_http_request(int sock, const char *url) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", 
             METHOD, url, url);
    
    send(sock, request, strlen(request), 0);
}

void connect_to_server(const char *hostname, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    send_http_request(sock, "/");
    char *response = get_http_response(sock);
    print_http_response(response);
    
    free(response);
    close(sock);
}

void parse_url(const char *url, char *hostname) {
    const char *http = "http://";
    if (strncmp(url, http, strlen(http)) == 0) {
        url += strlen(http);
    }

    char *slash = strchr(url, '/');
    if (slash != NULL) {
        strncpy(hostname, url, slash - url);
        hostname[slash - url] = '\0';
    } else {
        strcpy(hostname, url);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char hostname[MAX_URL_LENGTH];
    parse_url(argv[1], hostname);

    printf("Connecting to %s...\n", hostname);
    connect_to_server(hostname, PORT);

    return EXIT_SUCCESS;
}
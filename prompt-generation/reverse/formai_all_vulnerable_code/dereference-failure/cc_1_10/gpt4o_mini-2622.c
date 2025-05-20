//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFSIZE 1024
#define MAX_URL_SIZE 256
#define HTTP_GET "GET"
#define HTTP_VERSION "HTTP/1.1"

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void parse_url(const char *url, char *hostname, char *path) {
    char *start = strstr(url, "://");
    if (start) {
        start += 3; // Skip over "://"
    } else {
        start = (char *)url; // No protocol specified
    }

    char *slash = strchr(start, '/');
    if (slash) {
        strncpy(hostname, start, slash - start);
        hostname[slash - start] = '\0';
        strcpy(path, slash); // Keep the leading '/'
    } else {
        strcpy(hostname, start);
        path[0] = '/';
        path[1] = '\0'; // Default path to root
    }
}

void send_http_get_request(int sock, const char *hostname, const char *path) {
    char request[BUFSIZE];
    snprintf(request, sizeof(request), "%s %s %s\r\nHost: %s\r\nConnection: close\r\n\r\n",
             HTTP_GET, path, HTTP_VERSION, hostname);
    
    if (send(sock, request, strlen(request), 0) < 0) {
        handle_error("Send failed");
    }
}

void receive_http_response(int sock) {
    char buffer[BUFSIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received data
        printf("%s", buffer); // Print the response to stdout
    }

    if (bytes_received < 0) {
        handle_error("Receive failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char hostname[MAX_URL_SIZE];
    char path[MAX_URL_SIZE];

    parse_url(argv[1], hostname, path);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Socket creation failed");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with actual IP resolution logic

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    send_http_get_request(sock, hostname, path);
    receive_http_response(sock);

    close(sock);
    return EXIT_SUCCESS;
}
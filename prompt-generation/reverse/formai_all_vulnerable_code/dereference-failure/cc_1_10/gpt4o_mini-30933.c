//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 4096

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void parse_url(const char *url, char *hostname, char *path) {
    char *start = strstr(url, "://");  // Check for protocol
    if (start) {
        start += 3; // Jump over "://"
    } else {
        start = (char *)url; // No protocol
    }

    char *slash_pos = strchr(start, '/');
    if (slash_pos) {
        strncpy(hostname, start, slash_pos - start);
        hostname[slash_pos - start] = '\0';
        strcpy(path, slash_pos); // Copy the path
    } else {
        strcpy(hostname, start);
        strcpy(path, "/"); // Default to root path
    }
}

int create_socket(const char *hostname, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("socket creation failed");
    }

    struct hostent *host_info = gethostbyname(hostname);
    if (!host_info) {
        handle_error("could not resolve hostname");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr_list[0], host_info->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connection to server failed");
    }

    return sock;
}

void send_http_request(int sock, const char *hostname, const char *path) {
    char request[MAX_BUFFER];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",
             path, hostname);
    
    write(sock, request, strlen(request));
}

void receive_http_response(int sock) {
    char buffer[MAX_BUFFER];
    ssize_t bytes_received;

    while ((bytes_received = read(sock, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        handle_error("error reading response");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char hostname[256];
    char path[256];

    parse_url(argv[1], hostname, path);
    printf("Parsed URL:\nHostname: %s\nPath: %s\n", hostname, path);

    int sock = create_socket(hostname, 80);
    send_http_request(sock, hostname, path);
    receive_http_response(sock);

    close(sock);
    return 0;
}
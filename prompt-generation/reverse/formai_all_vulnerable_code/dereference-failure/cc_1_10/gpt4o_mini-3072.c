//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 8192

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_http_client_socket(const char *host, int port) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host_entry;

    // Resolve hostname to IP address
    host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        error_handling("gethostbyname() failed");
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error_handling("socket() failed");
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr_list[0], host_entry->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sock);
        error_handling("connect() failed");
    }

    return sock;
}

void send_http_request(int sock, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, host);
    
    if (send(sock, request, strlen(request), 0) < 0) {
        error_handling("send() failed");
    }
}

void receive_http_response(int sock) {
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the string
        printf("%s", response); // Print the response to STDOUT
    }

    if (bytes_received < 0) {
        error_handling("recv() failed");
    }
}

void close_http_client_socket(int sock) {
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    int port = 80;  // HTTP default port
    int sock = create_http_client_socket(host, port);

    send_http_request(sock, host, path);
    receive_http_response(sock);
    close_http_client_socket(sock);

    return EXIT_SUCCESS;
}
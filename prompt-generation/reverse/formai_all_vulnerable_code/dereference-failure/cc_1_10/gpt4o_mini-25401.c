//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void build_http_request(const char *hostname, const char *path, char *request) {
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
}

void parse_http_response(char *response) {
    char *line = strtok(response, "\r\n");
    while (line != NULL) {
        printf("%s\n", line);
        line = strtok(NULL, "\r\n");
    }
}

int create_socket(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        error("Could not resolve hostname");
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Could not create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Could not connect to server");
    }

    return sock;
}

void send_request(int sock, const char *request) {
    if (send(sock, request, strlen(request), 0) < 0) {
        error("Error sending request");
    }
}

void receive_response(int sock) {
    char response[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';  // Null terminate the received data
        parse_http_response(response);
    }

    if (bytes_received < 0) {
        error("Error receiving response");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    char request[BUFFER_SIZE];

    int sock = create_socket(hostname, 80);
    build_http_request(hostname, path, request);
    send_request(sock, request);
    receive_response(sock);

    close(sock);
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 2048

void serenade(const char *intimateMessage) {
    printf("%s\n\n", intimateMessage);
}

void compose_request(char *request_buffer, const char *host, const char *path) {
    sprintf(request_buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
}

int establish_connection(const char *host, int port) {
    struct hostent *server;
    struct sockaddr_in server_address;
    int socket_fd;

    // Fall in love with a host
    server = gethostbyname(host);
    if (server == NULL) {
        serenade("Oh love! The host is lost among the clouds!");
        exit(EXIT_FAILURE);
    }

    // Embrace the connection
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        serenade("Alas, my heart aches! The socket creation has failed.");
        exit(EXIT_FAILURE);
    }

    memset((char *)&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    server_address.sin_port = htons(port);

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        serenade("Oh dear, our connection has been thwarted!");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

void send_request(int socket_fd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    compose_request(request, host, path);
    serenade("With a trembling heart, I send my fervent request:");
    printf("%s\n", request);
    
    write(socket_fd, request, strlen(request));
}

void receive_response(int socket_fd) {
    char response[BUFFER_SIZE];
    serenade("Awaiting the response from my beloved...");

    while (1) {
        memset(response, 0, BUFFER_SIZE);
        ssize_t bytes_received = read(socket_fd, response, BUFFER_SIZE - 1);
        if (bytes_received <= 0) {
            break; // No more data or error
        }
        printf("%s", response);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        serenade("Oh sweet love, please provide the host and path!");
        printf("Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *path = argv[2];
    
    serenade("Oh darling, I shall now reach out across the network,");
    serenade("To send you a heartfelt request! Let's see if you respond...");

    int socket_fd = establish_connection(host, 80);
    send_request(socket_fd, host, path);
    receive_response(socket_fd);

    serenade("Our connection has drawn to a close,");
    serenade("But know that I will always cherish this moment.");
    
    close(socket_fd);
    return EXIT_SUCCESS;
}
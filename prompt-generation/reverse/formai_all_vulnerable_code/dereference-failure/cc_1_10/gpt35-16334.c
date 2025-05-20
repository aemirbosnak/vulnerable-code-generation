//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    char server_hostname[256] = "www.example.com";
    int server_port = 80;
    char request_message[1024];
    char response_buffer[1024];

    struct hostent *server_info = gethostbyname(server_hostname);
    if (server_info == NULL) {
        printf("Error: could not find host '%s'\n", server_hostname);
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server_info->h_addr, server_info->h_length);
    server_address.sin_port = htons(server_port);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    sprintf(request_message, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", server_hostname);
    int bytes_sent = send(socket_fd, request_message, strlen(request_message), 0);
    if (bytes_sent < 0) {
        printf("Error: could not send request\n");
        exit(1);
    }

    int total_bytes_received = 0;
    int bytes_received = 0;
    while ((bytes_received = recv(socket_fd, response_buffer, sizeof(response_buffer), 0)) > 0) {
        total_bytes_received += bytes_received;
        printf("Received %d bytes:\n", bytes_received);
        printf("%.*s", bytes_received, response_buffer);
        memset(response_buffer, 0, sizeof(response_buffer));
    }

    printf("Total bytes received: %d\n", total_bytes_received);

    close(socket_fd);

    return 0;
}
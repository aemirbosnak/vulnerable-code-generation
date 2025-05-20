//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 4) {
        printf("Usage: %s <host> <port> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get host and port
    char *host = argv[1];
    int port = atoi(argv[2]);
    char *path = argv[3];

    // Create TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get IP address
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        fprintf(stderr, "Unknown host %s\n", host);
        exit(EXIT_FAILURE);
    }
    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    struct in_addr addr = *addr_list[0];

    // Connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = addr.s_addr;
    server_addr.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send GET request
    char *request_fmt = "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request[strlen(request_fmt) + strlen(host) + strlen(path)];
    sprintf(request, request_fmt, path, host);
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response
    char response_buff[BUFF_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(sock, response_buff, BUFF_SIZE - 1, 0)) > 0) {
        response_buff[bytes_received] = '\0';
        printf("%s", response_buff);
    }

    // Close socket
    close(sock);

    return 0;
}
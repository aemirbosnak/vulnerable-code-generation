//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: protected
// Example HTTP Client program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_address> <port_number> <request_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    int port_number = atoi(argv[2]);
    char *request_path = argv[3];

    // Create and connect socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_number);
    if(inet_pton(AF_INET, server_address, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Send HTTP GET request
    char request[BUFF_SIZE];
    snprintf(request, BUFF_SIZE - 1, "GET %s HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\n\r\n",
             request_path, server_address, port_number);
    int bytes_sent = send(sock, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    char response[BUFF_SIZE];
    int bytes_received = recv(sock, response, BUFF_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    response[bytes_received] = '\0';

    // Print HTTP response
    printf("HTTP Response:\n%s\n", response);
    
    // Close socket
    close(sock);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_error("Invalid number of arguments");
    }

    char* host = argv[1];
    char* port = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        print_error("Failed to create socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));

    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        print_error("Invalid host or port");
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("Failed to connect to server");
    }

    char buffer[BUFFER_SIZE];
    send(sockfd, "PING", strlen("PING"), 0);

    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        print_error("Failed to receive response from server");
    }

    buffer[bytes_received] = '\0';

    if (strcmp(buffer, "PONG")!= 0) {
        print_error("Server did not respond with PONG");
    }

    close(sockfd);

    return 0;
}
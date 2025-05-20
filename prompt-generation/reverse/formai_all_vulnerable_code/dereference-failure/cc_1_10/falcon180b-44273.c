//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip address> <port number>\n", argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    int port_number = atoi(argv[2]);

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip_address, NULL, &hints, &result)!= 0) {
        print_error("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        print_error("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        print_error("connect");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (send(sockfd, "PING", strlen("PING"), 0) == -1) {
        print_error("send");
    }

    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        int result = recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }

    buffer[bytes_received] = '\0';
    printf("Received response: %s\n", buffer);

    close(sockfd);
    freeaddrinfo(result);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[1024];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        print_error("Failed to resolve hostname");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        print_error("Failed to create socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        print_error("Failed to connect to host");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}
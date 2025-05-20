//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 5
#define SLEEP_TIME 1000

void print_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int ping(const char* hostname) {
    struct addrinfo hints;
    struct addrinfo* result;
    int sockfd = -1;
    int status = 0;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        print_error("getaddrinfo");
        return -1;
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        print_error("socket");
        return -1;
    }

    for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
        if (connect(sockfd, result->ai_addr, result->ai_addrlen) == 0) {
            status = 0;
            break;
        }

        close(sockfd);
        usleep(SLEEP_TIME);

        if (attempt == MAX_ATTEMPTS - 1) {
            status = -1;
            break;
        }

        if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
            print_error("getaddrinfo");
            return -1;
        }

        sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (sockfd == -1) {
            print_error("socket");
            return -1;
        }
    }

    close(sockfd);
    freeaddrinfo(result);

    return status;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char hostname[1024];
    strncpy(hostname, argv[1], sizeof(hostname) - 1);

    int status = ping(hostname);

    if (status == 0) {
        printf("%s is reachable\n", hostname);
    } else {
        printf("%s is unreachable\n", hostname);
    }

    return status;
}
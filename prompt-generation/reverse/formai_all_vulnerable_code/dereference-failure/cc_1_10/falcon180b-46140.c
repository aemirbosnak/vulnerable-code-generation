//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [IP Address]\n", argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    struct addrinfo hints, *result;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip_address, NULL, &hints, &result)!= 0) {
        die("getaddrinfo");
    }

    int sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (sock == -1) {
        die("socket");
    }

    freeaddrinfo(result);

    for (int i = 1; i <= MAX_PORTS; i++) {
        int port = htons(i);
        if (connect(sock, (struct sockaddr*)&(result->ai_addr), result->ai_addrlen) == 0) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    close(sock);
    return 0;
}
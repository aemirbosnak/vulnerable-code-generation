//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_TRIES 5
#define TIMEOUT 5000
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <website> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *website = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, website, &server_addr.sin_addr) <= 0) {
        die("Invalid address/ Address not supported");
    }

    int retries = 0;
    int connected = 0;

    while (retries < MAX_TRIES) {
        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            close(sockfd);
            usleep(TIMEOUT);
            retries++;
            continue;
        }

        connected = 1;
        break;
    }

    if (!connected) {
        fprintf(stderr, "Failed to connect to %s:%d after %d attempts\n", website, port, MAX_TRIES);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t n = recv(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL);
    if (n <= 0) {
        fprintf(stderr, "Failed to receive data from %s:%d\n", website, port);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Received %ld bytes from %s:%d:\n%.*s\n", n, website, port, (int)n, buffer);

    close(sockfd);
    return EXIT_SUCCESS;
}
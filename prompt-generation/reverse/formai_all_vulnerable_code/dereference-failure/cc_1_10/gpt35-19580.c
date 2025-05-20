//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <remote_host> <remote_port>\n", argv[0]);
        return 1;
    }

    char *remote_host = argv[1];
    int remote_port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(remote_host);
    remote_addr.sin_port = htons(remote_port);

    if (connect(sockfd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
        error("ERROR connecting to remote host");
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
            error("ERROR writing to stdout");
        }
    }

    if (bytes_read < 0) {
        error("ERROR reading from remote host");
    }

    close(sockfd);

    return 0;
}
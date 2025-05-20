//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        printf("Invalid host: %s\n", host);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host_entry->h_addr_list[0];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        printf("%s", buffer);
    }

    if (bytes_read < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}
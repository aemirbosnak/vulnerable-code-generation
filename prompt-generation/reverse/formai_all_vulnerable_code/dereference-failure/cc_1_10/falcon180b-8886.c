//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024

void print_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char buffer[MAX_DATA_SIZE];
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "PING %d\r\n", time(NULL));

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        print_error("send");
    }

    char response[MAX_DATA_SIZE];
    memset(response, 0, sizeof(response));

    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received <= 0) {
        print_error("recv");
    }

    response[bytes_received] = '\0';
    printf("Response: %s\n", response);

    close(sockfd);
    return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 10240

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a request to the server
    char request[MAX_BUFFER_SIZE];
    snprintf(request, sizeof(request), "USER anonymous\r\nPASS anonymous@example.com\r\nLIST\r\n");
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive a response from the server
    char response[MAX_BUFFER_SIZE];
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response to the console
    printf("%s", response);

    // Close the socket
    if (close(sockfd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <pthread.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and filename from the command line arguments.
    char *hostname = argv[1];
    char *filename = argv[2];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the hostname.
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the GET request to the server.
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", filename, hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    char response[BUFFER_SIZE];
    int n = recv(sockfd, response, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Parse the response.
    char *body = strstr(response, "\r\n\r\n");
    if (body == NULL) {
        fprintf(stderr, "Invalid response from server.\n");
        return EXIT_FAILURE;
    }

    // Write the response to a file.
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    if (write(fd, body, strlen(body)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    close(fd);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}
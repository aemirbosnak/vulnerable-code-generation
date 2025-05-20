//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response
    char *response = malloc(1024);
    if (recv(sockfd, response, 1024, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check the HTTP status code
    char *status_code = strstr(response, "HTTP/1.1 ");
    if (status_code == NULL) {
        fprintf(stderr, "Invalid HTTP response: %s\n", response);
        return EXIT_FAILURE;
    }
    status_code += strlen("HTTP/1.1 ");
    int code = atoi(status_code);
    if (code != 200) {
        fprintf(stderr, "HTTP status code: %d\n", code);
        return EXIT_FAILURE;
    }

    // Print the HTTP response body
    char *body = strstr(response, "\r\n\r\n");
    if (body == NULL) {
        fprintf(stderr, "Invalid HTTP response: %s\n", response);
        return EXIT_FAILURE;
    }
    body += strlen("\r\n\r\n");
    printf("%s", body);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}
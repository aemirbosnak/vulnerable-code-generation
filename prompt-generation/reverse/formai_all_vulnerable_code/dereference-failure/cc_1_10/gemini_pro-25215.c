//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>

#define MAX_URL_LENGTH 2048
#define MAX_RESPONSE_LENGTH 4096

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];

    // Parse the URL
    struct sockaddr_in addr;
    int port;
    char *host;
    if (parse_url(url, &addr, &port, &host) != 0) {
        fprintf(stderr, "Error parsing URL: %s\n", url);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send an HTTP GET request
    char request[] = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char request_buf[strlen(request) + strlen(host) + 1];
    sprintf(request_buf, request, host);
    if (write(sockfd, request_buf, strlen(request_buf)) == -1) {
        perror("write");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the HTTP response
    char response[MAX_RESPONSE_LENGTH];
    int response_len = 0;
    while (1) {
        int n = read(sockfd, response + response_len, MAX_RESPONSE_LENGTH - response_len);
        if (n == -1) {
            perror("read");
            close(sockfd);
            return EXIT_FAILURE;
        } else if (n == 0) {
            break;
        } else {
            response_len += n;
        }
    }

    // Parse the HTTP response
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        fprintf(stderr, "Error parsing HTTP response: %s\n", response);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check the status code
    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        fprintf(stderr, "Error parsing HTTP status code: %s\n", status_line);
        close(sockfd);
        return EXIT_FAILURE;
    }

    int code = atoi(status_code);
    if (code != 200) {
        fprintf(stderr, "HTTP error: %d\n", code);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Print the response
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}

int parse_url(char *url, struct sockaddr_in *addr, int *port, char **host) {
    // Parse the scheme
    char *scheme = strtok(url, "://");
    if (scheme == NULL) {
        return -1;
    }

    // Check the scheme
    if (strcmp(scheme, "http") != 0) {
        return -1;
    }

    // Parse the host
    *host = strtok(NULL, "/");
    if (*host == NULL) {
        return -1;
    }

    // Parse the port
    char *port_str = strtok(NULL, "/");
    if (port_str != NULL) {
        *port = atoi(port_str);
    } else {
        *port = 80;
    }

    // Parse the address
    struct hostent *h = gethostbyname(*host);
    if (h == NULL) {
        return -1;
    }

    addr->sin_family = AF_INET;
    addr->sin_port = htons(*port);
    addr->sin_addr = *(struct in_addr *)h->h_addr_list[0];

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 4096
#define DEFAULT_CHECK_INTERVAL 600

// Function to check the status of a website
int check_website(char *url) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Parse the URL
    struct sockaddr_in servaddr;
    char *host = strtok(url, ":");
    char *port = strtok(NULL, ":");
    if (host == NULL || port == NULL) {
        fprintf(stderr, "Invalid URL format: %s\n", url);
        return EXIT_FAILURE;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send an HTTP GET request
    char request[MAX_RESPONSE_LENGTH];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response
    char response[MAX_RESPONSE_LENGTH];
    int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    response[bytes_received] = '\0';

    // Close the socket
    close(sockfd);

    // Check the HTTP status code
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        fprintf(stderr, "Invalid HTTP response: %s\n", response);
        return EXIT_FAILURE;
    }

    char *status_code = strtok(status_line, " ");
    if (status_code == NULL || atoi(status_code) != 200) {
        fprintf(stderr, "HTTP error: %s\n", response);
        return EXIT_FAILURE;
    }

    // The website is up and running
    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
    // Check the arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the URL from the command line
    char *url = argv[1];

    // Check the website every 10 minutes
    int check_interval = DEFAULT_CHECK_INTERVAL;

    // Keep checking the website until it goes down
    while (1) {
        // Check the website
        int status = check_website(url);

        // Print the status
        if (status == EXIT_SUCCESS) {
            printf("%s is up\n", url);
        } else {
            printf("%s is down\n", url);
        }

        // Sleep for the check interval
        sleep(check_interval);
    }

    return EXIT_SUCCESS;
}
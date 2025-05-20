//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main() {
    // Get the website URL from the user.
    char website[BUFSIZE];
    printf("Enter the website URL: ");
    scanf("%s", website);

    // Parse the URL and get the hostname.
    struct hostent *host = gethostbyname(website);
    if (host == NULL) {
        fprintf(stderr, "Invalid website URL.\n");
        return 1;
    }

    // Create a socket for connecting to the website.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Failed to create socket.\n");
        return 1;
    }

    // Set the socket timeout.
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        fprintf(stderr, "Failed to set socket timeout.\n");
        return 1;
    }

    // Connect to the website.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Failed to connect to website.\n");
        return 1;
    }

    // Send an HTTP GET request to the website.
    char request[BUFSIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", website);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        fprintf(stderr, "Failed to send HTTP GET request.\n");
        return 1;
    }

    // Receive the HTTP response from the website.
    char response[BUFSIZE];
    int bytes_received = recv(sockfd, response, BUFSIZE - 1, 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Failed to receive HTTP response.\n");
        return 1;
    }

    // Close the socket.
    close(sockfd);

    // Check the HTTP response code to see if the website is up.
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        fprintf(stderr, "Invalid HTTP response.\n");
        return 1;
    }

    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        fprintf(stderr, "Invalid HTTP response.\n");
        return 1;
    }

    if (strcmp(status_code, "200") == 0) {
        printf("Website is up.\n");
    } else {
        printf("Website is down.\n");
    }

    return 0;
}
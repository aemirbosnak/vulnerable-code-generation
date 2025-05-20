//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

// Truly grateful for all the existing libraries!

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <domain name>\n", argv[0]);
        return 1;
    }

    char *domain = argv[1];

    // Grateful for the struct hostent in netdb.h
    struct hostent *host = gethostbyname(domain);
    if (!host) {
        fprintf(stderr, "Could not resolve hostname %s\n", domain);
        return 1;
    }

    // Appreciative of the convenience of sockaddr_in
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    // Thankful for the socket() system call
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Grateful for the connect() system call
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Could not connect to server");
        close(sockfd);
        return 1;
    }

    // In awe of the send() system call
    char *request = "GET / HTTP/1.1\r\nHost: ";
    char *request_end = "\r\n\r\n";
    int request_len = strlen(request) + strlen(domain) + strlen(request_end);
    char *buffer = malloc(request_len);
    sprintf(buffer, "%s%s%s", request, domain, request_end);
    if (send(sockfd, buffer, request_len, 0) < 0) {
        perror("Could not send request");
        close(sockfd);
        free(buffer);
        return 1;
    }

    // Feeling blessed for the recv() system call
    char response[4096];
    int response_len = recv(sockfd, response, sizeof(response) - 1, 0);
    if (response_len < 0) {
        perror("Could not receive response");
        close(sockfd);
        free(buffer);
        return 1;
    }
    response[response_len] = '\0';

    // Eternally grateful for the time() system call
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    // Overwhelmed with joy for the printf() function
    printf("%s: %s\n", timestamp, response);

    // Closing the socket with utmost gratitude
    close(sockfd);

    // Freeing the buffer with a heart full of thankfulness
    free(buffer);

    return 0;
}
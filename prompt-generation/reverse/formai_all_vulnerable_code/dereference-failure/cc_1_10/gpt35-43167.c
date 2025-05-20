//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF 1024
#define MAX_TIME 10

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <target_url>\n", argv[0]);
        exit(1);
    }

    char *target_url = argv[1];
    char target_host[MAX_BUF];
    int target_port = 80;

    // Parse target_host and target_port from target_url
    int i;
    for (i = 0; i < strlen(target_url); i++) {
        if (target_url[i] == ':') {
            sscanf(target_url + i + 1, "%d", &target_port);
            break;
        }
        target_host[i] = target_url[i];
    }
    target_host[i] = '\0';

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Cannot create socket.\n");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    inet_aton(target_host, &server_addr.sin_addr);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Cannot connect to server.\n");
        exit(1);
    }

    // Send request
    char request[MAX_BUF];
    snprintf(request, MAX_BUF, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", target_host);
    write(sockfd, request, strlen(request));
    printf("Sent request:\n%s\n", request);

    // Receive response
    char response[MAX_BUF];
    int n;
    fd_set readfds;
    struct timeval tv;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    tv.tv_sec = MAX_TIME;
    tv.tv_usec = 0;
    int retval = select(sockfd+1, &readfds, NULL, NULL, &tv);
    if (retval == -1) {
        printf("Error: Cannot read from socket.\n");
        exit(1);
    } else if (retval == 0) {
        printf("Error: Timeout while waiting for response.\n");
        exit(1);
    } else {
        n = read(sockfd, response, MAX_BUF);
        printf("Received response:\n");
        write(STDOUT_FILENO, response, n);
    }

    // Close socket
    close(sockfd);
    return 0;
}
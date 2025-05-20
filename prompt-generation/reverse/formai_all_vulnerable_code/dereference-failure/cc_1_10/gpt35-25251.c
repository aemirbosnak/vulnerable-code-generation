//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_REQUEST_LEN 1024
#define MAX_RESPONSE_LEN 2048

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];

    // Parse the URL
    char *host = url;
    char *path = strstr(url, "/");
    if (path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path++;
    }

    // Resolve the hostname
    struct hostent *he = gethostbyname(host);
    if (he == NULL || he->h_addr_list[0] == NULL) {
        printf("Could not resolve hostname: %s\n", host);
        return 1;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Could not create socket.\n");
        return 1;
    }

    // Connect to the host
    struct sockaddr_in addr = {0};
    memcpy(&addr.sin_addr, he->h_addr_list[0], he->h_length);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Could not connect to server.\n");
        return 1;
    }

    // Send the HTTP request
    char request[MAX_REQUEST_LEN];
    snprintf(request, MAX_REQUEST_LEN, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    if (send(sockfd, request, strlen(request), MSG_NOSIGNAL) < 0) {
        printf("Could not send request.\n");
        return 1;
    }

    // Receive the HTTP response
    char response[MAX_RESPONSE_LEN];
    int bytes_received = 0;
    int total_bytes_received = 0;
    while ((bytes_received = recv(sockfd, response + total_bytes_received, MAX_RESPONSE_LEN - total_bytes_received, 0)) > 0) {
        total_bytes_received += bytes_received;
        if (total_bytes_received >= MAX_RESPONSE_LEN - 1) {
            break;
        }
    }
    response[total_bytes_received] = '\0';

    // Close the socket
    close(sockfd);

    // Print the HTTP response
    printf("%s", response);

    return 0;
}
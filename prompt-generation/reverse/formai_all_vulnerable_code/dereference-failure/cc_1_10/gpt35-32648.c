//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define REQUEST_BUF_SIZE 1024
#define RESPONSE_BUF_SIZE 8192

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Get hostname and path from URL
    char *url = argv[1];
    char *hostname = strstr(url, "//");
    if(hostname == NULL) {
        hostname = url;
    } else {
        hostname += 2;
    }
    char *path = strchr(hostname, '/');
    if(path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path++;
    }

    // Get server IP address
    struct hostent *he = gethostbyname(hostname);
    if(he == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    char server_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, he->h_addr, server_ip, INET_ADDRSTRLEN);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    char request_buf[REQUEST_BUF_SIZE];
    snprintf(request_buf, REQUEST_BUF_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    if(send(sock, request_buf, strlen(request_buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive and print HTTP response
    char response_buf[RESPONSE_BUF_SIZE];
    ssize_t bytes_received;
    while((bytes_received = recv(sock, response_buf, RESPONSE_BUF_SIZE-1, 0)) > 0) {
        response_buf[bytes_received] = '\0';
        printf("%s", response_buf);
    }

    // Close socket
    close(sock);
    
    return 0;
}
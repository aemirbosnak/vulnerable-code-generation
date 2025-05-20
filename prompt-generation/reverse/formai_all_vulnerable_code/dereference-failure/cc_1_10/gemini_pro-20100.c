//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_REQUEST_LEN 4096

// Custom HTTP client request builder
char* build_http_request(char* hostname, int port, char* path, char* method) {
    // Format: "GET / HTTP/1.1\r\nHost: hostname:port\r\n\r\n"
    char* request = malloc(MAX_REQUEST_LEN);
    sprintf(request, "%s %s HTTP/1.1\r\n", method, path);
    sprintf(request, "%sHost: %s:%d\r\n\r\n", request, hostname, port);
    return request;
}

// Custom HTTP client implementation
int send_http_request(char* hostname, int port, char* path, char* method) {
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Resolve hostname to IP address
    struct hostent* hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, hostinfo->h_addr, hostinfo->h_length);
    server_addr.sin_port = htons(port);

    // Connect to server
    int connect_res = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (connect_res == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send HTTP request
    char* request = build_http_request(hostname, port, path, method);
    int send_res = send(sockfd, request, strlen(request), 0);
    free(request);
    if (send_res == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive HTTP response
    char buffer[4096];
    int recv_res = recv(sockfd, buffer, sizeof(buffer), 0);
    if (recv_res == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }
    printf("%s", buffer);

    // Clean up
    close(sockfd);
    return 0;
}

int main() {
    // Example usage:
    char* hostname = "example.com";
    int port = 80;
    char* path = "/";
    char* method = "GET";
    int result = send_http_request(hostname, port, path, method);
    if (result == -1) {
        fprintf(stderr, "Error sending HTTP request.\n");
    }
    return 0;
}
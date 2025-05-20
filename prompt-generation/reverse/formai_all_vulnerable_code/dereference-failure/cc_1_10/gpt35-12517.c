//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define HTTP_PORT 80

int main(int argc, char *argv[]) {
    char *url;
    int sock, bytes_read;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[4096];

    if(argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    url = argv[1];

    // parse url
    printf("Parsing URL: %s\n", url);

    char *protocol_ptr = strstr(url, "://");
    if(protocol_ptr == NULL) {
        printf("Invalid URL\n");
        exit(1);
    }
    
    char *path_ptr = strchr(protocol_ptr + 3, '/');
    char *protocol = strndup(url, protocol_ptr - url);
    char *host_str = strndup(protocol_ptr + 3, path_ptr - protocol_ptr - 3);
    char *path = path_ptr == NULL ? "/" : path_ptr;

    printf("Protocol: %s\n", protocol);
    printf("Host: %s\n", host_str);
    printf("Path: %s\n", path);

    // create socket
    printf("Creating socket...\n");
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Socket creation error");
        exit(1);
    }

    // resolve hostname
    printf("Resolving hostname...\n");

    host = gethostbyname(host_str);
    if(host == NULL) {
        printf("Couldn't resolve hostname\n");
        exit(1);
    }

    // setup server address
    printf("Setting up server address...\n");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(HTTP_PORT);

    // connect to server
    printf("Connecting to server...\n");

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        exit(1);
    }

    // send HTTP request
    char *request = (char*)malloc(strlen(protocol) + strlen(host_str) + strlen(path) + 30);
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host_str);

    printf("Sending HTTP request:\n%s\n", request);

    if(send(sock, request, strlen(request), 0) < 0) {
        perror("Send error");
        exit(1);
    }

    // receive HTTP response
    printf("Receiving HTTP response...\n");

    memset(buffer, 0, sizeof(buffer));
    bytes_read = recv(sock, buffer, sizeof(buffer), 0);

    printf("Response:\n%s", buffer);

    // cleanup
    printf("Cleaning up...\n");

    free(protocol);
    free(host_str);
    free(request);
    close(sock);

    return 0;
}
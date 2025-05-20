//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to get IP address from hostname
char *get_ip_address(char *host) {
    struct hostent *he;
    struct in_addr **addr_list;

    if ((he = gethostbyname(host)) == NULL) {
        herror("gethostbyname");
        return NULL;
    }

    addr_list = (struct in_addr **)he->h_addr_list;

    return inet_ntoa(*addr_list[0]);
}

int main(int argc, char *argv[]) {
    int sock, port = 80;
    char *host, *ip_address, request[BUFFER_SIZE], response[BUFFER_SIZE];
    struct sockaddr_in server;

    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse host and path from URL
    host = strtok(argv[1], "/");
    char *path = strtok(NULL, "");
    if (path == NULL) {
        path = "";
    }

    // Get IP address of host
    ip_address = get_ip_address(host);

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(port);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Create HTTP request
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send HTTP request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    int bytes_received;
    while ((bytes_received = recv(sock, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sock);

    return 0;
}
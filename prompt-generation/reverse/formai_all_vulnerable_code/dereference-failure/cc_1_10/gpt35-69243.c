//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 10000

char *get_ip_address(char *hostname) {
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        return NULL;
    }
    struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;
    return inet_ntoa(*addr_list[0]);
}

int http_client(char *hostname, char *path) {
    int sockfd, portno;
    char buffer[MAX_BUFFER_SIZE], request[MAX_BUFFER_SIZE], *ip_address;

    portno = 80;      // Default HTTP port number
    ip_address = get_ip_address(hostname);
    if (ip_address == NULL) {
        printf("Error: Could not resolve hostname\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket\n");
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        printf("Error: Invalid IP address\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server\n");
        return -1;
    }

    // Construct HTTP GET request
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send HTTP GET request to server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error: Failed to send HTTP request\n");
        return -1;
    }

    // Receive response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    while (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    char *hostname, *path;

    if (argc < 3) {
        printf("Usage: %s <hostname> <path>\n", argv[0]);
        return -1;
    }

    hostname = argv[1];
    path = argv[2];

    if (http_client(hostname, path) < 0) {
        printf("Error: Failed to retrieve web page\n");
        return -1;
    }

    return 0;
}
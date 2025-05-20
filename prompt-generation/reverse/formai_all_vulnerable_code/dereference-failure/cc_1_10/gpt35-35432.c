//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to Parse the URL into Hostname and Path
void parse_url(char *url, char **hostname, char **path) {
    char *ptr = strstr(url, "://");
    char *slash_ptr;
    if (ptr) {
        *hostname = ptr + 3;
    } else {
        *hostname = url;
    }

    slash_ptr = strchr(*hostname, '/');
    if (slash_ptr) {
        *slash_ptr = '\0';
        *path = slash_ptr + 1;
    } else {
        *path = "/";
    }
}

// Function to Create a Socket Connection
int create_socket(char *hostname) {
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        perror("Error: Host Not Found");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Error: Could Not Create Socket");
        return -1;
    }

    struct sockaddr_in host_addr;
    memset(&host_addr, 0, sizeof(host_addr));
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(0);
    memmove(&(host_addr.sin_addr.s_addr), host->h_addr_list[0], 4);

    if (connect(sockfd, (struct sockaddr *)&host_addr, sizeof(host_addr)) < 0) {
        perror("Error: Could Not Connect to Host");
        return -1;
    }

    return sockfd;
}

// Function to Send HTTP Request
int send_http_request(int sockfd, char *hostname, char *path) {
    char buf[BUFFER_SIZE];
    sprintf(buf, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    int bytes_sent = send(sockfd, buf, strlen(buf), 0);
    if (bytes_sent < 0) {
        perror("Error: Could Not Send HTTP Request");
        return -1;
    }

    return bytes_sent;
}

// Function to Read Response and Print
int read_http_response(int sockfd) {
    char buf[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = read(sockfd, buf, BUFFER_SIZE)) > 0) {
        printf("%.*s", bytes_read, buf);
    }

    if (bytes_read < 0) {
        perror("Error: Could Not Read HTTP Response");
        return -1;
    }

    return bytes_read;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    char *hostname, *path;
    parse_url(url, &hostname, &path);

    int sockfd = create_socket(hostname);
    if (sockfd < 0) {
        return EXIT_FAILURE;
    }

    if (send_http_request(sockfd, hostname, path) < 0) {
        return EXIT_FAILURE;
    }

    if (read_http_response(sockfd) < 0) {
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}
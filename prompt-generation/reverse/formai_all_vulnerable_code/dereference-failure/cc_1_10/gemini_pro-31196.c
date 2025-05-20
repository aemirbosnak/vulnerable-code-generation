//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_URL_LENGTH 255
#define MAX_HOST_LENGTH 255
#define MAX_PORT_LENGTH 5

typedef struct {
    char url[MAX_URL_LENGTH];
    char host[MAX_HOST_LENGTH];
    char port[MAX_PORT_LENGTH];
} url_info_t;

typedef struct {
    int sockfd;
    url_info_t *url_info;
} monitor_t;

int create_socket(url_info_t *url_info) {
    struct sockaddr_in servaddr;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Translate hostname to IPv4 address
    struct hostent *hostent = gethostbyname(url_info->host);
    if (hostent == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(url_info->port));
    servaddr.sin_addr = *((struct in_addr *)hostent->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

int check_website(monitor_t *monitor) {
    char buffer[1024];
    int n;

    // Send a HTTP GET request
    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", monitor->url_info->url, monitor->url_info->host);
    n = send(monitor->sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    // Receive the response from the server
    memset(buffer, 0, sizeof(buffer));
    n = recv(monitor->sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }

    // Check the HTTP status code
    char *status_line = strtok(buffer, "\r\n");
    if (status_line == NULL) {
        return -1;
    }

    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        return -1;
    }

    int status_code_int = atoi(status_code);
    if (status_code_int != 200) {
        return status_code_int;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the URL
    url_info_t url_info;
    char *url = argv[1];
    char *host;
    char *port;

    if (strncmp(url, "http://", 7) == 0) {
        url += 7;
        host = strtok(url, ":");
        port = strtok(NULL, "/");
    } else if (strncmp(url, "https://", 8) == 0) {
        url += 8;
        host = strtok(url, ":");
        port = strtok(NULL, "/");
    } else {
        fprintf(stderr, "Invalid URL: %s\n", url);
        return EXIT_FAILURE;
    }

    if (host == NULL || port == NULL) {
        fprintf(stderr, "Invalid URL: %s\n", url);
        return EXIT_FAILURE;
    }

    strcpy(url_info.url, url);
    strcpy(url_info.host, host);
    strcpy(url_info.port, port);

    // Create a socket and connect to the website
    monitor_t monitor;
    monitor.url_info = &url_info;
    monitor.sockfd = create_socket(&url_info);
    if (monitor.sockfd == -1) {
        return EXIT_FAILURE;
    }

    // Check the website and print the status code
    int status_code = check_website(&monitor);
    if (status_code == 0) {
        printf("Website is up\n");
    } else {
        printf("Website is down (status code: %d)\n", status_code);
    }

    // Close the socket
    close(monitor.sockfd);

    return EXIT_SUCCESS;
}
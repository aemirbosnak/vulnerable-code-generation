//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 4096
#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 10

typedef struct {
    char *url;
    int port;
    int timeout;
    int (*check_func)(char *, int, int);
} monitor_config_t;

int check_website(char *url, int port, int timeout);
int get_status_code(char *response);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url> [port] [timeout]\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    monitor_config_t config;
    config.url = argv[1];
    config.port = DEFAULT_PORT;
    config.timeout = DEFAULT_TIMEOUT;
    if (argc >= 3) {
        config.port = atoi(argv[2]);
    }
    if (argc >= 4) {
        config.timeout = atoi(argv[3]);
    }

    // Check website uptime
    int status = check_website(config.url, config.port, config.timeout);

    // Print results
    if (status == 200) {
        printf("%s is up and running!\n", config.url);
    } else {
        printf("%s is down! Status code: %d\n", config.url, status);
    }

    return 0;
}

int check_website(char *url, int port, int timeout) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return -1;
    }

    // Resolve hostname
    struct hostent *host = gethostbyname(url);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Connect to website
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send HTTP GET request
    char request[MAX_URL_LENGTH + 128];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\nHost: %s\n\n", url);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive HTTP response
    char response[MAX_RESPONSE_LENGTH];
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Close socket
    close(sockfd);

    // Get HTTP status code
    int status_code = get_status_code(response);

    return status_code;
}

int get_status_code(char *response) {
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        return -1;
    }

    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        return -1;
    }

    return atoi(status_code);
}
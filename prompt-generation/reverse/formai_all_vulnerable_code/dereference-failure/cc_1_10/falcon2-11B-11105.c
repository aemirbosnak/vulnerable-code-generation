//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <sys/wait.h>

#define BUF_SIZE 1024
#define MAX_TIMEOUT 60
#define MAX_HTTP_RETURN_CODE 599
#define DEFAULT_HOST "www.google.com"
#define DEFAULT_PORT 80
#define DEFAULT_PATH "/"

typedef struct {
    int timeout;
    int http_return_code;
} Result;

void handle_signal(int sig) {
    printf("Received signal %d\n", sig);
    exit(EXIT_SUCCESS);
}

void error_handling(char *msg, int errnum) {
    printf("%s: %s\n", msg, strerror(errnum));
    exit(EXIT_FAILURE);
}

void handle_connect(int sockfd, struct sockaddr_in *serv_addr, char *host, char *path) {
    printf("Connecting to %s on port %d\n", host, serv_addr->sin_port);
    if (connect(sockfd, (struct sockaddr *)serv_addr, sizeof(*serv_addr)) < 0) {
        error_handling("Failed to connect to server", errno);
    }
    printf("Connection established\n");
    char request[BUF_SIZE];
    strcpy(request, "GET ");
    strcat(request, path);
    strcat(request, " HTTP/1.0\r\nHost: ");
    strcat(request, host);
    strcat(request, "\r\n\r\n");
    int len = strlen(request);
    int send_ret = send(sockfd, request, len, 0);
    if (send_ret < 0) {
        error_handling("Failed to send request", errno);
    }
    Result result;
    result.timeout = MAX_TIMEOUT;
    result.http_return_code = 0;
    int recv_ret = recv(sockfd, &result, sizeof(Result), 0);
    if (recv_ret < 0) {
        error_handling("Failed to receive response", errno);
    } else if (recv_ret!= sizeof(Result)) {
        printf("Received unexpected response size: %d\n", recv_ret);
    } else {
        printf("Received response: %d\n", result.http_return_code);
    }
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host> [<port> [<path>]]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *host = argv[1];
    char *port = NULL;
    char *path = NULL;
    if (argc >= 3) {
        port = argv[2];
    }
    if (argc >= 4) {
        path = argv[3];
    }
    int sockfd;
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(DEFAULT_HOST);
    if (port) {
        serv_addr.sin_port = htons(atoi(port));
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_handling("Failed to create socket", errno);
    }
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Failed to connect to server", errno);
    }
    if (path) {
        handle_connect(sockfd, &serv_addr, host, path);
    } else {
        handle_connect(sockfd, &serv_addr, host, DEFAULT_PATH);
    }
    return 0;
}
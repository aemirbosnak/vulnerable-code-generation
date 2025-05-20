//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_RESPONSE_SIZE 1024
#define USER_AGENT "Peaceful HTTP Client"

/**
 * Function to print error message and exit
 * if an error occurs while socket operations
 */
void error(const char *msg) {
    perror(msg);
    exit(1);
}

/**
 * Function to parse and get the host and path
 * from the given URL
 */
void parse_url(char *url, char *host, char *path) {
    char *ptr = strstr(url, "://");
    if (ptr != NULL) {
        url = ptr + 3;
    }

    ptr = strchr(url, '/');
    if (ptr != NULL) {
        *ptr = '\0';
        strcpy(path, ptr+1);
    } else {
        strcpy(path, "/");
    }
    strcpy(host, url);
}

/**
 * Function to create a socket and connect to the host
 * using given port
 */
int connect_to_server(char *host, int port) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("Error connecting");
    }

    return sockfd;
}

/**
 * Function to send a HTTP GET request to the server
 * and store the response in a buffer
 */
void http_get(char *url) {
    char host[256];
    char path[256];
    char response[MAX_RESPONSE_SIZE];
    int port = 80;

    int sockfd, bytes, total_bytes = 0;
    char request[256];

    parse_url(url, host, path);

    sockfd = connect_to_server(host, port);

    bzero(request, sizeof(request));
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n", path, host, USER_AGENT);

    bytes = send(sockfd, request, strlen(request), 0);
    if (bytes < 0) {
        error("Error writing to socket");
    }

    bzero(response, MAX_RESPONSE_SIZE);
    do {
        bytes = recv(sockfd, response+total_bytes, MAX_RESPONSE_SIZE-total_bytes, 0);
        if (bytes < 0) {
            error("Error reading from socket");
        }
        total_bytes += bytes;
    } while (bytes > 0);

    printf("%s", response);
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./http-client <URL>\n");
        return 1;
    }

    http_get(argv[1]);

    return 0;
}
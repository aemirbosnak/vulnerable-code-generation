//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_URLS 100
#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 1024

struct url {
    char *url;
    time_t last_checked;
    int status_code;
    char *response;
};

struct url urls[MAX_URLS];
int num_urls = 0;

int create_socket(int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int accept_connection(int sockfd) {
    int connfd;
    struct sockaddr_in cliaddr;
    socklen_t len;

    len = sizeof(cliaddr);
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return connfd;
}

void handle_request(int connfd) {
    char request[MAX_RESPONSE_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int n;

    n = read(connfd, request, MAX_RESPONSE_LENGTH);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("Received request: %s\n", request);

    // Parse the request
    char *url = strtok(request, " ");
    char *method = strtok(NULL, " ");

    if (strcmp(method, "GET") != 0) {
        // Only GET requests are supported
        sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");
        write(connfd, response, strlen(response));
        close(connfd);
        return;
    }

    // Find the URL in the list of URLs
    int i;
    for (i = 0; i < num_urls; i++) {
        if (strcmp(urls[i].url, url) == 0) {
            break;
        }
    }

    if (i == num_urls) {
        // The URL is not in the list
        sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\n");
        write(connfd, response, strlen(response));
        close(connfd);
        return;
    }

    // Send the response
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n%s", strlen(urls[i].response), urls[i].response);
    write(connfd, response, strlen(response));
    close(connfd);
}

int main(int argc, char *argv[]) {
    int sockfd, connfd;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = create_socket(atoi(argv[1]));

    while (1) {
        connfd = accept_connection(sockfd);
        handle_request(connfd);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}
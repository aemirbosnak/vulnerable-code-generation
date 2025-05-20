//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 80
#define DEFAULT_HOST "www.example.com"

struct http_request {
    char *method;
    char *path;
    char *version;
    char *headers;
    char *body;
};

struct http_response {
    int status_code;
    char *status_message;
    char *headers;
    char *body;
};

static int send_request(int sockfd, struct http_request *request) {
    char buffer[4096];
    int n;

    snprintf(buffer, sizeof(buffer), "%s %s %s\r\n", request->method, request->path, request->version);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        return -1;
    }

    if (request->headers != NULL) {
        if (write(sockfd, request->headers, strlen(request->headers)) < 0) {
            perror("write");
            return -1;
        }
    }

    if (request->body != NULL) {
        if (write(sockfd, request->body, strlen(request->body)) < 0) {
            perror("write");
            return -1;
        }
    }

    if (write(sockfd, "\r\n", 2) < 0) {
        perror("write");
        return -1;
    }

    return 0;
}

static int receive_response(int sockfd, struct http_response *response) {
    char buffer[4096];
    int n;

    // Read the status line
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        return -1;
    }
    buffer[n] = '\0';

    char *status_line = strtok(buffer, " ");
    if (status_line == NULL) {
        fprintf(stderr, "Invalid status line: %s\n", buffer);
        return -1;
    }

    response->status_code = atoi(strtok(NULL, " "));
    response->status_message = strtok(NULL, "\r\n");

    // Read the headers
    response->headers = malloc(4096);
    n = read(sockfd, response->headers, 4096 - 1);
    if (n < 0) {
        perror("read");
        return -1;
    }
    response->headers[n] = '\0';

    // Read the body
    response->body = malloc(4096);
    n = read(sockfd, response->body, 4096 - 1);
    if (n < 0) {
        perror("read");
        return -1;
    }
    response->body[n] = '\0';

    return 0;
}

static void print_response(struct http_response *response) {
    printf("Status: %d %s\n", response->status_code, response->status_message);
    printf("Headers:\n%s\n", response->headers);
    printf("Body:\n%s\n", response->body);
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;

    char *host_name = DEFAULT_HOST;
    int port = DEFAULT_PORT;

    if (argc >= 2) {
        host_name = argv[1];
    }

    if (argc >= 3) {
        port = atoi(argv[2]);
    }

    if ((host = gethostbyname(host_name)) == NULL) {
        perror("gethostbyname");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    struct http_request request;
    request.method = "GET";
    request.path = "/";
    request.version = "HTTP/1.1";
    request.headers = NULL;
    request.body = NULL;

    if (send_request(sockfd, &request) < 0) {
        return 1;
    }

    struct http_response response;
    if (receive_response(sockfd, &response) < 0) {
        return 1;
    }

    print_response(&response);

    close(sockfd);

    return 0;
}
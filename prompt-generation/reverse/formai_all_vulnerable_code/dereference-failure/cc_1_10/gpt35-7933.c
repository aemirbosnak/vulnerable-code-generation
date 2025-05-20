//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>


// define constants
#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT "80"
#define TIMEOUT 5000


// data structure for storing HTTP response
struct http_response {
    char *header;
    char *body;
    int status_code;
};


// helper method to extract hostname and path from URL
int parse_url(char* url, char** hostname, char** path) {
    char* temp_buffer = malloc(strlen(url) + 1);
    if (temp_buffer == NULL) {
        return -1;
    }
    strcpy(temp_buffer, url);

    char* ptr = strstr(temp_buffer, "//");
    if (ptr != NULL) {
        *hostname = ptr + 2;
    } else {
        *hostname = temp_buffer;
    }

    ptr = strchr(*hostname, '/');
    if (ptr != NULL) {
        *ptr = '\0';
        *path = ptr + 1;
    } else {
        *path = "/";
    }

    return 0;
}


// helper method for setting up a socket connection
int setup_socket(char* hostname, char* port) {
    struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM
    };
    struct addrinfo *result, *rp;
    int sfd, s;

    s = getaddrinfo(hostname, port, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;
        }

        close(sfd);
    }

    if (rp == NULL) {
        fprintf(stderr, "Failed to connect to server\n");
        return -1;
    }

    freeaddrinfo(result);
    return sfd;
}


// helper method for sending request and receiving response
struct http_response* make_request(char* hostname, char* path) {
    struct http_response* response = malloc(sizeof(struct http_response));
    if (response == NULL) {
        return NULL;
    }

    int socket_fd = setup_socket(hostname, DEFAULT_PORT);
    if (socket_fd < 0) {
        return NULL;
    }

    char request_buffer[MAX_BUFFER_SIZE];

    // build the request
    snprintf(request_buffer, sizeof(request_buffer), "GET /%s HTTP/1.1\r\n"
                       "Host: %s\r\n"
                       "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:89.0) Gecko/20100101 Firefox/89.0\r\n"
                       "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
                       "Accept-Language: en-US,en;q=0.5\r\n"
                       "Accept-Encoding: gzip, deflate, br\r\n"
                       "Connection: keep-alive\r\n\r\n", path, hostname);

    ssize_t bytes_sent = send(socket_fd, request_buffer, strlen(request_buffer), 0);

    if (bytes_sent < 0) {
        perror("send");
        return NULL;
    }

    // set timeout for receiving response
    struct timeval timeout = {
        .tv_sec = TIMEOUT / 1000,
        .tv_usec = (TIMEOUT % 1000) * 1000
    };
    setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    char buffer[MAX_BUFFER_SIZE];
    char* pos;

    // receive response header
    ssize_t bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv");
        return NULL;
    }

    pos = strstr(buffer, "\r\n\r\n");
    if (pos == NULL) {
        return NULL;
    }

    *pos = '\0';

    response->header = strdup(buffer);
    response->body = NULL;
    response->status_code = 0;

    // check for 301 and 302 redirect status codes
    if (strncmp(buffer, "HTTP/1.1 301", 12) == 0 || strncmp(buffer, "HTTP/1.1 302", 12) == 0) {
        pos = strstr(buffer, "Location: ");
        if (pos == NULL) {
            return NULL;
        }

        *pos = '\0';
        pos += 10;

        char* redirect_url = strdup(pos);
        response = make_request(redirect_url, path);
        free(redirect_url);
        return response;
    }

    // extract status code
    char* status_line = strtok(buffer, "\r\n");
    if (status_line != NULL) {
        sscanf(status_line, "HTTP/1.1 %d", &response->status_code);
    }

    // receive response body
    bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv");
    } else if (bytes_received > 0) {
        response->body = malloc(bytes_received);
        if (response->body != NULL) {
            memcpy(response->body, buffer, bytes_received);
        }
    }

    close(socket_fd);
    return response;
}


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [url]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* hostname;
    char* path;

    if (parse_url(argv[1], &hostname, &path) < 0) {
        printf("Invalid URL: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Connecting to %s ...\n", hostname);

    struct http_response* response = make_request(hostname, path);

    if (response != NULL && response->status_code > 0) {
        printf("Response Status Code: %d\n", response->status_code);

        if (response->header != NULL) {
            printf("Response Header:\n%s\n", response->header);
        }

        if (response->body != NULL) {
            // print only first 100 characters from response body
            printf("Response Body:\n%.100s\n", response->body);
        }
    } else {
        printf("Failed to make request\n");
    }

    if (response != NULL) {
        free(response->header);
        free(response->body);
        free(response);
    }

    free(hostname);
    free(path);

    return 0;
}
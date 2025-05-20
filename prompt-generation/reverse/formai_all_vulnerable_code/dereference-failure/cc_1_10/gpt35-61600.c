//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT "80" // Port for HTTP protocol

// Struct to hold the response from the server
struct HttpResponse {
    int status_code;
    char *body;
};

// Function to create a TCP socket and connect to a URL
int connect_to_server(char *hostname) {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(hostname, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    // Loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("connect error");
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo);

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    return sock;
}

// Function to make an HTTP GET request to a URL
struct HttpResponse http_get(char *url) {
    int sock = connect_to_server(url);

    char *request = malloc(strlen(url) + 20);
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);

    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send error");
        exit(1);
    }

    free(request);

    int bytes_received = 0;
    char *buffer = malloc(1024);
    char *body = NULL;
    int body_length = 0;
    int status_code = 0;

    while ((bytes_received = recv(sock, buffer, 1024, 0)) > 0) {
        if (body == NULL) { // We haven't received the body yet
            char *body_ptr = strstr(buffer, "\r\n\r\n");
            if (body_ptr != NULL) { // We found the body
                body_ptr += 4; // Move past '\r\n\r\n'
                body_length = bytes_received - (body_ptr - buffer);
                body = malloc(body_length + 1);
                memcpy(body, body_ptr, body_length);
                body[body_length] = '\0';
            }
        } else { // We have received the body
            body_length += bytes_received;
            body = realloc(body, body_length + 1);

            if (body == NULL) {
                fprintf(stderr, "realloc error\n");
                exit(1);
            }

            memcpy(body + body_length - bytes_received, buffer, bytes_received);
            body[body_length] = '\0';
        }

        char *status_ptr = strstr(buffer, "HTTP/1.1 ");
        if (status_ptr != NULL) { // We found the status code
            sscanf(status_ptr, "HTTP/1.1 %d", &status_code);
        }

        memset(buffer, 0, 1024);
    }

    free(buffer);
    close(sock);

    struct HttpResponse response = {status_code, body};
    return response;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: http_client <url>\n");
        exit(1);
    }

    struct HttpResponse response = http_get(argv[1]);

    printf("Status code: %d\n", response.status_code);
    printf("Body:\n%s\n", response.body);

    free(response.body);

    return 0;
}
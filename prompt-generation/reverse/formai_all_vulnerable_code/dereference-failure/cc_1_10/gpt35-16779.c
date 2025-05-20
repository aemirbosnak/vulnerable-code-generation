//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_DATA_SIZE 1024           // Max buffer size.
#define HTTP_PORT 80                 // HTTP default port.

typedef struct {
    char *host_name;
    char *path;
    int port;
} http_request;

// function to build and execute HTTP client request.
void http_client_request(http_request req) {
    struct sockaddr_in server_addr;
    struct hostent *he;
    int sockfd, num_bytes;
    char request_buffer[MAX_DATA_SIZE];
    char response_buffer[MAX_DATA_SIZE];

    // get the host information.
    if ((he = gethostbyname(req.host_name)) == NULL) {
        perror("Could not get host");
        exit(EXIT_FAILURE);
    }

    // create the socket for communication with server.
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // set the server address information.
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(req.port);
    server_addr.sin_addr = *((struct in_addr*)he->h_addr);

    // Connect to the remote server.
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Could not connect to server");
        exit(EXIT_FAILURE);
    }

    // Build the HTTP request.
    sprintf(request_buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nAccept: */*\r\nConnection: close\r\n\r\n", req.path, req.host_name);

    // Send the request to the remote server.
    if (send(sockfd, request_buffer, strlen(request_buffer), 0) == -1) {
        perror("Error sending request");
        exit(EXIT_FAILURE);
    }

    // Read the response from the remote server.
    while ((num_bytes = recv(sockfd, response_buffer, MAX_DATA_SIZE - 1, 0)) > 0) {
        response_buffer[num_bytes] = '\0';
        printf("%s", response_buffer);
    }

    // Close the socket.
    close(sockfd);
}


int main(int argc, char *argv[]) {
    http_request req;

    req.host_name = "www.example.com";
    req.path = "/";
    req.port = HTTP_PORT;

    // make the HTTP client request.
    http_client_request(req);

    return 0;
}
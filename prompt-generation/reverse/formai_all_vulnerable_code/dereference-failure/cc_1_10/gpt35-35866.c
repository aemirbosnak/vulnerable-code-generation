//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    // check if URL is provided as input
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // parse URL to get host name and file path
    char *url = argv[1];
    char *host_name = strstr(url, "://");
    if (host_name == NULL) {
        fprintf(stderr, "Invalid URL\n");
        exit(EXIT_FAILURE);
    }
    host_name += 3;
    char *file_path = strchr(host_name, '/');
    if (file_path == NULL) {
        file_path = "/";
    } else {
        *file_path = '\0';
        file_path++;
    }

    // resolve host name to IP address
    struct hostent *he = gethostbyname(host_name);
    if (he == NULL) {
        fprintf(stderr, "Could not resolve host name\n");
        exit(EXIT_FAILURE);
    }
    const char *ip_address = inet_ntoa(*(struct in_addr *) he->h_addr);

    // create socket to connect to server
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        fprintf(stderr, "Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(80); // HTTP port
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    // send HTTP request to server
    char request[BUF_SIZE];
    sprintf(request, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", file_path, host_name);
    if (send(sock_fd, request, strlen(request), 0) == -1) {
        fprintf(stderr, "Could not send request to server\n");
        exit(EXIT_FAILURE);
    }

    // receive HTTP response from server
    char response[BUF_SIZE];
    int bytes_received = recv(sock_fd, response, BUF_SIZE - 1, 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Could not receive response from server\n");
        exit(EXIT_FAILURE);
    }
    response[bytes_received] = '\0';

    // print HTTP response
    printf("%s", response);

    // close socket and exit
    close(sock_fd);
    exit(EXIT_SUCCESS);
}
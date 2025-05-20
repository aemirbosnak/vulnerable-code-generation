//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/* function to create a TCP socket */
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

/* function to connect to a server */
void connect_to_server(int sockfd, const char* hostname, const char* port) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo* res;
    int status = getaddrinfo(hostname, port, &hints, &res);
    if(status != 0) {
        perror(gai_strerror(status));
        exit(EXIT_FAILURE);
    }
    if(connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(res);
}

/* function to send an HTTP GET request */
void send_http_request(int sockfd, const char* hostname, const char* path) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if(write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Failed to send HTTP request");
        exit(EXIT_FAILURE);
    }
}

/* function to receive the HTTP response */
void receive_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int num_bytes;
    do {
        num_bytes = read(sockfd, buffer, BUFFER_SIZE-1);
        if(num_bytes < 0) {
            perror("Failed to receive HTTP response");
            exit(EXIT_FAILURE);
        } else {
            buffer[num_bytes] = '\0'; // add null terminator
            printf("%s", buffer);
        }
    } while(num_bytes > 0);
}

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Usage: %s host port\n", argv[0]);
        return EXIT_FAILURE;
    }
    int sockfd = create_socket();
    connect_to_server(sockfd, argv[1], argv[2]);
    send_http_request(sockfd, argv[1], "/");
    receive_http_response(sockfd);
    close(sockfd);
    return EXIT_SUCCESS;
}
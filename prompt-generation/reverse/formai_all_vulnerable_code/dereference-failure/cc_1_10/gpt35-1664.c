//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname = "www.example.com";
    char *port = "80";
    char *payload = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    struct addrinfo hints, *server_info;
    int sockfd, bytes_sent, bytes_recv;
    char buffer[BUFFER_SIZE];

    // initialize hints struct to 0 and set necessary values
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // get server info
    int status = getaddrinfo(hostname, port, &hints, &server_info);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    // create socket file descriptor
    sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // connect to server
    status = connect(sockfd, server_info->ai_addr, server_info->ai_addrlen);
    if (status == -1) {
        perror("connect");
        return 1;
    }

    // send payload
    bytes_sent = send(sockfd, payload, strlen(payload), 0);
    if (bytes_sent == -1) {
        perror("send");
        return 1;
    }

    // receive response
    bytes_recv = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_recv == -1) {
        perror("recv");
        return 1;
    }

    // null terminate response buffer
    buffer[bytes_recv] = '\0';

    // print response
    printf("%s", buffer);

    // free server info and close socket file descriptor
    freeaddrinfo(server_info);
    close(sockfd);

    return 0;
}
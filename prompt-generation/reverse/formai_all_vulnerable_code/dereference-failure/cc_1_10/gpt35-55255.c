//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_NAME "localhost"
#define SERVER_PORT "80"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct addrinfo hints, *server_info;
    int status;
    int socketfd = 0;
    int valread = 0;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE] = "GET / HTTP/1.1\nHost: localhost\n\n";
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(SERVER_NAME, SERVER_PORT, &hints, &server_info)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    if ((socketfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol)) < 0) {
        perror("socket");
        return 1;
    }

    if (connect(socketfd, server_info->ai_addr, server_info->ai_addrlen) < 0) {
        perror("connect");
        return 1;
    }

    if (send(socketfd, message, strlen(message), 0) < 0) {
        perror("send");
        return 1;
    }

    while ((valread = read(socketfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[valread] = '\0';
        printf("%s", buffer);
    }
    
    if (valread < 0) {
        perror("read");
    }

    close(socketfd);
    freeaddrinfo(server_info);
    return 0;
}
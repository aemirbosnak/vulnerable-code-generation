//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80

int main() {
    struct sockaddr_in server;
    struct hostent *server_info;
    int sockfd;
    struct timeval timeout;
    char buffer[256];
    char *host_name = "www.google.com";
    char *error_message = NULL;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    server_info = gethostbyname(host_name);

    if (server_info == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy(&server.sin_addr.s_addr, server_info->h_addr, server_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "ERROR connecting to server\n");
        exit(1);
    }

    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        fprintf(stderr, "ERROR setting socket timeout\n");
        exit(1);
    }

    if (send(sockfd, "GET / HTTP/1.1\r\n\r\n", strlen("GET / HTTP/1.1\r\n\r\n"), 0) < 0) {
        fprintf(stderr, "ERROR sending request\n");
        exit(1);
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        fprintf(stderr, "ERROR receiving response\n");
        exit(1);
    }

    if (strcmp(buffer, "HTTP/1.1 200 OK\r\n\r\n")!= 0) {
        fprintf(stderr, "ERROR, wrong response\n");
        exit(1);
    }

    printf("Connection successful\n");

    exit(0);
}
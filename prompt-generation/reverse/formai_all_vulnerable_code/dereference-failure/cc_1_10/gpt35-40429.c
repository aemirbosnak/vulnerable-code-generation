//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define MAX_BUFFER 1024
#define SERVER_PORT 80

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];

    if (argc < 2) {
        printf("Please enter a host name as an argument.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Could not find host.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed.\n");
        exit(1);
    }

    // Sending GET request
    int bytes_sent = send(sockfd, "GET / HTTP/1.1\r\nHost:example.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost:example.com\r\n\r\n"), 0);

    if (bytes_sent < 0) {
        printf("Error sending request.\n");
        exit(1);
    }

    int bytes_received;
    memset(buffer, 0, sizeof(buffer));
    bytes_received = recv(sockfd, buffer, MAX_BUFFER - 1, 0);

    if (bytes_received < 0) {
        printf("Error receiving data.\n");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}
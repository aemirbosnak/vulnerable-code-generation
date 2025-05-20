//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 256

int main(int argc, char **argv)
{
    int sockfd;
    char *server_ip;
    int server_port;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER_SIZE];
    int n;

    if (argc < 3) {
        fprintf(stderr, "usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    server_ip = argv[1];
    server_port = atoi(argv[2]);

    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "error creating socket\n");
        exit(1);
    }

    /* get server information */
    server = gethostbyname(server_ip);
    if (server == NULL) {
        fprintf(stderr, "error getting server information\n");
        exit(1);
    }

    /* set server address */
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(server_port);

    /* connect to server */
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "error connecting to server\n");
        exit(1);
    }

    /* build and send HTTP request */
    snprintf(buffer, MAX_BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s:%d\r\nUser-Agent: HTTPClient/1.0\r\nAccept: */*\r\n\r\n", server_ip, server_port);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "error sending HTTP request\n");
        exit(1);
    }

    /* receive HTTP response */
    memset(buffer, 0, MAX_BUFFER_SIZE);
    while ((n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    /* close socket */
    close(sockfd);

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_LINE_LENGTH 4096
#define MAX_BUF_SIZE 8192

int main(int argc, char *argv[]) {
    struct addrinfo *res, *rp;
    int sockfd, portno, n;
    char *url = "https://www.example.com";
    char buf[MAX_BUF_SIZE];
    char req_buf[MAX_LINE_LENGTH];
    struct hostent *host;
    struct sockaddr_in serv_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if ((host = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    memcpy((char *) &serv_addr, (char *) host->h_addr, host->h_length);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("HTTP/1.0 200 OK\r\n");
    printf("Content-Type: text/html\r\n");
    printf("\r\n");

    strcpy(req_buf, "GET / HTTP/1.1\r\n");
    strcat(req_buf, "Host: localhost\r\n");
    strcat(req_buf, "\r\n");

    if (send(sockfd, req_buf, strlen(req_buf), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s", buf);

    close(sockfd);

    return 0;
}
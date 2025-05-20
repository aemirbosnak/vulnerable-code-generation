//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_PORT 80
#define SERVER_ADDR "www.google.com"
#define BUF_SIZE 1024

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buf[BUF_SIZE];

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // get the server's IP address
    if ((server = gethostbyname(SERVER_ADDR)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // fill in the server's address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // send a request to the server
    sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_ADDR);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    // receive the response from the server
    struct timeval start, end;
    gettimeofday(&start, NULL);
    int total_bytes = 0;
    while ((n = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
        total_bytes += n;
    }
    gettimeofday(&end, NULL);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    // calculate the download speed
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double speed = total_bytes / elapsed_time;

    // close the socket
    close(sockfd);

    // print the download speed
    printf("Download speed: %.2f MB/s\n", speed / 1024 / 1024);

    return 0;
}
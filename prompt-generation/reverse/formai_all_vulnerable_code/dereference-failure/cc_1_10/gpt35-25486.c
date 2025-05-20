//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define PORT "80" // port number used for the HTTP request
#define REQUEST "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n" // HTTP GET request used to initiate the download 

int main(int argc, char *argv[])
{
    struct addrinfo hints, *res;
    int sockfd, status, len, bytes_sent, bytes_recv, total_time;
    struct timeval t1, t2;
    char data[1024];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo("www.google.com", PORT, &hints, &res)) != 0) {
        fprintf(stderr, "Error: getaddrinfo failed: %s\n", gai_strerror(status));
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sockfd < 0) {
        perror("Error: Could not create socket\n");
        return 1;
    }

    if ((status = connect(sockfd, res->ai_addr, res->ai_addrlen))) {
        perror("Error: Connect failed\n");
        close(sockfd);
        return 1;
    }

    len = strlen(REQUEST);

    bytes_sent = send(sockfd, REQUEST, len, 0);

    if (bytes_sent < 0) {
        perror("Error: Send failed\n");
        close(sockfd);
        return 1;
    }

    gettimeofday(&t1, NULL);

    while ((bytes_recv = recv(sockfd, data, sizeof data, 0)) > 0) {}

    gettimeofday(&t2, NULL);

    total_time = (t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_usec - t1.tv_usec) / 1000;

    printf("Download speed: %.2f kB/s\n", (float)(len / (total_time / 1000.0)));

    close(sockfd);
    freeaddrinfo(res);

    return 0;
}
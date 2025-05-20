//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/nameser.h>
#include <sys/signal.h>

#define MAXLINE 4096
#define PORT 80
#define REQUEST "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: keep-alive\r\n\r\n"

/*
 * function to get the system uptime
 */
int get_uptime()
{
    struct timeval timeval;
    int retval;
    char uptime[128];

    gettimeofday(&timeval, NULL);
    retval = sysconf(_SC_CLK_TCK);
    sprintf(uptime, "%.2f", (double)timeval.tv_sec + (double)timeval.tv_usec * 1e-6 / retval);
    return 0;
}

/*
 * function to send a request to the server
 */
int send_request(int sockfd, char *host, int port)
{
    char request[MAXLINE];
    struct sockaddr_in serv_addr;

    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    memset(request, 0, sizeof(request));
    strcpy(request, REQUEST);
    int len = strlen(request);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect() failed");
        return -1;
    }

    if (send(sockfd, request, len, 0) < 0) {
        perror("send() failed");
        return -1;
    }

    return 0;
}

/*
 * function to read the server response
 */
int read_response(int sockfd)
{
    char buf[MAXLINE];
    int n, rc;

    while ((rc = read(sockfd, buf, MAXLINE)) > 0) {
        printf("%s", buf);
    }

    return rc;
}

/*
 * function to check the response code
 */
int check_response(int sockfd)
{
    int n;
    char buf[MAXLINE];
    int status_code = 0;

    read(sockfd, buf, MAXLINE);
    n = sscanf(buf, "%d %*s %d %*s %d %*s %s", &status_code);

    if (n < 1) {
        printf("Error: Invalid response code\n");
        return -1;
    }

    if (status_code >= 200 && status_code < 300) {
        printf("Response code: %d\n", status_code);
        return 0;
    }

    printf("Error: Bad response code (%d)\n", status_code);
    return -1;
}

/*
 * function to send an HTTP request to the server
 */
int send_http_request(int sockfd, char *host, int port)
{
    if (send_request(sockfd, host, port) < 0) {
        return -1;
    }

    if (read_response(sockfd) < 0) {
        return -1;
    }

    if (check_response(sockfd) < 0) {
        return -1;
    }

    return 0;
}

/*
 * main function
 */
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[INET_ADDRSTRLEN];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    if (send_http_request(sockfd, argv[1], portno) < 0) {
        exit(1);
    }

    printf("Uptime: %s\n", get_uptime());

    return 0;
}
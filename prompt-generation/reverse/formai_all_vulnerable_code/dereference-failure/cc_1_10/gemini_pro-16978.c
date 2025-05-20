//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 8192
#define MAX_HOST 256

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char **argv)
{
    int sockfd, n;
    char buffer[MAX_LINE];
    struct sockaddr_in servaddr;
    struct hostent *host;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error("socket");

    host = gethostbyname(argv[1]);
    if (host == NULL)
        error("gethostbyname");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&servaddr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        error("connect");

    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1)
        error("write");

    while ((n = read(sockfd, buffer, MAX_LINE - 1)) > 0)
    {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    if (n == -1)
        error("read");

    close(sockfd);
    return 0;
}
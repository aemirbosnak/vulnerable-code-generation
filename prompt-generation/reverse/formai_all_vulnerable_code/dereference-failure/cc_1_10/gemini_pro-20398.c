//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define HOSTNAME_MAX_LENGTH 255
#define PORT_MAX_LENGTH 5

static int create_socket(const char* hostname, const char* port)
{
    int sockfd;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &res) != 0)
    {
        perror("getaddrinfo");
        return -1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0)
    {
        perror("socket");
        return -1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0)
    {
        perror("connect");
        return -1;
    }

    freeaddrinfo(res);
    return sockfd;
}

static void close_socket(int sockfd)
{
    if (sockfd >= 0)
    {
        close(sockfd);
    }
}

static int send_request(int sockfd)
{
    const char* request = "HEAD / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    int len = strlen(request);

    if (send(sockfd, request, len, 0) != len)
    {
        perror("send");
        return -1;
    }

    return 0;
}

static int receive_response(int sockfd)
{
    char buffer[1024];
    int len;

    while ((len = recv(sockfd, buffer, sizeof(buffer), 0)) > 0)
    {
        if (strstr(buffer, "200 OK") != NULL)
        {
            return 0;
        }
    }

    if (len < 0)
    {
        perror("recv");
    }

    return -1;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    const char* hostname = argv[1];
    const char* port = argv[2];

    int sockfd = create_socket(hostname, port);
    if (sockfd < 0)
    {
        return 1;
    }

    if (send_request(sockfd) < 0)
    {
        close_socket(sockfd);
        return 1;
    }

    if (receive_response(sockfd) < 0)
    {
        close_socket(sockfd);
        return 1;
    }

    close_socket(sockfd);
    return 0;
}
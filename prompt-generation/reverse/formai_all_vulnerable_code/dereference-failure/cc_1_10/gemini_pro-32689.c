//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    const char *host = argv[1];
    const char *port = argv[2];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(host);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return 1;
    }

    const char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

    if (send(sockfd, request, strlen(request), 0) == -1)
    {
        perror("send");
        return 1;
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    int n;
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0)
    {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    if (n == -1)
    {
        perror("recv");
        return 1;
    }

    close(sockfd);

    return 0;
}
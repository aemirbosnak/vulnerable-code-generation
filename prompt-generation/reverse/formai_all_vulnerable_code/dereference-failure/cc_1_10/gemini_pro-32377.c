//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BACKLOG 5

int main(int argc, char** argv)
{
    int sockfd, new_sockfd, portno, yes = 1, val = 0, len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(portno);

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(sockfd, BACKLOG);

    len = sizeof(cli_addr);
    while (1)
    {
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &len);
        if (new_sockfd < 0)
        {
            perror("accept");
            exit(1);
        }

        memset(buffer, 0, 256);
        recv(new_sockfd, buffer, 255, 0);

        printf("%s", buffer);

        memset(buffer, 0, 256);
        val = atoi(buffer);

        send(new_sockfd, &val, 4, 0);

        close(new_sockfd);
    }

    close(sockfd);

    return 0;
}
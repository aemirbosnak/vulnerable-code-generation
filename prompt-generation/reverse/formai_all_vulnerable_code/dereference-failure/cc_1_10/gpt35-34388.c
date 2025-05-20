//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int client_fd, server_fd, sock_port, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    sock_port = atoi(argv[1]);

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        error("ERROR creating socket");
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(sock_port);

    if (bind(client_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR on binding");
    }

    while (1)
    {
        listen(client_fd, 5);
        socklen_t cli_len = sizeof(cli_addr);
        server_fd = accept(client_fd, (struct sockaddr *)&cli_addr, &cli_len);

        if (server_fd < 0)
        {
            error("ERROR on accept");
        }

        bzero(buffer, sizeof(buffer));
        n = read(server_fd, buffer, sizeof(buffer));

        if (n < 0)
        {
            error("ERROR reading from socket");
        }

        printf("%s\n", buffer);

        char *host = strtok(buffer + 11, "\r\n");
        printf("%s\n", host);

        server = gethostbyname(host);

        if (server == NULL)
        {
            error("ERROR no such host");
        }

        bzero((char *)&serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(80);

        if (connect(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            error("ERROR connecting");
        }

        n = write(server_fd, buffer, sizeof(buffer));

        if (n < 0)
        {
            error("ERROR writing to socket");
        }

        bzero(buffer, sizeof(buffer));

        while ((n = read(server_fd, buffer, sizeof(buffer))) > 0)
        {

            if (write(server_fd, buffer, n) < 0)
            {
                error("ERROR writing to socket");
            }
        }

        if (n < 0)
        {
            error("ERROR reading from socket");
        }

        close(server_fd);
    }

    return 0;
}
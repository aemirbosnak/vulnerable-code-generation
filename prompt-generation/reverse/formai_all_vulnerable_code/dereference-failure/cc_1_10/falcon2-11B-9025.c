//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int server_fd, conn_fd, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    listen(server_fd, 5);

    while (1)
    {
        conn_fd = accept(server_fd, (struct sockaddr *) &cli_addr, (socklen_t *)&n);
        if (conn_fd < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(atoi(argv[2]));

        if (connect(conn_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        {
            perror("ERROR on connecting");
            exit(1);
        }

        n = read(conn_fd, (char *) &serv_addr, sizeof(serv_addr));
        printf("Received data %d bytes from %s:%d\n", n, inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        close(conn_fd);
    }

    close(server_fd);
    return 0;
}
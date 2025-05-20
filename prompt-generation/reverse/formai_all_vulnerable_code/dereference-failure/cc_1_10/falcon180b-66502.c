//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535

int main(int argc, char *argv[])
{
    int sock, port, max_sd, addrlen, new_sd, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1025];
    int opt = 1;
    char *ip;
    int count = 0;

    if (argc < 3)
    {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        exit(0);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);
    printf("Port %d is open\n", port);

    for (port = port + 1; port <= MAX; port++)
    {
        if ((new_sd = accept(sock, (struct sockaddr *)NULL, NULL)) < 0)
        {
            if (errno!= ECONNABORTED)
                perror("accept");

            close(new_sd);
            continue;
        }

        addrlen = sizeof(cli_addr);
        getsockname(new_sd, (struct sockaddr *)&cli_addr, &addrlen);

        inet_ntop(AF_INET, &cli_addr.sin_addr, buffer, sizeof(buffer));

        printf("Port %d is open\n", ntohs(cli_addr.sin_port));
        close(new_sd);
    }

    close(sock);
    return 0;
}
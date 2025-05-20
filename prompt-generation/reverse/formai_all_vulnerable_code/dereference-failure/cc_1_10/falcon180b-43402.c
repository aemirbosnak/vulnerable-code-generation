//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[])
{
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char *ip = "127.0.0.1";
    int port = 8080;
    int opt = 1;
    char buffer[MAX_LINE];

    if(argc!= 3)
    {
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if(bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        return 1;
    }

    if(listen(listen_fd, BACKLOG) == -1)
    {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Proxy server started on %s:%d\n", ip, port);

    while(1)
    {
        memset(buffer, 0, MAX_LINE);
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if(client_fd == -1)
        {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while(1)
        {
            memset(buffer, 0, MAX_LINE);
            if(recv(client_fd, buffer, MAX_LINE, 0) == 0)
            {
                printf("Client disconnected\n");
                break;
            }

            send(client_fd, buffer, strlen(buffer), 0);
        }

        close(client_fd);
    }

    close(listen_fd);
    return 0;
}
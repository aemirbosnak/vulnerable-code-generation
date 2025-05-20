//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define ERROR_MESSAGE "Error: %s\n"

int main(int argc, char **argv)
{
    int listen_sock, client_sock, bytes_received;
    struct sockaddr_in server_addr, client_addr;

    if(argc!= 3)
    {
        fprintf(stderr, "Usage: %s <port_number> <ip_address>\n", argv[0]);
        return 1;
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_sock == -1)
    {
        fprintf(stderr, ERROR_MESSAGE, "Failed to create socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if(bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        fprintf(stderr, ERROR_MESSAGE, "Failed to bind socket");
        return 1;
    }

    if(listen(listen_sock, 5) == -1)
    {
        fprintf(stderr, ERROR_MESSAGE, "Failed to listen on socket");
        return 1;
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while(1)
    {
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if(client_sock == -1)
        {
            fprintf(stderr, ERROR_MESSAGE, "Failed to accept connection");
            continue;
        }

        char buffer[BUFFER_SIZE];
        while((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0)
        {
            send(client_sock, buffer, bytes_received, 0);
        }

        close(client_sock);
    }

    return 0;
}
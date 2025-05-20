//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    int result = bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result == -1)
    {
        perror("bind");
        exit(1);
    }

    result = listen(listen_sock, 5);
    if (result == -1)
    {
        perror("listen");
        exit(1);
    }

    int conn_sock;
    while ((conn_sock = accept(listen_sock, NULL, NULL))!= -1)
    {
        char buffer[1024];
        int bytes_read;

        bytes_read = read(conn_sock, buffer, sizeof(buffer));
        if (bytes_read == -1)
        {
            perror("read");
            exit(1);
        }

        printf("Received: %s\n", buffer);
        bytes_read = write(conn_sock, "ACK", 3);
        if (bytes_read == -1)
        {
            perror("write");
            exit(1);
        }

        close(conn_sock);
    }

    close(listen_sock);
    return 0;
}
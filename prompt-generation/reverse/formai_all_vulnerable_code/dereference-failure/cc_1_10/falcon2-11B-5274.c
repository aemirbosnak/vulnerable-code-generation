//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFERSIZE 1024
#define PORT 8080

int main()
{
    int listen_socket, conn_socket, n;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(cli_addr);
    char buffer[BUFFERSIZE];
    char url[BUFFERSIZE];
    char *filename;

    int server_port = PORT;
    int server_addr = "127.0.0.1";

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_addr);
    serv_addr.sin_port = htons(server_port);

    if (bind(listen_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, 5) < 0)
    {
        perror("listen");
        exit(1);
    }

    while (1)
    {
        conn_socket = accept(listen_socket, (struct sockaddr *)&cli_addr, &addrlen);
        if (conn_socket < 0)
        {
            perror("accept");
            exit(1);
        }

        printf("Connected to %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        printf("Enter a URL: ");
        fgets(url, BUFFERSIZE, stdin);
        url[strcspn(url, "\n")] = 0;
        printf("Sending to server...\n");

        filename = malloc(strlen(url) + 1);
        strcpy(filename, url);
        send(conn_socket, filename, strlen(filename), 0);
        recv(conn_socket, buffer, BUFFERSIZE, 0);
        printf("Received from server: %s\n", buffer);

        free(filename);
        close(conn_socket);
    }

    close(listen_socket);
    return 0;
}
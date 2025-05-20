//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc!= 4)
    {
        printf("Usage:./program <host> <port> <username>\n");
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];
    char *username = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "USER %s\r\n", username);

    send(sock, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);

    printf("Server response: %s\n", response);

    close(sock);

    return 0;
}
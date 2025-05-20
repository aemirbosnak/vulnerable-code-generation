//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define DELIMITER "\r\n"

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int n;

    if (argc!= 4)
    {
        printf("Usage:./pop3_client <server_address> <username> <password>\n");
        return 1;
    }

    strcpy(send_buffer, "USER ");
    strcat(send_buffer, argv[2]);
    strcat(send_buffer, DELIMITER);
    send(sock, send_buffer, strlen(send_buffer), 0);

    n = recv(sock, recv_buffer, BUFFER_SIZE, 0);
    if (n <= 0)
    {
        printf("Error receiving from server\n");
        close(sock);
        return 1;
    }

    printf("Server response: %s", recv_buffer);

    strcpy(send_buffer, "PASS ");
    strcat(send_buffer, argv[3]);
    strcat(send_buffer, DELIMITER);
    send(sock, send_buffer, strlen(send_buffer), 0);

    n = recv(sock, recv_buffer, BUFFER_SIZE, 0);
    if (n <= 0)
    {
        printf("Error receiving from server\n");
        close(sock);
        return 1;
    }

    printf("Server response: %s", recv_buffer);

    strcpy(send_buffer, "LIST");
    strcat(send_buffer, DELIMITER);
    send(sock, send_buffer, strlen(send_buffer), 0);

    n = recv(sock, recv_buffer, BUFFER_SIZE, 0);
    if (n <= 0)
    {
        printf("Error receiving from server\n");
        close(sock);
        return 1;
    }

    printf("Server response: %s", recv_buffer);

    close(sock);
    return 0;
}
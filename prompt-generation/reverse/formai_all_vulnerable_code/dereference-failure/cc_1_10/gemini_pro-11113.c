//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define MAX_RECV 4096

void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    char buf[256];
    vsprintf(buf, format, args);

    write(1, buf, strlen(buf));

    va_end(args);
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        my_printf("Usage: %s <server_ip> <server_port> <email_address>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        my_printf("Error: Could not create socket\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &servaddr.sin_addr) == 0)
    {
        my_printf("Error: Invalid server IP address\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        my_printf("Error: Could not connect to server\n");
        return 1;
    }

    char recv_buf[MAX_RECV];
    int recv_len;

    recv_len = recv(sockfd, recv_buf, MAX_RECV, 0);
    if (recv_len == -1)
    {
        my_printf("Error: Could not receive data from server\n");
        return 1;
    }

    recv_buf[recv_len] = '\0';
    my_printf("%s", recv_buf);

    char send_buf[MAX_LINE];
    int send_len;

    my_printf("To: ");
    fgets(send_buf, MAX_LINE, stdin);
    send_len = strlen(send_buf);
    if (send_buf[send_len - 1] == '\n')
        send_buf[send_len - 1] = '\0';
    if (send(sockfd, send_buf, send_len, 0) == -1)
    {
        my_printf("Error: Could not send data to server\n");
        return 1;
    }

    my_printf("Subject: ");
    fgets(send_buf, MAX_LINE, stdin);
    send_len = strlen(send_buf);
    if (send_buf[send_len - 1] == '\n')
        send_buf[send_len - 1] = '\0';
    if (send(sockfd, send_buf, send_len, 0) == -1)
    {
        my_printf("Error: Could not send data to server\n");
        return 1;
    }

    my_printf("Body: ");
    fgets(send_buf, MAX_LINE, stdin);
    send_len = strlen(send_buf);
    if (send_buf[send_len - 1] == '\n')
        send_buf[send_len - 1] = '\0';
    if (send(sockfd, send_buf, send_len, 0) == -1)
    {
        my_printf("Error: Could not send data to server\n");
        return 1;
    }

    my_printf(".\n");
    if (send(sockfd, ".", 2, 0) == -1)
    {
        my_printf("Error: Could not send data to server\n");
        return 1;
    }

    recv_len = recv(sockfd, recv_buf, MAX_RECV, 0);
    if (recv_len == -1)
    {
        my_printf("Error: Could not receive data from server\n");
        return 1;
    }

    recv_buf[recv_len] = '\0';
    my_printf("%s", recv_buf);

    close(sockfd);

    return 0;
}
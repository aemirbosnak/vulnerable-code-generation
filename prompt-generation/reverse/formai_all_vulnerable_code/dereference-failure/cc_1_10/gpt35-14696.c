//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) 
{
    int sock;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE];
    int str_len;

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    // send command to server
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "%s", "LOGIN username password");
    write(sock, buf, strlen(buf));

    // receive response from server
    memset(buf, 0, BUF_SIZE);
    str_len = read(sock, buf, BUF_SIZE-1);
    if (str_len <= 0)
        error_handling("read() error");

    printf("Response from server: %s\n", buf);

    // logout
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "%s", "LOGOUT");
    write(sock, buf, strlen(buf));

    close(sock);

    return 0;
}

void error_handling(char *message) 
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
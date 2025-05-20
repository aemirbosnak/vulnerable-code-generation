//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUFFER_SIZE];
    int str_len, recv_len, recv_cnt;

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        error_handling("connect() error");
    }

    char *from = "FROM: test@example.com\r\n";
    char *to = "TO: example@gmail.com\r\n";
    char *subject = "SUBJECT: SMTP Client Example\r\n";
    char *body = "This is an example SMTP client program written in C.\r\n";
    char *end = ".\r\n";

    char *message_text = calloc(strlen(from) + strlen(to) + strlen(subject) + strlen(body) + strlen(end) + 1, sizeof(char));
    sprintf(message_text, "%s%s%s\r\n%s", from, to, subject, body);
    strcat(message_text, end);

    str_len = strlen(message_text);

    if (write(sock, message_text, str_len) == -1)
    {
        error_handling("write() error");
    }

    memset(message, 0, BUFFER_SIZE);

    recv_len = 0;
    while (recv_len < str_len)
    {
        recv_cnt = read(sock, &message[recv_len], BUFFER_SIZE - 1);
        if (recv_cnt == -1)
        {
            error_handling("read() error");
        }
        recv_len += recv_cnt;
    }

    printf("Message from server: %s\n", message);

    close(sock);

    free(message_text);

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
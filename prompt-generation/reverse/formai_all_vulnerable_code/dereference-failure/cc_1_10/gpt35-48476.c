//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock_desc;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    char user[BUF_SIZE], pass[BUF_SIZE];

    if(argc != 3)
    {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server at %s:%d\n", argv[1], atoi(argv[2]));

    recv(sock_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);

    printf("Enter username: ");
    fgets(user, BUF_SIZE, stdin);
    user[strcspn(user, "\n")] = 0;

    sprintf(buf, "USER %s\r\n", user);
    send(sock_desc, buf, strlen(buf), 0);

    recv(sock_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);

    printf("Enter password: ");
    fgets(pass, BUF_SIZE, stdin);
    pass[strcspn(pass, "\n")] = 0;

    sprintf(buf, "PASS %s\r\n", pass);
    send(sock_desc, buf, strlen(buf), 0);

    recv(sock_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);

    sprintf(buf, "LIST\r\n");
    send(sock_desc, buf, strlen(buf), 0);

    recv(sock_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);

    sprintf(buf, "QUIT\r\n");
    send(sock_desc, buf, strlen(buf), 0);

    recv(sock_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    close(sock_desc);

    return 0;
}
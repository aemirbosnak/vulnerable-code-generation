//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[])
{
    int sock, port = 110;
    struct sockaddr_in serv_adr;
    char buf[BUF_SIZE];

    if(argc != 3){
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        perror("socket() error");
        exit(1);
    }

    if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1){
        perror("connect() error");
        exit(1);
    }

    memset(buf, 0, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("%s", buf);

    printf("Username : ");
    memset(buf, 0, BUF_SIZE);
    fgets(buf, BUF_SIZE-1, stdin);
    buf[strlen(buf)-1] = '\0';

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "USER %s\r\n", buf);
    write(sock, buf, strlen(buf));
    read(sock, buf, BUF_SIZE);
    printf("%s", buf);

    printf("Password : ");
    memset(buf, 0, BUF_SIZE);
    fgets(buf, BUF_SIZE-1, stdin);
    buf[strlen(buf)-1] = '\0';

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "PASS %s\r\n", buf);
    write(sock, buf, strlen(buf));
    read(sock, buf, BUF_SIZE);
    printf("%s", buf);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "STAT\r\n");
    write(sock, buf, strlen(buf));
    read(sock, buf, BUF_SIZE);
    printf("%s", buf);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "QUIT\r\n");
    return 0;
}
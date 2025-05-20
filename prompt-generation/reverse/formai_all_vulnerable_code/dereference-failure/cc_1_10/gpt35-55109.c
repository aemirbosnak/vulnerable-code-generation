//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char **argv){

    if(argc < 4){
        printf("Usage: %s ip port email\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);
    char *email = argv[3];

    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1){
        printf("Error creating socket!\n");
        exit(1);
    }

    struct sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) == -1){
        printf("Error connecting to server!\n");
        exit(1);
    }

    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);

    recv(socket_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "HELO smtp.gmail.com\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    recv(socket_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "MAIL FROM:<%s>\r\n", email);
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    recv(socket_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "RCPT TO:<recipient@domain.com>\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    recv(socket_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "DATA\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    recv(socket_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "Subject: Test email from SMTP client\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "From: <%s>\r\n", email);
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "To: <recipient@domain.com>\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "Content-Type: text/plain;charset=utf-8\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "Hello, this is a test email from my SMTP client.\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "\r\n.\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    recv(socket_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "QUIT\r\n");
    send(socket_desc, buf, strlen(buf), 0);

    memset(buf, 0, BUF_SIZE);
    recv(socket_desc, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    close(socket_desc);

    return 0;
}
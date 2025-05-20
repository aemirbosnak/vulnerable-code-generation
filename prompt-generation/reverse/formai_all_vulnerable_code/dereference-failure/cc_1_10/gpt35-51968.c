//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

void error(const char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){
    int sock, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[2000];

    if(argc < 4){
        fprintf(stderr, "USAGE: %s hostname port message", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    sprintf(buffer, "EHLO %s\r\n", argv[1]);
    n = write(sock, buffer, strlen(buffer));
    if(n < 0)
        error("ERROR writing to socket");
    memset(buffer, 0, 2000);
    n = read(sock, buffer, 2000);
    if(n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    sprintf(buffer, "MAIL FROM: <%s>\r\n", argv[3]);
    n = write(sock, buffer, strlen(buffer));
    if(n < 0)
        error("ERROR writing to socket");
    memset(buffer, 0, 2000);
    n = read(sock, buffer, 2000);
    if(n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    sprintf(buffer, "RCPT TO: <%s>\r\n", argv[4]);
    n = write(sock, buffer, strlen(buffer));
    if(n < 0)
        error("ERROR writing to socket");
    memset(buffer, 0, 2000);
    n = read(sock, buffer, 2000);
    if(n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    sprintf(buffer, "DATA\r\n");
    n = write(sock, buffer, strlen(buffer));
    if(n < 0)
        error("ERROR writing to socket");
    memset(buffer, 0, 2000);
    n = read(sock, buffer, 2000);
    if(n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    sprintf(buffer, "%s\r\n.\r\n", argv[5]);
    n = write(sock, buffer, strlen(buffer));
    if(n < 0)
        error("ERROR writing to socket");
    memset(buffer, 0, 2000);
    n = read(sock, buffer, 2000);
    if(n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    sprintf(buffer, "QUIT\r\n");
    n = write(sock, buffer, strlen(buffer));
    if(n < 0)
        error("ERROR writing to socket");
    memset(buffer, 0, 2000);
    n = read(sock, buffer, 2000);
    if(n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    close(sock);
    return 0;
}
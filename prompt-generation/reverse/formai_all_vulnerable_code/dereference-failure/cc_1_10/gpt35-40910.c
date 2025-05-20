//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char message[BUFSIZE];
    char response[BUFSIZE];
    int msg_len;

    if (argc != 3) {
        printf("Usage: %s <server IP> <server port>\n", argv[0]);
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        error("socket() failed");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2])) ;

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("connect() failed");

    recv(sock , response , BUFSIZE , 0);
    printf("%s\n",response);

    sprintf(message,"USER username\r\n");
    send(sock , message , strlen(message) , 0);

    recv(sock , response , BUFSIZE , 0);
    printf("%s\n",response);

    sprintf(message,"PASS password\r\n");
    send(sock , message , strlen(message) , 0);

    recv(sock , response , BUFSIZE , 0);
    printf("%s\n",response);

    sprintf(message,"STAT\r\n");
    send(sock , message , strlen(message) , 0);

    recv(sock , response , BUFSIZE , 0);
    printf("%s\n",response);

    sprintf(message,"QUIT\r\n");
    send(sock , message , strlen(message) , 0);

    recv(sock , response , BUFSIZE , 0);
    printf("%s\n",response);

    close(sock);
    exit(0);
}
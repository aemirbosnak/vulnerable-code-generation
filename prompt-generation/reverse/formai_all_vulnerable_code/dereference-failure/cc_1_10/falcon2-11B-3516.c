//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 110
#define MAXLINE 512

int main()
{
    // create socket
    int sockfd;
    struct sockaddr_in server;
    struct hostent *server_host;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        return 1;
    }

    // server hostname
    char hostname[] = "pop3.example.com";
    server_host = gethostbyname(hostname);
    if (server_host == NULL)
    {
        fprintf(stderr, "ERROR: hostname not found (%s)\n", hostname);
        return 1;
    }

    // fill server address struct
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy((char *) &server.sin_addr.s_addr, (char *) server_host->h_addr, server_host->h_length);

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0)
    {
        perror("connect failed");
        return 1;
    }

    // initialize buffer
    char line[MAXLINE];
    int line_len;
    char *pos;

    // login
    pos = (char *) malloc(MAXLINE);
    sprintf(pos, "USER %s\r\n", "username");
    line_len = strlen(pos);
    send(sockfd, pos, line_len, 0);
    recv(sockfd, line, MAXLINE, 0);
    printf("%s\n", line);

    // fetch emails
    pos = (char *) malloc(MAXLINE);
    sprintf(pos, "PASS %s\r\n", "password");
    line_len = strlen(pos);
    send(sockfd, pos, line_len, 0);
    recv(sockfd, line, MAXLINE, 0);
    printf("%s\n", line);

    // loop to fetch emails
    int count = 0;
    while (1)
    {
        pos = (char *) malloc(MAXLINE);
        sprintf(pos, "RETR %d\r\n", count);
        line_len = strlen(pos);
        send(sockfd, pos, line_len, 0);
        recv(sockfd, line, MAXLINE, 0);
        printf("%s\n", line);
        count++;
    }

    free(pos);
    return 0;
}
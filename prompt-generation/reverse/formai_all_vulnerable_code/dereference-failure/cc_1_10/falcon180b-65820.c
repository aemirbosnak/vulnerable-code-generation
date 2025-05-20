//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n, valread;
    char *ptr;

    if (argc < 4)
    {
        printf("Usage:./smtp_client <server_ip> <server_port> <message_file>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error: Unable to create socket.\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error: Unable to connect to server.\n");
        exit(0);
    }

    FILE *fp;
    fp = fopen(argv[3], "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open message file.\n");
        exit(0);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL)
    {
        n = strlen(line);
        line[n] = '\r';
        line[n+1] = '\n';
        line[n+2] = '\0';
        send(sockfd, line, strlen(line), 0);
    }

    fclose(fp);

    close(sockfd);

    return 0;
}
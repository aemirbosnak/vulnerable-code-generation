//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    int port;
    char *ip;
    char buffer[BUF_SIZE];
    int bytes_received;
    FILE *fp;

    if (argc!= 4)
    {
        printf("Usage:./ftp_client <IP Address> <Port Number> <File Name>\n");
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);
    char *filename = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error: Socket Creation Failed!\n");
        exit(1);
    }

    printf("Socket Created Successfully!\n");

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        printf("Error: Connection Failed!\n");
        exit(1);
    }

    printf("Connected to Server!\n");

    fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        printf("Error: File Creation Failed!\n");
        exit(1);
    }

    printf("File Created Successfully!\n");

    while ((bytes_received = recv(sockfd, buffer, BUF_SIZE, 0)) > 0)
    {
        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);

    if (bytes_received == -1)
    {
        printf("Error: Data Transfer Failed!\n");
        exit(1);
    }

    printf("Data Transfer Completed Successfully!\n");

    close(sockfd);

    return 0;
}
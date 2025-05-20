//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

void ftp_error(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in addr;
    int sockfd, port, n;
    char buffer[BUF_SIZE];
    char* hostname = argv[1];
    int portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        ftp_error("Error in socket creation");

    addr.sin_family = AF_INET;
    addr.sin_port = htons(portno);
    addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
        ftp_error("Error in connect");

    printf("Connected to %s on port %d\n", hostname, portno);

    char command[BUF_SIZE];
    memset(command, 0, sizeof(command));
    strcpy(command, "USER anonymous");
    if (send(sockfd, command, strlen(command), 0) < 0)
        ftp_error("Error sending command");

    memset(command, 0, sizeof(command));
    strcpy(command, "PASS ");
    strcat(command, "password");
    if (send(sockfd, command, strlen(command), 0) < 0)
        ftp_error("Error sending command");

    memset(command, 0, sizeof(command));
    strcpy(command, "SYST");
    if (send(sockfd, command, strlen(command), 0) < 0)
        ftp_error("Error sending command");

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0)
        ftp_error("Error receiving data");

    printf("Server reply: %s\n", buffer);

    memset(command, 0, sizeof(command));
    strcpy(command, "LIST");
    if (send(sockfd, command, strlen(command), 0) < 0)
        ftp_error("Error sending command");

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0)
        ftp_error("Error receiving data");

    printf("Server reply: %s\n", buffer);

    memset(command, 0, sizeof(command));
    strcpy(command, "RETR ");
    strcat(command, "example.txt");
    if (send(sockfd, command, strlen(command), 0) < 0)
        ftp_error("Error sending command");

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0)
        ftp_error("Error receiving data");

    printf("Server reply: %s\n", buffer);

    FILE *fp;
    fp = fopen("example.txt", "wb");
    if (fp == NULL)
        ftp_error("Error opening file");

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0)
        ftp_error("Error receiving data");

    fwrite(buffer, strlen(buffer), 1, fp);

    if (fclose(fp) < 0)
        ftp_error("Error closing file");

    close(sockfd);

    return 0;
}
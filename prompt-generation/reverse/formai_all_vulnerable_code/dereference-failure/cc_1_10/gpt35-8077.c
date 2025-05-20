//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

void ftpClient(int sockfd) {
    char buff[MAXLINE];
    int n;
    while (1) {
        bzero(buff, sizeof(buff));
        printf("FTP Client: ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("FTP Server: %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("FTP Client: Exiting...\n");
            break;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./ftpclient <IPaddress> <Port>\n");
        return -1;
    }
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("FTP Client: Could not create socket\n");
        return -1;
    }
    else {
        printf("FTP Client: Socket created\n");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("FTP Client: Could not connect to server\n");
        return -1;
    }
    else {
        printf("FTP Client: Connected to server\n");
    }
    ftpClient(sockfd);
    close(sockfd);
    return 0;
}
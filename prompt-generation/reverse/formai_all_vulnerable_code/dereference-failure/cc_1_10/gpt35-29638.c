//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 1024
#define PORT 21

void getResponse(int sock, char *buffer) {
    int len = recv(sock, buffer, MAXLINE, 0);
    buffer[len] = '\0';
    printf("%s", buffer);
}

int main(int argc, char **argv) {
    int sockfd, errcode;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;
    struct hostent *host;
    char recvbuffer[MAXLINE];
    char user[MAXLINE] = "anonymous";
    char password[MAXLINE] = "";
    char filename[MAXLINE] = "file.txt";
    int fd;
    int bytesrecv = 0;
    int n = 1;

    if(argc < 2) {
        printf("Please enter server address.\n");
        exit(0);
    }

    if((host=gethostbyname(argv[1])) == NULL) {
        printf("Cannot resolve hostname.\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr = *((struct in_addr*)host->h_addr);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Cannot create socket.\n");
        exit(0);
    }

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Cannot connect to server.\n");
        exit(0);
    }

    getResponse(sockfd, buffer);
    sprintf(buffer, "USER %s\r\n", user);
    send(sockfd, buffer, strlen(buffer), 0);
    getResponse(sockfd, buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    getResponse(sockfd, buffer);

    sprintf(buffer, "TYPE I\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    getResponse(sockfd, buffer);

    sprintf(buffer, "PASV\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    getResponse(sockfd, buffer);

    int ports[6];
    char *token = strtok(buffer, ",");
    int i = 0;
    while(token != NULL) {
        ports[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }

    int port = ports[4] * 256 + ports[5];
    printf("Using port %d\n", port);

    struct sockaddr_in dataSockAddr;
    memset(&dataSockAddr, 0, sizeof(dataSockAddr));
    dataSockAddr.sin_family = AF_INET;
    dataSockAddr.sin_addr.s_addr = servaddr.sin_addr.s_addr;
    dataSockAddr.sin_port = htons(port);

    int dataSock = socket(AF_INET, SOCK_STREAM, 0);
    if(dataSock < 0) {
        printf("Cannot create data socket.\n");
        exit(0);
    }

    if(connect(dataSock, (struct sockaddr*)&dataSockAddr, sizeof(dataSockAddr)) < 0) {
        printf("Cannot connect to data port.\n");
        exit(0);
    }

    sprintf(buffer, "RETR %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);
    getResponse(sockfd, buffer);
    if(strncmp(buffer, "550", 3) == 0) {
        printf("Could not find file on server.\n");
        exit(0);
    }

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd < 0) {
        printf("Cannot open file for writing.\n");
        exit(0);
    }

    int flags = fcntl(dataSock, F_GETFL, 0);
    fcntl(dataSock, F_SETFL, flags | O_NONBLOCK);

    while(n > 0) {
        n = read(dataSock, recvbuffer, MAXLINE);
        if(n > 0) {
            bytesrecv += n;
            write(fd, recvbuffer, n);
        } else {
            if(errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            } else {
                printf("Error receiving file.\n");
                exit(0);
            }
        }
    }

    printf("File received! Bytes: %d\n", bytesrecv);
    close(fd);

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    getResponse(sockfd, buffer);

    close(sockfd);

    return 0;
}
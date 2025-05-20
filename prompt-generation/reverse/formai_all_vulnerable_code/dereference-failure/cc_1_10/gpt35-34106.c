//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char **argv) {
    int sockfd, connect_status, port;
    char buffer[MAXSIZE], filename[MAXSIZE];
    struct sockaddr_in serveraddr;
    socklen_t addrlen;
    FILE *fp;

    if(argc != 4) {
        printf("Usage: %s <ip address> <port> <filename>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Error in creating socket");
        exit(1);
    }

    port = atoi(argv[2]);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);

    connect_status = inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);
    if(connect_status <= 0) {
        perror("Error in converting IP address");
        exit(1);
    }

    addrlen = sizeof(serveraddr);

    connect_status = connect(sockfd, (struct sockaddr*)&serveraddr, addrlen);
    if(connect_status < 0) {
        perror("Error in connecting to FTP server");
        exit(1);
    }

    strcpy(filename, argv[3]);

    send(sockfd, filename, strlen(filename), 0);

    fp = fopen(filename, "wb");
    if(fp == NULL) {
        perror("Error in opening file");
        exit(1);
    }

    while(1) {
        int bytes_recv = recv(sockfd, buffer, MAXSIZE, 0);
        if(bytes_recv == 0) {
            break;
        }
        if(bytes_recv < 0) {
            perror("Error in receiving file contents");
            exit(1);
        }
        fwrite(buffer, 1, bytes_recv, fp);
    }

    fclose(fp);
    close(sockfd);

    printf("File received successfully!\n");

    return 0;
}
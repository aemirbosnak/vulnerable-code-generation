//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[MAX_LINE];
    char *ptr;
    int n;
    int err;
    
    if (argc!= 4) {
        printf("Usage:./smtp_client [IP address] [port number] [file name]\n");
        exit(0);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }
    
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }
    
    FILE *fp;
    fp = fopen(argv[3], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    
    char *header = "From: sender@example.com\r\n";
    char *subject = "Subject: Test message\r\n";
    char *body = "This is a test message.\r\n";
    
    send(sockfd, header, strlen(header), 0);
    send(sockfd, subject, strlen(subject), 0);
    send(sockfd, "Content-Type: text/plain\r\nContent-Transfer-Encoding: 7bit\r\n\r\n", strlen("Content-Type: text/plain\r\nContent-Transfer-Encoding: 7bit\r\n\r\n"), 0);
    
    while ((n = fread(buffer, 1, MAX_LINE, fp)) > 0) {
        buffer[n] = '\0';
        send(sockfd, buffer, n, 0);
    }
    
    fclose(fp);
    close(sockfd);
    
    return 0;
}
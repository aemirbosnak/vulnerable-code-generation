//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define MAX_LINE 1024
#define USER "anonymous"
#define PASS "anonymous@example.com"

int main(int argc, char *argv[]) {
    char hostname[64];
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    char *token;
    FILE *fp;
    int dataconn;

    // Get hostname from command line argument
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(0);
    }
    strcpy(hostname, argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    // Set up server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    // Send username
    sprintf(sendline, "USER %s\r\n", USER);
    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);

    // Send password
    sprintf(sendline, "PASS %s\r\n", PASS);
    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);

    // Change to passive mode
    sprintf(sendline, "PASV\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);
    token = strtok(recvline, " ");
    sprintf(sendline, "RETR %s\r\n", token);
    send(sockfd, sendline, strlen(sendline), 0);

    // Open local file for writing
    fp = fopen("download.txt", "wb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    // Set up data connection
    dataconn = accept(sockfd, NULL, NULL);
    if (dataconn < 0) {
        printf("Error accepting data connection\n");
        exit(0);
    }

    // Receive and write file data
    while ((n = recv(dataconn, recvline, MAX_LINE, 0)) > 0) {
        fwrite(recvline, 1, n, fp);
    }

    // Close connections and exit
    close(sockfd);
    close(dataconn);
    fclose(fp);
    exit(0);
}
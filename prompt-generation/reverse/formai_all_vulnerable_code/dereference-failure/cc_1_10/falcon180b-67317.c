//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USERNAME "anonymous"
#define PASSWORD "anonymous@example.com"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *filename = "file.txt";
    char *command = "RETR ";
    char *username = USERNAME;
    char *password = PASSWORD;
    FILE *fp;

    printf("Building a FTP Client example program\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    portno = PORT;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Connected to server\n");

    printf("Logging in as %s\n", username);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    printf("Logging in successful\n");

    strcat(command, filename);
    send(sockfd, command, strlen(command), 0);

    printf("Retrieving file %s\n", filename);

    fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Could not open file for writing\n");
        exit(1);
    }

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, n, fp);
    }

    printf("File retrieved successfully\n");

    close(sockfd);
    close(fp);

    return 0;
}
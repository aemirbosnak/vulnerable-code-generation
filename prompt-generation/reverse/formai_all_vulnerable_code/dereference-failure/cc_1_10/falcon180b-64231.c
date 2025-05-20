//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];

    if (argc!= 4) {
        printf("Usage:./client <server_ip> <server_port> <message_file>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        printf("Error opening message file\n");
        exit(1);
    }

    char message[BUF_SIZE];
    while (fgets(message, BUF_SIZE, fp)!= NULL) {
        send(sockfd, message, strlen(message), 0);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}
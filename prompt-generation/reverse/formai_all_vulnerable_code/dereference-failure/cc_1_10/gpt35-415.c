//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char filename[100];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    printf("Please enter the filename: ");
    scanf("%s", filename);

    strcpy(buffer, "get ");
    strcat(buffer, filename);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket");
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        error("Error reading from socket");
    }

    if (strcmp(buffer, "File not found") == 0) {
        printf("%s\n", buffer);
    } else {
        printf("File contents:\n");
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}
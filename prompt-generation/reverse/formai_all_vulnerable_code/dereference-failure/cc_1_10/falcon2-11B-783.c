//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to server!\n");

    while (1) {
        n = read(sockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("%s", buffer);

        char cmd[BUFFER_SIZE];
        fgets(cmd, BUFFER_SIZE, stdin);
        if (strcmp(cmd, "quit") == 0) {
            break;
        }

        n = write(sockfd, cmd, strlen(cmd));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}
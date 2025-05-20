//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 110
#define MAXLINE 80

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[MAXLINE];
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname("mail.example.com");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&servaddr.sin_addr.s_addr,
         server->h_length);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    write(sockfd, "+OK POP3d/1.0\r\n", 13);
    write(sockfd, argv[1], strlen(argv[1]) + 1);
    write(sockfd, argv[2], strlen(argv[2]) + 1);

    while (1) {
        n = recv(sockfd, buffer, MAXLINE, 0);
        if (n > 0) {
            printf("%s", buffer);
            if (strstr(buffer, "+OK") != NULL) {
                char cmd[MAXLINE];
                printf("Enter command: ");
                scanf("%s", cmd);

                write(sockfd, cmd, strlen(cmd) + 1);
                if (strcmp(cmd, "QUIT") == 0) {
                    break;
                }
            }
        } else if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}
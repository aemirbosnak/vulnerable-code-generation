//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    if (argc != 3) {
        printf("Usage: %s <hostname/IP> <username> <password>\n", argv[0]);
        exit(1);
    }

    portno = PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    write(sockfd, "+OK POP3d v1.00\r\n", strlen("+OK POP3d v1.00\r\n"));
    write(sockfd, "USER ", 5);
    write(sockfd, argv[2], strlen(argv[2]));
    write(sockfd, "\r\n", 2);

    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);

    if (strncmp(buffer, "-ERR", 4) == 0) {
        perror("Error: Username/Password Incorrect");
        close(sockfd);
        exit(1);
    }

    write(sockfd, "PASS ", 5);
    write(sockfd, argv[3], strlen(argv[3]));
    write(sockfd, "\r\n", 2);

    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);

    if (strncmp(buffer, "+OK", 2) != 0) {
        perror("Error: Username/Password Incorrect");
        close(sockfd);
        exit(1);
    }

    write(sockfd, "LIST\r\n", 5);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);

        if (n <= 0) {
            if (feof(stdin)) {
                close(sockfd);
                exit(0);
            } else {
                perror("Error reading from socket");
                close(sockfd);
                exit(1);
            }
        }

        if (strstr(buffer, ".") != NULL) {
            fwrite(buffer, n, 1, stdout);
            continue;
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}
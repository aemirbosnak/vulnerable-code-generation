//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFFER 2048

int sockfd, n;
char buffer[MAX_BUFFER];
struct sockaddr_in servaddr;

void send_mail(int sockfd)
{
    char helo[1024];
    printf("Enter your HELO message: ");
    fgets(helo, sizeof(helo), stdin);
    strcat(helo, "\r\n");
    write(sockfd, helo, strlen(helo));

    while (1) {
        memset(buffer, 0, MAX_BUFFER);
        printf("Enter your message: ");
        fgets(buffer, sizeof(buffer), stdin);
        strcat(buffer, "\r\n");
        if (strcmp(buffer, "QUIT\r\n") == 0) {
            write(sockfd, buffer, strlen(buffer));
            break;
        }
        write(sockfd, buffer, strlen(buffer));
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s [IP address] [Port]\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) != 1) {
        printf("Error: invalid IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1) {
        printf("Error: could not set socket to non blocking mode\n");
        exit(1);
    }

    printf("Connected to server %s:%s\n", argv[1], argv[2]);

    while (1) {
        memset(buffer, 0, MAX_BUFFER);
        n = read(sockfd, buffer, MAX_BUFFER);
        if (n == -1 && errno != EWOULDBLOCK) {
            printf("Error: could not read from socket\n");
            exit(1);
        }
        if (n > 0) {
            printf("%s", buffer);
        }
        send_mail(sockfd);
    }

    close(sockfd);
    return 0;
}
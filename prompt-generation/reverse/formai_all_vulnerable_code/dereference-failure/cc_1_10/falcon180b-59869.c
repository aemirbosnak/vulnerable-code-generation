//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAXLINE 1024
#define POP3_PORT 110
#define USERNAME "username"
#define PASSWORD "password"

int main() {
    int sockfd;
    struct addrinfo hints, *res;
    char hostname[] = "localhost";
    char buffer[MAXLINE];
    int n;
    int total_bytes_received = 0;
    int total_bytes_sent = 0;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo(hostname, "pop3", &hints, &res))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    connect(sockfd, res->ai_addr, res->ai_addrlen);

    freeaddrinfo(res);

    while (1) {
        printf("Enter command (quit to exit): ");
        fgets(buffer, MAXLINE, stdin);
        total_bytes_sent += strlen(buffer);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n == -1) {
            perror("send");
            exit(1);
        }
        total_bytes_sent += n;

        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, MAXLINE, 0);
        if (n == -1) {
            perror("recv");
            exit(1);
        }
        total_bytes_received += n;

        printf("Received: %s", buffer);
    }

    close(sockfd);

    printf("Total bytes sent: %d\n", total_bytes_sent);
    printf("Total bytes received: %d\n", total_bytes_received);

    return 0;
}
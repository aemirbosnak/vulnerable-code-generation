//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    struct hostent *host = gethostbyname("ftp.example.com");
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buf[1024];
    while (1) {
        bzero(buf, sizeof(buf));
        printf("ftp> ");
        fgets(buf, sizeof(buf), stdin);
        if (strcmp(buf, "quit\n") == 0) {
            break;
        }
        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            return EXIT_FAILURE;
        }
        bzero(buf, sizeof(buf));
        if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }
        printf("%s", buf);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}
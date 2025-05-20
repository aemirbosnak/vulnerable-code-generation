//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1025];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s\n", inet_ntoa(serv_addr.sin_addr));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = read(sockfd, buffer, 1024);
        if (n < 0) {
            perror("read failed");
            exit(1);
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}
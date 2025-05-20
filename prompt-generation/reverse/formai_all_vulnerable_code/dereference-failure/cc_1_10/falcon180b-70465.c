//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define TRUE   1
#define FALSE  0
#define PORT "80"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *host;
    int opt = 1;

    if (argc!= 2) {
        printf("Usage:./a.out <IP address>\n");
        return 1;
    }

    host = argv[1];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(errno);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(errno);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = htons(80);
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &serv_addr.sin_addr);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(errno);
    }

    while (TRUE) {
        bzero(buffer, BUFFER_SIZE);
        ret = read(sockfd, buffer, BUFFER_SIZE);
        if (ret <= 0) {
            printf("Read error\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}
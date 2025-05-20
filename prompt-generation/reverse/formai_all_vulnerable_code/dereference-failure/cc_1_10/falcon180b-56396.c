//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT "3490"

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, addrlen, opt = 1;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    char *hostname = argv[1];
    int portno = atoi(PORT);

    if (argc!= 2) {
        printf("Usage:./wifi_analyzer <hostname>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(errno);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(errno);
    }

    printf("Connected to %s:%d\n", hostname, portno);

    while(1) {
        memset(buffer, 0, BUF_SIZE);
        if(recv(sockfd, buffer, BUF_SIZE, 0) <= 0) {
            printf("Disconnected from server\n");
            close(sockfd);
            exit(0);
        }
        printf("%s", buffer);
    }

    return 0;
}
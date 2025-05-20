//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 8080
#define ALLOWED_IPS "192.168.1.100"
#define BLOCKED_IPS "192.168.1.101"

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int addrlen = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding to port\n");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        char *ip = inet_ntoa(cli_addr.sin_addr);
        if (strcmp(ip, ALLOWED_IPS) == 0) {
            printf("Connection allowed from %s\n", ip);
        } else if (strcmp(ip, BLOCKED_IPS) == 0) {
            printf("Connection blocked from %s\n", ip);
            close(newsockfd);
            continue;
        } else {
            printf("Connection allowed from %s\n", ip);
        }

        close(newsockfd);
    }

    return 0;
}
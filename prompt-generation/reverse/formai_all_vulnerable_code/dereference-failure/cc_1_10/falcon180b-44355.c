//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 143
#define IMAP_SERVER "localhost"

char* username = "your_username";
char* password = "your_password";

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[BUF_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        printf("Waiting for a connection...\n");
        socklen_t addr_size = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &addr_size);

        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection established with %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        char* login_req = "LOGIN ";
        strcat(login_req, username);
        strcat(login_req, " ");
        strcat(login_req, password);
        strcat(login_req, "\r\n");

        send(newsockfd, login_req, strlen(login_req), 0);

        char* response = "";
        while (recv(newsockfd, buffer, BUF_SIZE, 0) > 0) {
            strcat(response, buffer);
        }

        printf("Server response: %s\n", response);

        close(newsockfd);
    }

    return 0;
}
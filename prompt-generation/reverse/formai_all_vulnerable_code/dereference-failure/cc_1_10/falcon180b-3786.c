//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

void error_handling(const char *message);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct hostent *host;
    host = gethostbyname(server_address);

    if (host == NULL) {
        error_handling("Invalid server address");
    }

    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        error_handling("Failed to create socket");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("Failed to connect to server");
    }

    char *login_message = "USER ";
    strcat(login_message, username);
    strcat(login_message, "\r\n");

    if (send(sockfd, login_message, strlen(login_message), 0) == -1) {
        error_handling("Failed to send login message");
    }

    char *password_message = "PASS ";
    strcat(password_message, password);
    strcat(password_message, "\r\n");

    if (send(sockfd, password_message, strlen(password_message), 0) == -1) {
        error_handling("Failed to send password message");
    }

    char buffer[MAXLINE];
    while (fgets(buffer, MAXLINE, stdin)!= NULL) {
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            error_handling("Failed to send command");
        }
    }

    close(sockfd);

    return 0;
}

void error_handling(const char *message) {
    perror(message);
    exit(1);
}
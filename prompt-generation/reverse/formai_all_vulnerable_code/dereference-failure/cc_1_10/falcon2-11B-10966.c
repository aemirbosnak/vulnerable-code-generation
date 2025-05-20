//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAXLINE 1024
#define HOST "smtp.gmail.com"
#define PORT 587

int deleteOldEmails() {
    // Connect to the email server
    int sockfd, new_sockfd;
    struct sockaddr_in server;
    struct hostent* server_address;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_address = gethostbyname(HOST);
    if (server_address == NULL) {
        fprintf(stderr, "Error: host not found\n");
        exit(EXIT_FAILURE);
    }

    bzero((char*)&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    bcopy((char*)server_address->h_addr, (char*)&server.sin_addr.s_addr, server_address->h_length);

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char* message = "DELETE /INBOX/*.30\r\n";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_sockfd = accept(sockfd, NULL, NULL)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        if (new_sockfd < 0) {
            break;
        }
        close(sockfd);
        sockfd = new_sockfd;
    }

    char response[MAXLINE];
    if (recv(sockfd, response, MAXLINE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    close(sockfd);
    return 0;
}

int main() {
    deleteOldEmails();
    return 0;
}
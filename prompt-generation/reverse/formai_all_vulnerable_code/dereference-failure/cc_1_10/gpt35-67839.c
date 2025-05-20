//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFF_SIZE 1024
#define CRLF "\r\n"

int main(int argc, char *argv[]) {

    int sockfd, num_bytes;
    char buffer[MAX_BUFF_SIZE], response[MAX_BUFF_SIZE];
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if (argc < 3) {
        printf("Please provide arguments as: ./imap_client [HOST] [PORT]\n");
        return -1;
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket.\n");
        return -1;
    }

    // resolve hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Failed to resolve host.\n");
        return -1;
    }

    // set address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to server.\n");
        return -1;
    }

    // receive server greeting
    recv(sockfd, response, MAX_BUFF_SIZE, 0);
    printf("%s", response); // hello from server

    // send login credentials
    sprintf(buffer, "LOGIN %s %s" CRLF, "username", "password");
    send(sockfd, buffer, strlen(buffer), 0);

    // receive login response
    recv(sockfd, response, MAX_BUFF_SIZE, 0);
    printf("%s", response); // login successful

    // select mailbox
    sprintf(buffer, "SELECT INBOX" CRLF);
    send(sockfd, buffer, strlen(buffer), 0);

    // receive SELECT response
    recv(sockfd, response, MAX_BUFF_SIZE, 0);
    printf("%s", response); // mailbox selected

    // fetch emails
    sprintf(buffer, "FETCH 1:* FULL" CRLF);
    send(sockfd, buffer, strlen(buffer), 0);

    // receive FETCH response
    while ((num_bytes = recv(sockfd, response, MAX_BUFF_SIZE, 0)) > 0) {
        response[num_bytes] = '\0';
        printf("%s", response); // show email content
    }

    // logout and close socket
    sprintf(buffer, "LOGOUT" CRLF);
    send(sockfd, buffer, strlen(buffer), 0);
    close(sockfd);

    return 0;
}
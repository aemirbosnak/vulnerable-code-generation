//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SERVER_PORT 143
#define MAX_RESPONSE_SIZE 4096

char *username, *password, *mailbox;
int sockfd;

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <username> <password> <mailbox>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    username = argv[1];
    password = argv[2];
    mailbox = argv[3];

    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("socket");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);

    struct hostent *server = gethostbyname("localhost");
    if (server == NULL)
        error("gethostbyname");

    memcpy(&servaddr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        error("connect");

    char response[MAX_RESPONSE_SIZE];
    int n;

    // Read the welcome message
    n = recv(sockfd, response, MAX_RESPONSE_SIZE, 0);
    if (n < 0)
        error("recv");

    printf("%s", response);
   
    // Send the username
    sprintf(response, "USER %s\r\n", username);
    n = send(sockfd, response, strlen(response), 0);
    if (n < 0)
        error("send");

    // Read the response
    n = recv(sockfd, response, MAX_RESPONSE_SIZE, 0);
    if (n < 0)
        error("recv");

    printf("%s", response);

    // Send the password
    sprintf(response, "PASS %s\r\n", password);
    n = send(sockfd, response, strlen(response), 0);
    if (n < 0)
        error("send");

    // Read the response
    n = recv(sockfd, response, MAX_RESPONSE_SIZE, 0);
    if (n < 0)
        error("recv");

    printf("%s", response);

    // Send the mailbox
    sprintf(response, "SELECT %s\r\n", mailbox);
    n = send(sockfd, response, strlen(response), 0);
    if (n < 0)
        error("send");

    // Read the response
    n = recv(sockfd, response, MAX_RESPONSE_SIZE, 0);
    if (n < 0)
        error("recv");

    printf("%s", response);

    // List the messages
    sprintf(response, "LIST \"\" *\r\n");
    n = send(sockfd, response, strlen(response), 0);
    if (n < 0)
        error("send");

    // Read the response
    while ((n = recv(sockfd, response, MAX_RESPONSE_SIZE, 0)) > 0) {
        printf("%s", response);
    }
    if (n < 0)
        error("recv");

    // Close the connection
    close(sockfd);
    return 0;
}
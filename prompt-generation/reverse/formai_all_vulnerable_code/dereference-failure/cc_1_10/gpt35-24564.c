//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    // initialize variables
    char* host = "pop.example.com";
    char* username = "user";
    char* password = "password";
    char buffer[MAX_BUFFER_SIZE];
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    // open socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR: Failed to open socket.");
    }

    // get server address
    server = gethostbyname(host);
    if (server == NULL) {
        error("ERROR: Could not find server.");
    }

    // set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(110);    // POP3 port

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR: Could not connect to server.");
    }

    // receive connection message
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // send login credentials
    send(sockfd, "USER ", strlen("USER "), 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    send(sockfd, "PASS ", strlen("PASS "), 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // request list of emails
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // print list of emails
    printf("List of emails:\n%s", buffer);

    // close socket
    close(sockfd);

    return 0;
}
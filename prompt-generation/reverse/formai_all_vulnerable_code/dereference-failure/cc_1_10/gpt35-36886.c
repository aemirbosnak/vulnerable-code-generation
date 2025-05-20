//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFF_SIZE 1024

// The POP3 server's IP address and port number
#define SERVER_ADDR "mail.example.com"
#define SERVER_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buff[BUFF_SIZE], user[BUFF_SIZE], pass[BUFF_SIZE];

    // Get the server's IP address
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(0);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error: cannot open socket\n");

    // Initialize the server's address
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error: cannot connect to server\n");
    }

    // Get the server's welcome message
    bzero(buff, BUFF_SIZE);
    n = read(sockfd, buff, BUFF_SIZE-1);
    if (n < 0) error("Error: cannot read from socket\n");
    printf("%s\n", buff);

    // Ask the user for their username and password
    printf("What is your username, my dear friend? ");
    fgets(user, BUFF_SIZE-1, stdin);
    user[strcspn(user, "\n")] = 0; // remove the newline
    printf("And, pray tell me, what is your password? ");
    fgets(pass, BUFF_SIZE-1, stdin);
    pass[strcspn(pass, "\n")] = 0; // remove the newline

    // Send the user's username and password to the server
    bzero(buff, BUFF_SIZE);
    sprintf(buff, "USER %s\r\n", user);
    write(sockfd, buff, strlen(buff));
    n = read(sockfd, buff, BUFF_SIZE-1);
    if (n < 0) error("Error: cannot read from socket\n");
    printf("%s\n", buff);

    bzero(buff, BUFF_SIZE);
    sprintf(buff, "PASS %s\r\n", pass);
    write(sockfd, buff, strlen(buff));
    n = read(sockfd, buff, BUFF_SIZE-1);
    if (n < 0) error("Error: cannot read from socket\n");
    printf("%s\n", buff);

    // Ask the server for the number of messages in the user's mailbox
    bzero(buff, BUFF_SIZE);
    sprintf(buff, "STAT\r\n");
    write(sockfd, buff, strlen(buff));
    n = read(sockfd, buff, BUFF_SIZE-1);
    if (n < 0) error("Error: cannot read from socket\n");
    printf("%s\n", buff);

    // Close the connection
    close(sockfd);

    printf("Farewell, my dear friend!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
// Romeo and Juliet POP3 client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Function to print error messages
void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket.");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host.");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Error connecting to server.");

    // authentication with server
    char user[50], pass[50];
    printf("Enter username: ");
    fgets(user, 50, stdin);
    printf("Enter password: ");
    fgets(pass, 50, stdin);

    // send username to server
    bzero(buffer, 256);
    strncpy(buffer, "USER ", 256);
    strncat(buffer, user, 256 - strlen(buffer) - 1);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket.");

    // receive server response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("Error reading from socket.");
    printf("%s\n", buffer);

    // send password to server
    bzero(buffer, 256);
    strncpy(buffer, "PASS ", 256);
    strncat(buffer, pass, 256 - strlen(buffer) - 1);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket.");

    // receive server response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("Error reading from socket.");
    printf("%s\n", buffer);

    // check if login was successful
    if (strncmp(buffer, "+OK", 3) != 0)
        error("Authentication failed.");

    // download all messages
    bzero(buffer, 256);
    strncpy(buffer, "LIST", 256);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket.");

    // receive server response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("Error reading from socket.");
    printf("%s\n", buffer);

    // display individual messages
    char msgid[10];
    printf("Enter message id to download (or type 'q' to quit): ");
    fgets(msgid, 10, stdin);
    while (strncmp(msgid, "q", 1) != 0) {
        // send command to server
        bzero(buffer, 256);
        strncpy(buffer, "RETR ", 256);
        strncat(buffer, msgid, 256 - strlen(buffer) - 1);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("Error writing to socket.");

        // receive server response
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);
        if (n < 0)
            error("Error reading from socket.");
        printf("%s\n", buffer);

        // receive message body
        bzero(buffer, 256);
        while (1) {
            n = read(sockfd, buffer, 255);
            if (n < 0)
                error("Error reading from socket.");
            printf("%s", buffer);
            if (strstr(buffer, "\r\n.\r\n") != NULL)
                break;
            bzero(buffer, 256);
        }
        printf("\n");
        printf("Enter message id to download (or type 'q' to quit): ");
        fgets(msgid, 10, stdin);
    }

    // exit program
    bzero(buffer, 256);
    strncpy(buffer, "QUIT", 256);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket.");

    close(sockfd);
    return 0;
}
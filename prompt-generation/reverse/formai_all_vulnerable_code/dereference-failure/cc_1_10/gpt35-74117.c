//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024 // Maximum buffer size

int main(int argc, char* argv[]) {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        printf("Usage: %s <ip address> <port number>\n", argv[0]);
        exit(1);
    }

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) == 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    // Connecting to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection to server failed\n");
        exit(1);
    }

    // Receiving server greeting message
    if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
        printf("Error receiving message from server\n");
        exit(1);
    }
    printf("%s", buffer); // Printing server greeting message

    // Sending login credentials
    char username[MAXLINE], password[MAXLINE];
    printf("Enter username: ");
    fgets(username, MAXLINE, stdin);
    printf("Enter password: ");
    fgets(password, MAXLINE, stdin);

    char login[MAXLINE];
    sprintf(login, "USER %sPASS %s", username, password);
    send(sockfd, login, strlen(login), 0);

    // Response from server
    if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
        printf("Error receiving message from server\n");
        exit(1);
    }
    printf("\n%s\n", buffer);

    // Quitting the session
    char quit[] = "QUIT";
    send(sockfd, quit, strlen(quit), 0);
    close(sockfd);

    return 0;
}
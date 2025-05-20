//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 993

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Get hostname of the server
    char hostname[50];
    printf("Enter the hostname of the server: ");
    scanf("%s", hostname);
    server = gethostbyname(hostname);

    if (server == NULL) {
        perror("Error: ");
        exit(0);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: ");
        exit(0);
    }

    // Connect to server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error: ");
        exit(0);
    }

    // Read server response
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n",buffer);

    // Login credentials
    char username[50];
    char password[50];
    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Login
    char login[100];
    sprintf(login, "LOGIN %s %s\r\n", username, password);
    write(sockfd, login, strlen(login));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n", buffer);

    // Select inbox
    char select[50];
    sprintf(select, "SELECT INBOX\r\n");
    write(sockfd, select, strlen(select));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n", buffer);

    // Fetch emails
    char fetch[100];
    sprintf(fetch, "FETCH 1:10 BODY[HEADER.FIELDS (FROM DATE SUBJECT)]\r\n");
    write(sockfd, fetch, strlen(fetch));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n", buffer);

    // Logout
    char logout[50];
    sprintf(logout, "LOGOUT\r\n");
    write(sockfd, logout, strlen(logout));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}
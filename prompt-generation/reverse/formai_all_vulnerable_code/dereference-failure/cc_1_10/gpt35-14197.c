//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024
#define PORT 993

void print_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;
    struct hostent *host;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Get IP address from hostname */
    if ((host = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error getting IP address for %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Create socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        print_error("Error creating socket");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    memcpy(&servaddr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        print_error("Error connecting to server");
    }

    /* Receive server greeting */
    if ((n = read(sockfd, buffer, MAXLINE)) < 0) {
        print_error("Error reading from socket");
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    /* Send login information */
    char *username = "username";
    char *password = "password";
    char login_cmd[MAXLINE];
    sprintf(login_cmd, "LOGIN %s %s\r\n", username, password);
    write(sockfd, login_cmd, strlen(login_cmd));
    if ((n = read(sockfd, buffer, MAXLINE)) < 0) {
        print_error("Error reading from socket");
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    /* Select mailbox */
    char select_cmd[MAXLINE];
    sprintf(select_cmd, "SELECT INBOX\r\n");
    write(sockfd, select_cmd, strlen(select_cmd));
    if ((n = read(sockfd, buffer, MAXLINE)) < 0) {
        print_error("Error reading from socket");
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    /* Search for messages */
    char search_cmd[MAXLINE];
    sprintf(search_cmd, "SEARCH ALL\r\n");
    write(sockfd, search_cmd, strlen(search_cmd));
    if ((n = read(sockfd, buffer, MAXLINE)) < 0) {
        print_error("Error reading from socket");
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    /* Logout */
    char logout_cmd[MAXLINE];
    sprintf(logout_cmd, "LOGOUT\r\n");
    write(sockfd, logout_cmd, strlen(logout_cmd));
    if ((n = read(sockfd, buffer, MAXLINE)) < 0) {
        print_error("Error reading from socket");
    }

    close(sockfd);
    return 0;
}
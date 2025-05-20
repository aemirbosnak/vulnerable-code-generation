//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    char *hostname = "ftp.gnu.org";    // default hostname
    char *username = "anonymous";     // default username for anonymous FTP login
    char *password = "password";      // default password for anonymous FTP login

    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // get IP address from hostname
    struct hostent *he = gethostbyname(hostname);

    if (he == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    char *ip_addr = inet_ntoa(*addr_list[0]);

    // connect to the FTP server
    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip_addr);
    servaddr.sin_port = htons(21);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // send username
    char message[MAXLINE];
    snprintf(message, MAXLINE, "USER %s\r\n", username);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive response
    char response[MAXLINE];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("%s", response);

    // send password
    snprintf(message, MAXLINE, "PASS %s\r\n", password);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive response
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("%s", response);

    // send list command
    snprintf(message, MAXLINE, "LIST\r\n");
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive response
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("%s", response);

    // close the socket
    close(sockfd);

    return 0;
}
//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_RECV_BUF_SIZE 1024
#define MAX_SEND_BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char recv_buf[MAX_RECV_BUF_SIZE], send_buf[MAX_SEND_BUF_SIZE];
    struct sockaddr_in servaddr;

    // Creating the Socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Setting up the Server Address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110); // POP3 default port
    if (inet_pton(AF_INET, "pop3.server.com", &servaddr.sin_addr) <= 0) {
        perror("Error: Invalid server address");
        exit(EXIT_FAILURE);
    }

    // Establishing Connection with Server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error: Connection failed");
        exit(EXIT_FAILURE);
    }

    // Reading Server Response
    bzero(recv_buf, MAX_RECV_BUF_SIZE);
    if ((n = read(sockfd, recv_buf, MAX_RECV_BUF_SIZE)) < 0) {
        perror("Error: Cannot read server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buf);

    // Sending User Authentication
    bzero(send_buf, MAX_SEND_BUF_SIZE);
    sprintf(send_buf, "USER %s\r\n", "username");
    if (write(sockfd, send_buf, strlen(send_buf)) < 0) {
        perror("Error: Cannot write user authentication");
        exit(EXIT_FAILURE);
    }

    // Reading User Authentication Response
    bzero(recv_buf, MAX_RECV_BUF_SIZE);
    if ((n = read(sockfd, recv_buf, MAX_RECV_BUF_SIZE)) < 0) {
        perror("Error: Cannot read user authentication response");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buf);

    // Sending Password Authentication
    bzero(send_buf, MAX_SEND_BUF_SIZE);
    sprintf(send_buf, "PASS %s\r\n", "password");
    if (write(sockfd, send_buf, strlen(send_buf)) < 0) {
        perror("Error: Cannot write password authentication");
        exit(EXIT_FAILURE);
    }

    // Reading Password Authentication Response
    bzero(recv_buf, MAX_RECV_BUF_SIZE);
    if ((n = read(sockfd, recv_buf, MAX_RECV_BUF_SIZE)) < 0) {
        perror("Error: Cannot read password authentication response");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buf);

    // Quitting the Connection
    bzero(send_buf, MAX_SEND_BUF_SIZE);
    sprintf(send_buf, "QUIT\r\n");
    if (write(sockfd, send_buf, strlen(send_buf)) < 0) {
        perror("Error: Cannot write quit command");
        exit(EXIT_FAILURE);
    }

    close(sockfd);
    return 0;
}
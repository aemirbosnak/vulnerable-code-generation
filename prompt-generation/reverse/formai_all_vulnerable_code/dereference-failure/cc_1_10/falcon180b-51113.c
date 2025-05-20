//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024
#define SERVER "localhost"
#define PORT 110
#define USER "username"
#define PASS "password"

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUF_SIZE];
    int n;
    char *login_message;
    char *user_name;
    char *password;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error : Could not create socket \n");
        exit(1);
    }

    // Set up server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &servaddr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error : Could not connect to server \n");
        exit(1);
    }

    // Send login message
    login_message = "USER ";
    strcat(login_message, USER);
    strcat(login_message, "\r\n");
    send(sockfd, login_message, strlen(login_message), 0);

    // Receive server response
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    if (n <= 0) {
        printf("Error : Could not receive server response \n");
        exit(1);
    }
    printf("Server response : %s", buffer);

    // Send password message
    password = "PASS ";
    strcat(password, PASS);
    strcat(password, "\r\n");
    send(sockfd, password, strlen(password), 0);

    // Receive server response
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    if (n <= 0) {
        printf("Error : Could not receive server response \n");
        exit(1);
    }
    printf("Server response : %s", buffer);

    // Close socket
    close(sockfd);
    return 0;
}
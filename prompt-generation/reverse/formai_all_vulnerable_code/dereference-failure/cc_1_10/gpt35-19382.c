//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recv_buff[MAX_BUFF_SIZE];
    struct sockaddr_in servaddr;

    // Check for valid input
    if (argc != 3) {
        printf("Usage: %s <ServerIP> <PortNumber>\n", argv[0]);
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Configure server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("Invalid server address");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Receive greeting message from server
    bzero(recv_buff, MAX_BUFF_SIZE);
    n = recv(sockfd, recv_buff, MAX_BUFF_SIZE, 0);
    if (n < 0) {
        perror("Receive error");
        exit(1);
    }
    printf("%s", recv_buff);

    // Send login command
    char send_buff[MAX_BUFF_SIZE];
    sprintf(send_buff, "LOGIN %s %s\r\n", "username", "password");
    n = send(sockfd, send_buff, strlen(send_buff), 0);
    if (n < 0) {
        perror("Send error");
        exit(1);
    }

    // Receive login response from server
    bzero(recv_buff, MAX_BUFF_SIZE);
    n = recv(sockfd, recv_buff, MAX_BUFF_SIZE, 0);
    if (n < 0) {
        perror("Receive error");
        exit(1);
    }
    printf("%s", recv_buff);

    // Send logout command
    sprintf(send_buff, "LOGOUT\r\n");
    n = send(sockfd, send_buff, strlen(send_buff), 0);
    if (n < 0) {
        perror("Send error");
        exit(1);
    }

    // Receive logout response from server
    bzero(recv_buff, MAX_BUFF_SIZE);
    n = recv(sockfd, recv_buff, MAX_BUFF_SIZE, 0);
    if (n < 0) {
        perror("Receive error");
        exit(1);
    }
    printf("%s", recv_buff);

    // Close socket
    close(sockfd);

    return 0;
}
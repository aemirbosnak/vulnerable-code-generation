//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
// Build a POP3 Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024
#define SA struct sockaddr

void handle_error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port> <user_name>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation error");
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) < 0) {
        handle_error("Connection error");
    }

    sprintf(sendline, "USER %s\r\n", argv[3]);
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        handle_error("Send error");
    }

    if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
        handle_error("Receive error");
    }

    // Check if the server is ready for receiving password
    if (strncmp(recvline, "+OK", 3) != 0) {
        handle_error(recvline);
    }

    // Get password from user
    printf("Password: ");
    fgets(sendline, MAXLINE, stdin);
    sendline[strcspn(sendline, "\n")] = '\0';

    // Send password to server
    sprintf(sendline, "PASS %s\r\n", sendline);
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        handle_error("Send error");
    }

    if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
        handle_error("Receive error");
    }

    // Check if authentication was successful
    if (strncmp(recvline, "+OK", 3) != 0) {
        handle_error(recvline);
    }

    // List the emails
    sprintf(sendline, "LIST\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        handle_error("Send error");
    }

    if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
        handle_error("Receive error");
    }

    // Print the email list
    printf("%s", recvline);

    // Quit
    sprintf(sendline, "QUIT\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        handle_error("Send error");
    }

    if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
        handle_error("Receive error");
    }

    // Check if quitting was successful
    if (strncmp(recvline, "+OK", 3) != 0) {
        handle_error(recvline);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
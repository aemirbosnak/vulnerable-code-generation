//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server;
    char recv_buffer[MAX_BUFF_SIZE], send_buffer[MAX_BUFF_SIZE];
    int n;

    if (argc < 3) {
        printf("Usage: %s <server address> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Initialize socket address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        error("ERROR connecting");
    }

    // Read server response
    memset(recv_buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, recv_buffer, MAX_BUFF_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Print server greeting
    printf("Server says: %s\n", recv_buffer);

    // Send login credentials
    sprintf(send_buffer, "LOGIN %s %s\n", "username", "password");
    if (write(sockfd, send_buffer, strlen(send_buffer)) < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    memset(recv_buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, recv_buffer, MAX_BUFF_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Print server response
    printf("Server says: %s\n", recv_buffer);

    // Logout and close socket
    sprintf(send_buffer, "LOGOUT\n");
    if (write(sockfd, send_buffer, strlen(send_buffer)) < 0) {
        error("ERROR writing to socket");
    }

    close(sockfd);
    return 0;
}
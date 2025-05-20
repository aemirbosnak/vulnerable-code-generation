//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Function to connect to the IMAP server
int imap_connect(char* host, char* port) {
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(host, port, &hints, &res);
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    connect(sockfd, res->ai_addr, res->ai_addrlen);

    freeaddrinfo(res);

    return sockfd;
}

// Function to send commands to the IMAP server
int imap_send(int sockfd, char* cmd) {
    char buf[1024];
    sprintf(buf, "%s\r\n", cmd);

    int len = strlen(buf);
    if (send(sockfd, buf, len, 0) == len) {
        return 0;
    } else {
        return 1;
    }
}

// Function to receive data from the IMAP server
int imap_recv(int sockfd, char* buf, int len) {
    int bytes_received = 0;
    int status;

    while (bytes_received < len) {
        status = recv(sockfd, buf + bytes_received, len - bytes_received, 0);

        if (status == -1) {
            return 1;
        } else if (status == 0) {
            return 1;
        } else {
            bytes_received += status;
        }
    }

    return 0;
}

// Main function
int main(int argc, char* argv[]) {
    char* host = "imap.gmail.com";
    char* port = "993";
    char buf[1024];
    int sockfd;

    // Connect to the IMAP server
    sockfd = imap_connect(host, port);

    // Receive server greeting message
    imap_recv(sockfd, buf, sizeof(buf));
    printf("%s\n", buf);

    // Send login command
    imap_send(sockfd, "a login username password");

    // Receive server response
    imap_recv(sockfd, buf, sizeof(buf));
    printf("%s\n", buf);

    // Send list command
    imap_send(sockfd, "a list \"\" \"*\"");

    // Receive server response
    imap_recv(sockfd, buf, sizeof(buf));
    printf("%s\n", buf);

    // Send logout command
    imap_send(sockfd, "a logout");

    // Receive server response
    imap_recv(sockfd, buf, sizeof(buf));
    printf("%s\n", buf);

    close(sockfd);

    return 0;
}
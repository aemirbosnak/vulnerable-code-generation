//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buf[BUFSIZE + 1];

    if (argc != 3) {
        printf("Usage: %s [server] [port]\n", argv[0]);
        return 1;
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    // Fill in server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send IMAP login command
    memset(buf, 0, sizeof(buf));
    snprintf(buf, sizeof(buf), "1 login %s %s\r\n", "username", "password");
    int n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write");
        return 1;
    }

    // Read server response
    memset(buf, 0, sizeof(buf));
    n = read(sockfd, buf, BUFSIZE);
    if (n == -1) {
        perror("read");
        return 1;
    }

    printf("%s\n", buf);

    // Send IMAP select command to select a mailbox
    memset(buf, 0, sizeof(buf));
    snprintf(buf, sizeof(buf), "2 select inbox\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write");
        return 1;
    }

    // Read server response
    memset(buf, 0, sizeof(buf));
    n = read(sockfd, buf, BUFSIZE);
    if (n == -1) {
        perror("read");
        return 1;
    }

    printf("%s\n", buf);

    // Close socket
    close(sockfd);

    return 0;
}
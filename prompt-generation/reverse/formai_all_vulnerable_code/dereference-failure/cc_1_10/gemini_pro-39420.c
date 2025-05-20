//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define IMAP_PORT 143

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket to non-blocking mode
    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    // Connect to the server
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(IMAP_PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        if (errno != EINPROGRESS) {
            perror("connect");
            return 1;
        }
    }

    // Send the login command
    sprintf(buf, "LOGIN username password\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("%s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char message[BUFFER_SIZE];
    char *host;
    int port;

    // Check if user provided a host and port
    if (argc!= 4) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        printf("Invalid host or port\n");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send SMTP commands
    send(sockfd, "EHLO post-apocalyptic-world\r\n", strlen("EHLO post-apocalyptic-world\r\n"), 0);
    send(sockfd, "MAIL FROM: survivor@post-apocalyptic-world\r\n", strlen("MAIL FROM: survivor@post-apocalyptic-world\r\n"), 0);
    send(sockfd, "RCPT TO: recipient@post-apocalyptic-world\r\n", strlen("RCPT TO: recipient@post-apocalyptic-world\r\n"), 0);
    send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);

    // Send message
    sprintf(message, "Subject: Message from the wasteland\r\n\r\nHello, fellow survivor! We're still alive and kicking in this post-apocalyptic world. Stay safe out there.\r\n.\r\n");
    send(sockfd, message, strlen(message), 0);

    // Close socket
    close(sockfd);

    return 0;
}
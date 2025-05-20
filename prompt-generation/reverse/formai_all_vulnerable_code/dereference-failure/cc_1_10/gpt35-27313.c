//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLEN 1024
#define SERVER_PORT 25

int main(int argc, char *argv[]) {

    int sockfd;
    char buffer[MAXLEN], reply[MAXLEN];
    struct sockaddr_in server_address;
    struct hostent *host;

    // Get the server IP address from command line argument
    if (argc != 2) {
        fprintf(stderr, "usage: %s server_ip_address\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    // Get the server address from host name
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname error");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr = *((struct in_addr *) host->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connection error");
        exit(EXIT_FAILURE);
    }

    // Receive the banner message from the server
    memset(reply, 0, sizeof(reply));
    recv(sockfd, reply, sizeof(reply), 0);
    printf("%s", reply);

    // Send the HELO message to the server
    sprintf(buffer, "HELO client\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(reply, 0, sizeof(reply));
    recv(sockfd, reply, sizeof(reply), 0);
    printf("%s", reply);

    // Send the MAIL FROM message to the server
    sprintf(buffer, "MAIL FROM: <sender@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(reply, 0, sizeof(reply));
    recv(sockfd, reply, sizeof(reply), 0);
    printf("%s", reply);

    // Send the RCPT TO message to the server
    sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(reply, 0, sizeof(reply));
    recv(sockfd, reply, sizeof(reply), 0);
    printf("%s", reply);

    // Send the DATA message to the server
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(reply, 0, sizeof(reply));
    recv(sockfd, reply, sizeof(reply), 0);
    printf("%s", reply);

    // Send the message content to the server
    sprintf(buffer, "Subject: This is a test message\r\n\r\nThis is the body of the test message\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(reply, 0, sizeof(reply));
    recv(sockfd, reply, sizeof(reply), 0);
    printf("%s", reply);

    // Send the QUIT message to the server
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(reply, 0, sizeof(reply));
    recv(sockfd, reply, sizeof(reply), 0);
    printf("%s", reply);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}
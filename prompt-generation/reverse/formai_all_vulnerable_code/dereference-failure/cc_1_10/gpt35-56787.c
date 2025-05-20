//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 25
#define SURREAL_SMTP_SERVER "mx.surrealmail.net"

int main() {

    printf("Welcome to the Surrealist SMTP Client! Let's send some emails that are beyond the realm of reality.\n\n");

    // Create socket
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    } else {
        printf("Socket created successfully.\n");
    }

    // Fill server information
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    struct hostent *host = gethostbyname(SURREAL_SMTP_SERVER);

    if (host == NULL) {
        printf("Error: unable to resolve host.\n");
        exit(1);
    }

    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    // Establish connection
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Error: could not connect to server.\n");
        exit(1);
    } else {
        printf("Connected to Surreal SMTP server at %s.\n", SURREAL_SMTP_SERVER);
    }

    // Receive initial message from server
    char buffer[1024];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // HELO command
    char helo[50] = "HELO surrealmail.net\r\n";
    send(sockfd, helo, strlen(helo), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // MAIL FROM command
    char from[50] = "MAIL FROM:<dreamworld@surrealmail.net>\r\n";
    send(sockfd, from, strlen(from), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // RCPT TO command
    char to[50] = "RCPT TO:<nightmares@unknown.org>\r\n";
    send(sockfd, to, strlen(to), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // DATA command
    char data[10] = "DATA\r\n";
    send(sockfd, data, strlen(data), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // Email content
    char content[500] = "Subject: Your Worst Nightmare\r\nFrom: dreamworld@surrealmail.net\r\nTo: nightmares@unknown.org\r\nHello!\r\n\r\nI hope this email finds you in a dreamlike state. I wanted to share with you a nightmare I had last night. I was being chased by a giant rabbit and every time I tried to run, my feet turned into concrete. Eventually the rabbit caught up to me and revealed itself to be a human-sized caterpillar with a top hat. Just thought you'd like to know.\r\n.\r\n";
    send(sockfd, content, strlen(content), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // QUIT command
    char quit[10] = "QUIT\r\n";
    send(sockfd, quit, strlen(quit), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    close(sockfd);

    printf("\nEmail sent successfully. Reality may never be the same.\n");

    return 0;
}
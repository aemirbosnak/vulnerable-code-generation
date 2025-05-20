//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in serverAddr;
    struct hostent *hostConvert;
    char buffer[MAX_LINE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Server IP> <Port Number>\n", argv[0]);
        exit(1);
    }

    // Resolve host IP address
    if ((hostConvert = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Set up the socket address struct
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    memcpy(&serverAddr.sin_addr, hostConvert->h_addr, hostConvert->h_length);

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to server %s\n", argv[1]);

    // Receive greeting message from server
    memset(buffer, 0, MAX_LINE);
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Send HELO command
    char *heloCommand = "HELO client\r\n";
    if (send(sockfd, heloCommand, strlen(heloCommand), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to HELO command
    memset(buffer, 0, MAX_LINE);
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Construct the email message
    char *from = "From: <client@example.com>\r\n";
    char *to = "To: <recipient@example.com>\r\n";
    char *subject = "Subject: SMTP Test\r\n";
    char *body = "This is a test email sent from the client program.\r\n.\r\n";

    // Send MAIL FROM command
    char *mailFromCommand = "MAIL FROM: <client@example.com>\r\n";
    if (send(sockfd, mailFromCommand, strlen(mailFromCommand), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to MAIL FROM command
    memset(buffer, 0, MAX_LINE);
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Send RCPT TO command
    char *rcptToCommand = "RCPT TO: <recipient@example.com>\r\n";
    if (send(sockfd, rcptToCommand, strlen(rcptToCommand), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to RCPT TO command
    memset(buffer, 0, MAX_LINE);
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Send DATA command
    char *dataCommand = "DATA\r\n";
    if (send(sockfd, dataCommand, strlen(dataCommand), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to DATA command
    memset(buffer, 0, MAX_LINE);
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Send email message
    if (send(sockfd, from, strlen(from), 0) == -1) {
        perror("send");
        exit(1);
    }
    if (send(sockfd, to, strlen(to), 0) == -1) {
        perror("send");
        exit(1);
    }
    if (send(sockfd, subject, strlen(subject), 0) == -1) {
        perror("send");
        exit(1);
    }
    if (send(sockfd, body, strlen(body), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to email message
    memset(buffer, 0, MAX_LINE);
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Send QUIT command
    char *quitCommand = "QUIT\r\n";
    if (send(sockfd, quitCommand, strlen(quitCommand), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to QUIT command
    memset(buffer, 0, MAX_LINE);
    if (recv(sockfd, buffer, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}
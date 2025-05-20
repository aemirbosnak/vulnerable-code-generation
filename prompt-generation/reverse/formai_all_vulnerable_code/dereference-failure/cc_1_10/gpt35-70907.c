//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Function to send data to the server
int send_data(int sockfd, char *data) {
    int err = send(sockfd, data, strlen(data), 0);
    if (err < 0) {
        perror("Error sending data to server");
        return 0;
    }
    return 1;
}

// Function to receive data from the server
int receive_data(int sockfd, char *buffer) {
    int err = recv(sockfd, buffer, 1024, 0);
    if (err < 0) {
        perror("Error receiving data from server");
        return 0;
    }
    buffer[err] = '\0';
    return 1;
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Check if minimum arguments are passed
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Create socket using internet domain and stream type
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    // Copy server address information into serv_addr structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    portno = atoi(argv[2]);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive 220 message from the server
    if (!receive_data(sockfd, buffer)) {
        close(sockfd);
        exit(1);
    }
    printf("%s\n", buffer);

    // Send EHLO command to the server
    char *ehlo = "EHLO client\r\n";
    if (!send_data(sockfd, ehlo)) {
        close(sockfd);
        exit(1);
    }

    // Receive 250 message from the server for EHLO command
    if (!receive_data(sockfd, buffer)) {
        close(sockfd);
        exit(1);
    }
    printf("%s\n", buffer);

    // Send MAIL FROM command to the server
    char *mailfrom = "MAIL FROM: <sender@example.com>\r\n";
    if (!send_data(sockfd, mailfrom)) {
        close(sockfd);
        exit(1);
    }

    // Receive 250 message from the server for MAIL FROM command
    if (!receive_data(sockfd, buffer)) {
        close(sockfd);
        exit(1);
    }
    printf("%s\n", buffer);

    // Send RCPT TO command to the server
    char *rcptto = "RCPT TO: <recipient@example.com>\r\n";
    if (!send_data(sockfd, rcptto)) {
        close(sockfd);
        exit(1);
    }

    // Receive 250 message from the server for RCPT TO command
    if (!receive_data(sockfd, buffer)) {
        close(sockfd);
        exit(1);
    }
    printf("%s\n", buffer);

    // Send DATA command to the server
    char *datacmd = "DATA\r\n";
    if (!send_data(sockfd, datacmd)) {
        close(sockfd);
        exit(1);
    }

    // Receive 354 message from the server for DATA command
    if (!receive_data(sockfd, buffer)) {
        close(sockfd);
        exit(1);
    }
    printf("%s\n", buffer);

    // Send email body to the server
    char *body = "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Testing SMTP Client\r\n\r\nThis is a test email.\r\n.\r\n";
    if (!send_data(sockfd, body)) {
        close(sockfd);
        exit(1);
    }

    // Receive 250 message from the server for successful sending of email
    if (!receive_data(sockfd, buffer)) {
        close(sockfd);
        exit(1);
    }
    printf("%s\n", buffer);

    // Send QUIT command to the server
    char *quit = "QUIT\r\n";
    if (!send_data(sockfd, quit)) {
        close(sockfd);
        exit(1);
    }

    // Receive 221 message from the server for successful ending of session
    if (!receive_data(sockfd, buffer)) {
        close(sockfd);
        exit(1);
    }
    printf("%s\n", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}
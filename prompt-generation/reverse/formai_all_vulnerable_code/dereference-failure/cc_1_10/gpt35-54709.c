//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 

#define BUF_SIZE 1024 // Max buffer size

// Function to send data to the server
void send_data(int sockfd, char* msg) {
    send(sockfd, msg, strlen(msg), 0);
}

int main(int argc, char* argv[]) {
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    char buffer[BUF_SIZE];
    char* hostname;

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return 0;
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: No such host\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Sending EHLO command
    send_data(sockfd, "EHLO example.com\r\n");
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer); // Server response

    // Sending MAIL FROM command
    send_data(sockfd, "MAIL FROM: <sender@example.com>\r\n");
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer); // Server response

    // Sending RCPT TO command
    send_data(sockfd, "RCPT TO: <receiver@example.com>\r\n");
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer); // Server response

    // Sending DATA command
    send_data(sockfd, "DATA\r\n");
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer); // Server response

    // Sending message body
    char* message = "From: sender@example.com\nTo: receiver@example.com\nSubject: Test\n\nThis is a test email.\n.\r\n";
    send_data(sockfd, message);
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer); // Server response

    // Sending QUIT command
    send_data(sockfd, "QUIT\r\n");
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer); // Server response

    close(sockfd); // Closing the socket
    return 0;
}
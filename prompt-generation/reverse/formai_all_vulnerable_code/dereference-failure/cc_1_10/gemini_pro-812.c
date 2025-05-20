//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Sherlock Holmes' trusty SMTP client
int main() {
    // Prepare the communication tools
    int sockfd;
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Elemental, my dear Watson! Socket creation failed.\n");
        return EXIT_FAILURE;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Establish the connection with the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "My dear Watson, the connection has failed!\n");
        return EXIT_FAILURE;
    }

    // Receive the server's greeting
    char buffer[1024];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send the client's greeting
    char greeting[100];
    sprintf(greeting, "HELO mycroft.net\r\n");
    send(sockfd, greeting, strlen(greeting), 0);

    // Receive the server's response to the greeting
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send the sender's address
    char sender[100];
    sprintf(sender, "MAIL FROM: sherlock@mycroft.net\r\n");
    send(sockfd, sender, strlen(sender), 0);

    // Receive the server's response to the sender's address
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send the recipient's address
    char recipient[100];
    sprintf(recipient, "RCPT TO: john@watson.com\r\n");
    send(sockfd, recipient, strlen(recipient), 0);

    // Receive the server's response to the recipient's address
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send the data
    char data[100];
    sprintf(data, "DATA\r\n");
    send(sockfd, data, strlen(data), 0);

    // Receive the server's response to the data
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send the message body
    char message[100];
    sprintf(message, "Subject: The Case of the Purloined Letter\n\nMy dear Watson,\n\nI have a most curious case to present to you. It involves a stolen letter, a secret society, and a man with a remarkable memory. I believe your assistance in this matter will be invaluable.\n\nYours faithfully,\nSherlock Holmes\r\n.\r\n");
    send(sockfd, message, strlen(message), 0);

    // Receive the server's response to the message body
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send the quit command
    char quit[10];
    sprintf(quit, "QUIT\r\n");
    send(sockfd, quit, strlen(quit), 0);

    // Receive the server's response to the quit command
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Close the connection
    close(sockfd);

    return EXIT_SUCCESS;
}
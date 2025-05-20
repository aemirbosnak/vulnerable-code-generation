//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if enough arguments were passed
    if(argc != 4) {
        printf("Usage: ./smtp_client <server_address> <server_port> <email_address>\n");
        return 1;
    }

    // Extract input arguments
    char* server_address = argv[1];
    int server_port = atoi(argv[2]);
    char* email_address = argv[3];

    // Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    // Fill server details
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_address, &serv_addr.sin_addr);

    // Connect to server
    int status = connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
    if(status < 0) {
        printf("Error: Failed to connect to server.\n");
        return 1;
    }

    // Receive server response
    char buff[BUFF_SIZE];
    memset(buff, 0, BUFF_SIZE);
    status = recv(sockfd, buff, BUFF_SIZE, 0);
    if(status <= 0) {
        printf("Error: Failed to receive response from server.\n");
        return 1;
    }

    // Print server welcome message
    printf("%s", buff);

    // Send HELO message
    char helo_msg[BUFF_SIZE];
    sprintf(helo_msg, "HELO %s\r\n", email_address);
    status = send(sockfd, helo_msg, strlen(helo_msg), 0);
    if(status <= 0) {
        printf("Error: Failed to send HELO message.\n");
        return 1;
    }

    // Receive server response
    memset(buff, 0, BUFF_SIZE);
    status = recv(sockfd, buff, BUFF_SIZE, 0);
    if(status <= 0) {
        printf("Error: Failed to receive response from server.\n");
        return 1;
    }

    // Print server response to HELO message
    printf("%s", buff);

    // Send MAIL FROM message
    char mail_from_msg[BUFF_SIZE];
    sprintf(mail_from_msg, "MAIL FROM:<%s>\r\n", email_address);
    status = send(sockfd, mail_from_msg, strlen(mail_from_msg), 0);
    if(status <= 0) {
        printf("Error: Failed to send MAIL FROM message.\n");
        return 1;
    }

    // Receive server response
    memset(buff, 0, BUFF_SIZE);
    status = recv(sockfd, buff, BUFF_SIZE, 0);
    if(status <= 0) {
        printf("Error: Failed to receive response from server.\n");
        return 1;
    }

    // Print server response to MAIL FROM message
    printf("%s", buff);

    // Send RCPT TO message
    char rcpt_to_msg[BUFF_SIZE];
    printf("Enter recipient email address: ");
    fgets(buff, BUFF_SIZE, stdin); // Read from user input
    sscanf(buff, "%s", email_address); // Store user input in email_address variable
    sprintf(rcpt_to_msg, "RCPT TO:<%s>\r\n", email_address);
    status = send(sockfd, rcpt_to_msg, strlen(rcpt_to_msg), 0);
    if(status <= 0) {
        printf("Error: Failed to send RCPT TO message.\n");
        return 1;
    }

    // Receive server response
    memset(buff, 0, BUFF_SIZE);
    status = recv(sockfd, buff, BUFF_SIZE, 0);
    if(status <= 0) {
        printf("Error: Failed to receive response from server.\n");
        return 1;
    }

    // Print server response to RCPT TO message
    printf("%s", buff);

    // Send DATA message
    char data_msg[BUFF_SIZE];
    sprintf(data_msg, "DATA\r\n");
    status = send(sockfd, data_msg, strlen(data_msg), 0);
    if(status <= 0) {
        printf("Error: Failed to send DATA message.\n");
        return 1;
    }

    // Receive server response
    memset(buff, 0, BUFF_SIZE);
    status = recv(sockfd, buff, BUFF_SIZE, 0);
    if(status <= 0) {
        printf("Error: Failed to receive response from server.\n");
        return 1;
    }

    // Print server response to DATA message
    printf("%s", buff);

    // Send email body
    char email_body[BUFF_SIZE];
    printf("Enter email subject: ");
    fgets(buff, BUFF_SIZE, stdin); // Read from user input
    sprintf(email_body, "Subject: %s\r\n\r\n", buff); // Build email body
    printf("Enter email body (press enter followed by a dot to finish):\n");
    while(1) {
        fgets(buff, BUFF_SIZE, stdin); // Read from user input
        if(strcmp(buff, ".\n") == 0) {
            break; // End email body on input of '.'
        }
        strcat(email_body, buff); // Concatenate email body with user input
    }
    strcat(email_body, ".\r\n"); // Add end of body marker

    status = send(sockfd, email_body, strlen(email_body), 0);
    if(status <= 0) {
        printf("Error: Failed to send email body.\n");
        return 1;
    }

    // Receive server response
    memset(buff, 0, BUFF_SIZE);
    status = recv(sockfd, buff, BUFF_SIZE, 0);
    if(status <= 0) {
        printf("Error: Failed to receive response from server.\n");
        return 1;
    }

    // Print server response to email body
    printf("%s", buff);

    // Send QUIT message
    char quit_msg[BUFF_SIZE];
    sprintf(quit_msg, "QUIT\r\n");
    status = send(sockfd, quit_msg, strlen(quit_msg), 0);
    if(status <= 0) {
        printf("Error: Failed to send QUIT message.\n");
        return 1;
    }

    // Receive server response
    memset(buff, 0, BUFF_SIZE);
    status = recv(sockfd, buff, BUFF_SIZE, 0);
    if(status <= 0) {
        printf("Error: Failed to receive response from server.\n");
        return 1;
    }

    // Print server response to QUIT message
    printf("%s", buff);

    // Close socket
    close(sockfd);

    return 0;
}
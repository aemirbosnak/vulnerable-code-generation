//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Define constants
#define MAX_BUF 1024
#define SMTP_PORT 25
#define SERVER_NAME "mail.example.com"

// Function to get socket address
void *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main() {
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(1);
    }

    // Get host information
    struct hostent *he = gethostbyname(SERVER_NAME);
    if (he == NULL) {
        herror("Host not found");
        exit(1);
    }

    // Define server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        exit(1);
    }

    // Read server response
    char response[MAX_BUF] = {0};
    if (recv(sockfd, response, MAX_BUF, 0) < 0) {
        perror("Server response error");
        exit(1);
    }
    printf("%s\n", response);

    // Send HELO command
    char helo_cmd[MAX_BUF] = {0};
    sprintf(helo_cmd, "HELO %s\r\n", SERVER_NAME);
    if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) < 0) {
        perror("HELO command error");
        exit(1);
    }

    // Read server response
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, MAX_BUF, 0) < 0) {
        perror("Server response error");
        exit(1);
    }
    printf("%s\n", response);

    // Send MAIL FROM command
    char mail_from_cmd[MAX_BUF] = {0};
    sprintf(mail_from_cmd, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) < 0) {
        perror("MAIL FROM command error");
        exit(1);
    }

    // Read server response
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, MAX_BUF, 0) < 0) {
        perror("Server response error");
        exit(1);
    }
    printf("%s\n", response);

    // Send RCPT TO command
    char rcpt_to_cmd[MAX_BUF] = {0};
    sprintf(rcpt_to_cmd, "RCPT TO: <recipient@example.com>\r\n");
    if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) < 0) {
        perror("RCPT TO command error");
        exit(1);
    }

    // Read server response
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, MAX_BUF, 0) < 0) {
        perror("Server response error");
        exit(1);
    }
    printf("%s\n", response);

    // Send DATA command
    char data_cmd[MAX_BUF] = {0};
    sprintf(data_cmd, "DATA\r\n");
    if (send(sockfd, data_cmd, strlen(data_cmd), 0) < 0) {
        perror("DATA command error");
        exit(1);
    }

    // Read server response
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, MAX_BUF, 0) < 0) {
        perror("Server response error");
        exit(1);
    }
    printf("%s\n", response);

    // Send message body
    char msg_body[MAX_BUF] = {0};
    sprintf(msg_body, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test email\r\n\r\nHello world!\r\n.\r\n");
    if (send(sockfd, msg_body, strlen(msg_body), 0) < 0) {
        perror("Message body send error");
        exit(1);
    }

    // Read server response
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, MAX_BUF, 0) < 0) {
        perror("Server response error");
        exit(1);
    }
    printf("%s\n", response);

    // Send QUIT command
    char quit_cmd[MAX_BUF] = {0};
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0) {
        perror("QUIT command error");
        exit(1);
    }

    // Read server response
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, MAX_BUF, 0) < 0) {
        perror("Server response error");
        exit(1);
    }
    printf("%s\n", response);

    // Close connection
    close(sockfd);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT "25"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <email address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the recipient's email address
    char *recipient = argv[1];

    // Get the hostname of the SMTP server
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("gethostname");
        return EXIT_FAILURE;
    }

    // Get the IP address of the SMTP server
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a socket for connecting to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(SMTP_PORT));
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command to the SMTP server
    char helo_cmd[256];
    sprintf(helo_cmd, "HELO %s\r\n", hostname);
    if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    char recv_buf[256];
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the HELO command
    if (strncmp(recv_buf, "250", 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept HELO command\n");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command to the SMTP server
    char mail_from_cmd[256];
    sprintf(mail_from_cmd, "MAIL FROM: <%s>\r\n", getenv("USER"));
    if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the MAIL FROM command
    if (strncmp(recv_buf, "250", 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept MAIL FROM command\n");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command to the SMTP server
    char rcpt_to_cmd[256];
    sprintf(rcpt_to_cmd, "RCPT TO: <%s>\r\n", recipient);
    if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the RCPT TO command
    if (strncmp(recv_buf, "250", 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept RCPT TO command\n");
        return EXIT_FAILURE;
    }

    // Send the DATA command to the SMTP server
    if (send(sockfd, "DATA\r\n", 5, 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the DATA command
    if (strncmp(recv_buf, "354", 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept DATA command\n");
        return EXIT_FAILURE;
    }

    // Send the email message to the SMTP server
    char email_msg[1024];
    sprintf(email_msg, "To: %s\r\nFrom: %s\r\nSubject: Test Email\r\n\r\nThis is a test email message.\r\n", recipient, getenv("USER"));
    if (send(sockfd, email_msg, strlen(email_msg), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the end of the email message to the SMTP server
    if (send(sockfd, ".\r\n", 3, 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the email message
    if (strncmp(recv_buf, "250", 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept email message\n");
        return EXIT_FAILURE;
    }

    // Send the QUIT command to the SMTP server
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}
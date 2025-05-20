//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: distributed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and port number from the command line.
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Resolve the hostname to an IP address.
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Create a socket to connect to the SMTP server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        return EXIT_FAILURE;
    }

    // Set up the socket address structure.
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the SMTP server.
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to SMTP server\n");
        return EXIT_FAILURE;
    }

    // Send the HELO command to the SMTP server.
    const char *helo_cmd = "HELO smtp.mydomain.com\r\n";
    if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) < 0) {
        fprintf(stderr, "Error: could not send HELO command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    char buf[1024];
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server\n");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the HELO command.
    if (strncmp("250", buf, 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept HELO command\n");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command to the SMTP server.
    const char *mail_from_cmd = "MAIL FROM: <sender@mydomain.com>\r\n";
    if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) < 0) {
        fprintf(stderr, "Error: could not send MAIL FROM command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server\n");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the MAIL FROM command.
    if (strncmp("250", buf, 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept MAIL FROM command\n");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command to the SMTP server.
    const char *rcpt_to_cmd = "RCPT TO: <recipient@mydomain.com>\r\n";
    if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) < 0) {
        fprintf(stderr, "Error: could not send RCPT TO command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server\n");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the RCPT TO command.
    if (strncmp("250", buf, 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept RCPT TO command\n");
        return EXIT_FAILURE;
    }

    // Send the DATA command to the SMTP server.
    const char *data_cmd = "DATA\r\n";
    if (send(sockfd, data_cmd, strlen(data_cmd), 0) < 0) {
        fprintf(stderr, "Error: could not send DATA command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server\n");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the DATA command.
    if (strncmp("354", buf, 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept DATA command\n");
        return EXIT_FAILURE;
    }

    // Send the message to the SMTP server.
    const char *message = argv[3];
    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "Error: could not send message\n");
        return EXIT_FAILURE;
    }

    // Send the end-of-message indicator to the SMTP server.
    const char *eom_cmd = "\r\n.\r\n";
    if (send(sockfd, eom_cmd, strlen(eom_cmd), 0) < 0) {
        fprintf(stderr, "Error: could not send end-of-message indicator\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server\n");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the message.
    if (strncmp("250", buf, 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept message\n");
        return EXIT_FAILURE;
    }

    // Send the QUIT command to the SMTP server.
    const char *quit_cmd = "QUIT\r\n";
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0) {
        fprintf(stderr, "Error: could not send QUIT command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server\n");
        return EXIT_FAILURE;
    }

    // Check if the SMTP server accepted the QUIT command.
    if (strncmp("221", buf, 3) != 0) {
        fprintf(stderr, "Error: SMTP server did not accept QUIT command\n");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}
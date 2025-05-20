//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MSG_LENGTH 1024
#define SMTP_PORT 25

typedef struct {
    int sockfd;
    char buffer[MAX_MSG_LENGTH];
    char response[MAX_MSG_LENGTH];
} smtp_client_t;

/**
 * Connect to SMTP server
 * 
 * @param client SMTP client struct
 * @param server SMTP server address
 * 
 * @return status code
 */
int smtp_connect(smtp_client_t *client, const char *server) {
    // Create socket
    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        perror("Failed to create socket");
        return -1;
    }

    // Resolve server hostname/IP address
    struct hostent *he;
    if ((he = gethostbyname(server)) == NULL) {
        perror("Failed to resolve hostname");
        return -1;
    }

    // Set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    // Connect to server
    if (connect(client->sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Failed to connect to server");
        return -1;
    }

    // Receive initial server response
    int n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive response from server");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    return 0;
}

/**
 * Authenticate to SMTP server
 * 
 * @param client SMTP client struct
 * @param username SMTP username
 * @param password SMTP password
 * 
 * @return status code
 */
int smtp_authenticate(smtp_client_t *client, const char *username, const char *password) {
    // Send authentication command
    sprintf(client->buffer, "AUTH LOGIN\r\n");
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send AUTH command");
        return -1;
    }

    // Receive challenge for username
    int n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive challenge for username");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    // Send username in base64-encoded format
    sprintf(client->buffer, "%s\r\n", username);
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send username");
        return -1;
    }

    // Receive challenge for password
    n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive challenge for password");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    // Send password in base64-encoded format
    sprintf(client->buffer, "%s\r\n", password);
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send password");
        return -1;
    }

    // Receive final authentication response
    n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive authentication response");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    return 0;
}

/**
 * Send email message
 * 
 * @param client SMTP client struct
 * @param from sender email address
 * @param to recipient email address
 * @param subject email subject
 * @param message email message body
 * 
 * @return status code
 */
int smtp_send_message(smtp_client_t *client, const char *from, const char *to, const char *subject, const char *message) {
    // Send HELO command
    sprintf(client->buffer, "HELO localhost\r\n");
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send HELO command");
        return -1;
    }

    // Receive server response
    int n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive response to HELO command");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    // Send MAIL FROM command
    sprintf(client->buffer, "MAIL FROM: <%s>\r\n", from);
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send MAIL FROM command");
        return -1;
    }

    // Receive server response
    n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive response to MAIL FROM command");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    // Send RCPT TO command
    sprintf(client->buffer, "RCPT TO: <%s>\r\n", to);
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send RCPT TO command");
        return -1;
    }

    // Receive server response
    n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive response to RCPT TO command");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    // Send DATA command
    sprintf(client->buffer, "DATA\r\n");
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send DATA command");
        return -1;
    }

    // Receive server response
    n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive response to DATA command");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    // Send email message headers and body
    sprintf(client->buffer, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, message);
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send email message");
        return -1;
    }

    // Receive server response
    n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive response to email message");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    // Send QUIT command
    sprintf(client->buffer, "QUIT\r\n");
    if (send(client->sockfd, client->buffer, strlen(client->buffer), 0) == -1) {
        perror("Failed to send QUIT command");
        return -1;
    }

    // Receive server response
    n = recv(client->sockfd, client->buffer, MAX_MSG_LENGTH - 1, 0);
    if (n == -1) {
        perror("Failed to receive response to QUIT command");
        return -1;
    }
    client->buffer[n] = '\0';
    strcpy(client->response, client->buffer);

    return 0;
}

int main(int argc, char **argv) {
    // Check arguments
    if (argc < 5) {
        printf("Usage: %s <smtp_server> <smtp_username> <smtp_password> <recipient_email>\n", argv[0]);
        return 0;
    }

    // Initialize SMTP client
    smtp_client_t smtp_client;
    memset(&smtp_client, 0, sizeof(smtp_client_t));

    // Connect to SMTP server
    if (smtp_connect(&smtp_client, argv[1]) == -1) {
        printf("Failed to connect to SMTP server\n");
        return 1;
    }

    // Authenticate to SMTP server
    if (smtp_authenticate(&smtp_client, argv[2], argv[3]) == -1) {
        printf("Failed to authenticate to SMTP server\n");
        return 1;
    }

    // Send email message
    char *from = "sender@example.com";
    char *to = argv[4];
    char *subject = "Test email message";
    char *message = "This is a test email message sent from the SMTP client program.\n";
    if (smtp_send_message(&smtp_client, from, to, subject, message) == -1) {
        printf("Failed to send email message\n");
        return 1;
    }

    printf("Email message sent successfully\n");

    return 0;
}
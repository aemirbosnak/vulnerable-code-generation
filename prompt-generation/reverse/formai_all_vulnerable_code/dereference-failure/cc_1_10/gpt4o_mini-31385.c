//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_SERVER "smtp.cybermail.net"
#define SMTP_PORT 587
#define MAX_BUFFER 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void sendCommand(int sockfd, const char *cmd, char *response) {
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, response, MAX_BUFFER, 0);
    printf("%s", response);
}

int authenticate(int sockfd, const char *username, const char *password) {
    char response[MAX_BUFFER];

    // EHLO command
    sendCommand(sockfd, "EHLO cyberpunk\r\n", response);

    // AUTH LOGIN command
    sendCommand(sockfd, "AUTH LOGIN\r\n", response);

    // Send username
    char encodedUsername[MAX_BUFFER]; 
    sprintf(encodedUsername, "%s\r\n", username);
    sendCommand(sockfd, encodedUsername, response);

    // Send password
    char encodedPassword[MAX_BUFFER]; 
    sprintf(encodedPassword, "%s\r\n", password);
    sendCommand(sockfd, encodedPassword, response);

    if (strstr(response, "235") != NULL)
        return 1; // Authentication successful

    return 0; // Authentication failed
}

void sendEmail(int sockfd, const char *sender, const char *recipient, const char *subject, const char *body) {
    char response[MAX_BUFFER];

    // MAIL FROM command
    char mailFrom[MAX_BUFFER]; 
    sprintf(mailFrom, "MAIL FROM: <%s>\r\n", sender);
    sendCommand(sockfd, mailFrom, response);

    // RCPT TO command
    char rcptTo[MAX_BUFFER]; 
    sprintf(rcptTo, "RCPT TO: <%s>\r\n", recipient);
    sendCommand(sockfd, rcptTo, response);

    // DATA command
    sendCommand(sockfd, "DATA\r\n", response);

    // Email headers and body
    char email[MAX_BUFFER * 2];
    sprintf(email, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sockfd, email, strlen(email), 0);
    recv(sockfd, response, MAX_BUFFER, 0);
    printf("%s", response); // Confirm if SENT OK
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    // Get server address
    host = gethostbyname(SMTP_SERVER);
    if (host == NULL) error("ERROR, no such host");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    char response[MAX_BUFFER];
    recv(sockfd, response, MAX_BUFFER, 0);
    printf("%s", response); // Initial server response

    // Credentials and Email Info
    const char *username = "cyberpunk@node.com"; 
    const char *password = "neonLight$tr3am";
    const char *sender = "cyberpunk@node.com";
    const char *recipient = "cybermail@node.com";
    const char *subject = "Living in the Neon Galaxy";
    const char *body = "This message was sent from the underbelly of the city, where the wires hum with untold stories.";

    // Authenticate
    if (!authenticate(sockfd, username, password)) {
        printf("Authentication failed. Check your credentials.\n");
        close(sockfd);
        return 1;
    }

    // Send Email
    sendEmail(sockfd, sender, recipient, subject, body);
    printf("Mail sent!\n");

    // Quit command
    sendCommand(sockfd, "QUIT\r\n", response);
    close(sockfd);
    return 0;
}
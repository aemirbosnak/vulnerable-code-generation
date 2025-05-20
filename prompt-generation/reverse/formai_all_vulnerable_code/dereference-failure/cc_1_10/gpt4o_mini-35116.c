//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

char *receive_response(int sockfd) {
    static char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    int bytes_received = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_received < 0) {
        error("Failed to read from socket");
    }
    
    return buffer;
}

void smtp_client(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    // Receive welcome message
    printf("%s", receive_response(sockfd));

    // HELO command
    send_command(sockfd, "HELO localhost");
    printf("%s", receive_response(sockfd));

    // MAIL FROM command
    char mail_from_cmd[BUFFER_SIZE];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM: <%s>", from);
    send_command(sockfd, mail_from_cmd);
    printf("%s", receive_response(sockfd));

    // RCPT TO command
    char rcpt_to_cmd[BUFFER_SIZE];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO: <%s>", to);
    send_command(sockfd, rcpt_to_cmd);
    printf("%s", receive_response(sockfd));

    // DATA command
    send_command(sockfd, "DATA");
    printf("%s", receive_response(sockfd));
    
    // Construct email message
    char email_message[BUFFER_SIZE];
    snprintf(email_message, sizeof(email_message), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.", subject, from, to, body);
    
    // Send email data
    send_command(sockfd, email_message);
    printf("%s", receive_response(sockfd));

    // QUIT command
    send_command(sockfd, "QUIT");
    printf("%s", receive_response(sockfd));
    
    // Close the socket
    close(sockfd);
}

int main() {
    const char *smtp_server = "127.0.0.1"; // SMTP server address
    const char *from_address = "sender@example.com"; // Sender's email address
    const char *to_address = "receiver@example.com"; // Receiver's email address
    const char *email_subject = "Artistic Journey"; // Subject of the email
    const char *email_body = "Greetings,\n\nWelcome to an artistic SMTP client written in C!\n\nBest Regards,\nYour SMTP Client"; // Email body

    smtp_client(smtp_server, from_address, to_address, email_subject, email_body);

    return 0;
}
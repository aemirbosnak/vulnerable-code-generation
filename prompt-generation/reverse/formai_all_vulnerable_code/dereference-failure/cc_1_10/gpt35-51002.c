//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char* receive_reply(int sock) {
    char *buffer = malloc(BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    return buffer;
}

int main() {
    // Create socket for SMTP client
    int smtp_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set up server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25); // SMTP server port
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Local host IP

    // Connect to server
    connect(smtp_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Receive server welcome message
    printf("%s", receive_reply(smtp_socket));

    // Send HELO command
    char *helo_request = "HELO example.com\n";
    send(smtp_socket, helo_request, strlen(helo_request), 0);

    // Receive server response to HELO command
    printf("%s", receive_reply(smtp_socket));
    
    // Send MAIL FROM command
    char *mail_from_request = "MAIL FROM:<example-1@example.com>\n";
    send(smtp_socket, mail_from_request, strlen(mail_from_request), 0);

    // Receive server response to MAIL FROM command
    printf("%s", receive_reply(smtp_socket));

    // Send RCPT TO command
    char *rcpt_to_request = "RCPT TO:<example-2@example.com>\n";
    send(smtp_socket, rcpt_to_request, strlen(rcpt_to_request), 0);

    // Receive server response to RCPT TO command
    printf("%s", receive_reply(smtp_socket));

    // Send DATA command
    char *data_request = "DATA\n";
    send(smtp_socket, data_request, strlen(data_request), 0);

    // Receive server response to DATA command
    printf("%s", receive_reply(smtp_socket));

    // Send message content
    char *message = "Subject: Example email\n\nThis is an example email message.\n";
    send(smtp_socket, message, strlen(message), 0);

    // Send END OF MESSAGE command
    char *eom_request = "\r\n.\r\n";
    send(smtp_socket, eom_request, strlen(eom_request), 0);

    // Receive server response to EOM command
    printf("%s", receive_reply(smtp_socket));

    // Send QUIT command
    char *quit_request = "QUIT\n";
    send(smtp_socket, quit_request, strlen(quit_request), 0);

    // Receive server response to QUIT command
    printf("%s", receive_reply(smtp_socket));

    // Close socket
    close(smtp_socket);
    
    return 0;
}
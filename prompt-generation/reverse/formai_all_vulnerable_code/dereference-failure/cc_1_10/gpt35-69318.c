//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER 1024

int main(int argc, char* argv[]) {

    // Check if enough arguments have been provided
    if ( argc < 3 ) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket for the client
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Specify the server address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Failed to set server address");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Initialize buffer for messages
    char buffer[MAX_BUFFER];

    // Receive server greeting
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send HELO command to the server
    char helo_command[MAX_BUFFER];
    sprintf(helo_command, "HELO %s\r\n", argv[1]);
    send(sock, helo_command, strlen(helo_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send MAIL FROM command to the server
    char mail_from_command[MAX_BUFFER];
    printf("From: ");
    fgets(buffer, MAX_BUFFER, stdin);
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", buffer);
    send(sock, mail_from_command, strlen(mail_from_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send RCPT TO command to the server (to whom you want to send email)
    char rcpt_to_command[MAX_BUFFER];
    printf("To: ");
    fgets(buffer, MAX_BUFFER, stdin);
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", buffer);
    send(sock, rcpt_to_command, strlen(rcpt_to_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send DATA command to the server
    char data_command[MAX_BUFFER];
    sprintf(data_command, "DATA\r\n");
    send(sock, data_command, strlen(data_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send email body to the server
    char email_body[MAX_BUFFER];
    printf("Subject: ");
    fgets(buffer, MAX_BUFFER, stdin);
    strcpy(email_body, buffer);
    printf("\nMessage:\n");
    fgets(buffer, MAX_BUFFER, stdin);
    strcat(email_body, buffer);
    sprintf(data_command, "%s\r\n", email_body);
    send(sock, data_command, strlen(data_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send QUIT command to the server
    char quit_command[MAX_BUFFER];
    sprintf(quit_command, "QUIT\r\n");
    send(sock, quit_command, strlen(quit_command), 0);

    // Close the socket
    close(sock);

    return 0;
}
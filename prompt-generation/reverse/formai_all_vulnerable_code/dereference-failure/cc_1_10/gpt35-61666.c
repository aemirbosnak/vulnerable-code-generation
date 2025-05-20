//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 25

int main(int argc, char *argv[]) {

    int client_socket;
    struct sockaddr_in server_address;

    char *server_ip_address = "127.0.0.1"; // replace with SMTP server IP address
    char *mail_from = "example@mail.com"; // replace with sender email address
    char *mail_to = "recipient@mail.com"; // replace with recipient email address
    char *mail_subject = "Test Email"; // replace with email subject
    char *mail_body = "This is a test email sent using SMTP client"; // replace with email body
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);

    // Creating a socket for client
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Setting server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, server_ip_address, &server_address.sin_addr) <= 0) {
        perror("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connecting to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    // Reading server response
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Sending HELO command
    char *helo_command = "HELO example.com\r\n";
    send(client_socket, helo_command, strlen(helo_command), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Sending MAIL FROM command
    char mail_from_command[BUFFER_SIZE];
    sprintf(mail_from_command, "MAIL FROM:<%s>\r\n", mail_from);
    send(client_socket, mail_from_command, strlen(mail_from_command), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Sending RCPT TO command
    char mail_to_command[BUFFER_SIZE];
    sprintf(mail_to_command, "RCPT TO:<%s>\r\n", mail_to);
    send(client_socket, mail_to_command, strlen(mail_to_command), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Sending DATA command
    char *data_command = "DATA\r\n";
    send(client_socket, data_command, strlen(data_command), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Sending email
    char mail_body_command[BUFFER_SIZE];
    sprintf(mail_body_command, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", mail_from, mail_to, mail_subject, mail_body);
    send(client_socket, mail_body_command, strlen(mail_body_command), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Sending QUIT command
    char *quit_command = "QUIT\r\n";
    send(client_socket, quit_command, strlen(quit_command), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Closing client socket
    close(client_socket);
    free(buffer);

    return 0;
}
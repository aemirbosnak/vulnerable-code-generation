//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 587 // SMTP port
#define BUFFER_SIZE 1024

int main() {
    int socket_fd, n;
    struct sockaddr_in server_address;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    
    // get server details
    server = gethostbyname("mail.example.com"); // replace with actual SMTP server hostname
    if (server == NULL) {
        fprintf(stderr, "Error: Invalid server.\n");
        exit(1);
    }
    
    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: Socket creation failed.\n");
        exit(1);
    }
    
    // set server address details
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
        (char *)&server_address.sin_addr.s_addr,
         server->h_length);
    server_address.sin_port = htons(PORT);
    
    // connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Error: Connection failed.\n");
        exit(1);
    }
    
    // read server welcome message
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read server message.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send EHLO command
    char ehlo_command[BUFFER_SIZE] = "EHLO smtpclient.com\r\n";
    n = write(socket_fd, ehlo_command, strlen(ehlo_command));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send EHLO command.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send AUTH LOGIN command
    char auth_login_command[BUFFER_SIZE] = "AUTH LOGIN\r\n";
    n = write(socket_fd, auth_login_command, strlen(auth_login_command));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send AUTH LOGIN command.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send encoded username
    char encoded_username[BUFFER_SIZE] = "dXNlcm5hbWU=\r\n"; // replace with base64-encoded username
    n = write(socket_fd, encoded_username, strlen(encoded_username));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send encoded username.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send encoded password
    char encoded_password[BUFFER_SIZE] = "cGFzc3dvcmQ=\r\n"; // replace with base64-encoded password
    n = write(socket_fd, encoded_password, strlen(encoded_password));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send encoded password.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send MAIL FROM command
    char mail_from_command[BUFFER_SIZE] = "MAIL FROM:<sender@example.com>\r\n"; // replace with actual sender email
    n = write(socket_fd, mail_from_command, strlen(mail_from_command));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send MAIL FROM command.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send RCPT TO command
    char rcpt_to_command[BUFFER_SIZE] = "RCPT TO:<receiver@example.com>\r\n"; // replace with actual receiver email
    n = write(socket_fd, rcpt_to_command, strlen(rcpt_to_command));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send RCPT TO command.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send DATA command
    char data_command[BUFFER_SIZE] = "DATA\r\n";
    n = write(socket_fd, data_command, strlen(data_command));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send DATA command.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send email body
    char email_body[BUFFER_SIZE] = "Subject: Post-apocalyptic SMTP Client\n\nHello, this is a post-apocalyptic SMTP client program!\n";
    n = write(socket_fd, email_body, strlen(email_body));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send email body.\n");
        exit(1);
    }
    
    // send mail terminating sequence
    char mail_end[BUFFER_SIZE] = "\r\n.\r\n";
    n = write(socket_fd, mail_end, strlen(mail_end));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send mail terminating sequence.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // send QUIT command
    char quit_command[BUFFER_SIZE] = "QUIT\r\n";
    n = write(socket_fd, quit_command, strlen(quit_command));
    if (n < 0) {
        fprintf(stderr, "Error: Failed to send QUIT command.\n");
        exit(1);
    }
    
    // read response
    bzero(buffer, BUFFER_SIZE);
    n = read(socket_fd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Failed to read response.\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // close socket
    close(socket_fd);
    
    return 0;
}
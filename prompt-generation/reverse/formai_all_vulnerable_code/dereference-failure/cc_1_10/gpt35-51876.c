//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25 // SMTP port
#define SERVER_ADDR "smtp.gmail.com" // SMTP server address
#define BUF_SIZE 1024

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Get the server details
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr,"Error: No such host");
        exit(1);
    }

    // Set the server address and port
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr_list[0], (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read the welcome message from the server
    char buffer[BUF_SIZE];
    read(sock_fd, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Send the HELO command
    char helo_cmd[BUF_SIZE];
    sprintf(helo_cmd, "HELO %s\r\n", SERVER_ADDR);
    write(sock_fd, helo_cmd, strlen(helo_cmd));
    read(sock_fd, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Send the mail from command
    char from_cmd[BUF_SIZE];
    sprintf(from_cmd, "MAIL FROM: <sender@example.com>\r\n");
    write(sock_fd, from_cmd, strlen(from_cmd));
    read(sock_fd, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Send the rcpt to command
    char rcpt_to_cmd[BUF_SIZE];
    sprintf(rcpt_to_cmd, "RCPT TO: <recipient@example.com>\r\n");
    write(sock_fd, rcpt_to_cmd, strlen(rcpt_to_cmd));
    read(sock_fd, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Send the data command
    char data_cmd[BUF_SIZE];
    sprintf(data_cmd, "DATA\r\n");
    write(sock_fd, data_cmd, strlen(data_cmd));
    read(sock_fd, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Send the email body
    char body[BUF_SIZE];
    sprintf(body, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test email\r\n\r\nHello, this is a test email sent from a C program!\r\n.\r\n");
    write(sock_fd, body, strlen(body));
    read(sock_fd, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Send the quit command
    char quit_cmd[BUF_SIZE];
    sprintf(quit_cmd, "QUIT\r\n");
    write(sock_fd, quit_cmd, strlen(quit_cmd));
    read(sock_fd, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Close the socket
    close(sock_fd);

    return 0;
}
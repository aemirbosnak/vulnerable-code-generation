//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/tcp.h>

int main() {
    int socket_fd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Get the server address and port number
    char* server_name = "smtp.example.com";
    int server_port = 25;

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    server = gethostbyname(server_name);
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(server_port);

    n = connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (n < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Send the SMTP HELO command
    char helo_command[] = "HELO client.example.com\r\n";
    send(socket_fd, helo_command, strlen(helo_command), 0);

    // Send the SMTP MAIL FROM command
    char mail_from[] = "MAIL FROM:<user@example.com>\r\n";
    send(socket_fd, mail_from, strlen(mail_from), 0);

    // Send the SMTP RCPT TO command
    char rcpt_to[] = "RCPT TO:<recipient@example.com>\r\n";
    send(socket_fd, rcpt_to, strlen(rcpt_to), 0);

    // Send the SMTP DATA command
    char data_command[] = "DATA\r\n";
    send(socket_fd, data_command, strlen(data_command), 0);

    // Send the message content
    char message[] = "This is a test email.\r\n";
    send(socket_fd, message, strlen(message), 0);

    // Send the QUIT command
    char quit_command[] = "QUIT\r\n";
    send(socket_fd, quit_command, strlen(quit_command), 0);

    // Close the socket
    close(socket_fd);

    return 0;
}
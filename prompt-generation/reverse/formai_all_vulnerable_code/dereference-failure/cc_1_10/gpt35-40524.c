//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define MAX_BUFFER 4096

int main(int argc, char** argv) {
    // Check for correct usage.
    if (argc != 3) {
        printf("Usage: %s <recipient> <message>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Failed to create socket");
        exit(1);
    }

    struct hostent *host = gethostbyname("smtp.gmail.com");
    if (host == NULL) {
        perror("ERROR: Failed to retrieve hostname");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    memcpy(&server_address.sin_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR: Failed to connect to server");
        exit(1);
    }

    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer); // Print server greeting message.

    // Send HELO command.
    char helo_command[MAX_BUFFER];
    sprintf(helo_command, "HELO %s\r\n", "localhost");
    send(sockfd, helo_command, strlen(helo_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send MAIL FROM command.
    char mail_from_command[MAX_BUFFER];
    sprintf(mail_from_command, "MAIL FROM:<%s>\r\n", "sender@gmail.com");
    send(sockfd, mail_from_command, strlen(mail_from_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send RCPT TO command.
    char rcpt_to_command[MAX_BUFFER];
    sprintf(rcpt_to_command, "RCPT TO:<%s>\r\n", argv[1]);
    send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send DATA command.
    char data_command[MAX_BUFFER];
    sprintf(data_command, "DATA\r\n");
    send(sockfd, data_command, strlen(data_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send message.
    char message[MAX_BUFFER];
    sprintf(message, "From: sender@gmail.com\r\nTo: <%s>\r\nSubject: Test Message\r\n\r\n%s\r\n.\r\n", argv[1], argv[2]);
    send(sockfd, message, strlen(message), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send QUIT command.
    char quit_command[MAX_BUFFER];
    sprintf(quit_command, "QUIT\r\n");
    send(sockfd, quit_command, strlen(quit_command), 0);
    memset(buffer, 0, MAX_BUFFER);
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}
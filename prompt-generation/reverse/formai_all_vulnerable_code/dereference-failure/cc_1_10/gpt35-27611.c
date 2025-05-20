//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define SMTP_PORT 25
#define MAX_BUFFER_SIZE 1024

void send_command(int sockfd, const char* command) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_sent, bytes_received;

    bytes_sent = send(sockfd, command, strlen(command), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);
}

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent* server;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    
    char buffer[MAX_BUFFER_SIZE];
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    send_command(sockfd, "HELO localhost\r\n");
    send_command(sockfd, "MAIL FROM:<sender@example.com>\r\n");
    send_command(sockfd, "RCPT TO:<recipient@example.com>\r\n");
    send_command(sockfd, "DATA\r\n");
    send_command(sockfd, "Subject: SMTP Test Subject\r\n");
    send_command(sockfd, "From: SenderName <sender@example.com>\r\n");
    send_command(sockfd, "To: RecipientName <recipient@example.com>\r\n");
    send_command(sockfd, "This is a test message sent using SMTP.\r\n");
    send_command(sockfd, ".\r\n");
    send_command(sockfd, "QUIT\r\n");

    close(sockfd);
    return 0;
}
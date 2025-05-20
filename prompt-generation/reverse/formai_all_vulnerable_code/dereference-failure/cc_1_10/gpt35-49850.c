//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void write_socket(int sockfd, char *data) {
    int bytes_sent = send(sockfd, data, strlen(data), 0);
    if (bytes_sent == -1) {
        perror("send error");
        exit(1);
    }
}

void read_socket(int sockfd, char *buffer) {
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        perror("recv error");
        exit(1);
    }
    buffer[bytes_received] = '\0';
}

int main(int argc, char **argv) {
    // Check for required arguments
    if (argc != 3) {
        printf("Usage: smtp_client [server_hostname] [server_port]\n");
        exit(1);
    }

    // Set up connection to server
    struct hostent *server = gethostbyname(argv[1]);
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket error");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr*) server->h_addr);
    memset(&(server_address.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("connect error");
        exit(1);
    }

    // Read initial message from server
    char buffer[BUFFER_SIZE];
    read_socket(sockfd, buffer);
    printf("%s", buffer);

    // Send HELO message to server
    char *helo_message = "HELO localhost\r\n";
    write_socket(sockfd, helo_message);
    read_socket(sockfd, buffer);
    printf("%s", buffer);

    // Send MAIL FROM message to server
    char *mail_from_message = "MAIL FROM: <example@example.com>\r\n";
    write_socket(sockfd, mail_from_message);
    read_socket(sockfd, buffer);
    printf("%s", buffer);

    // Send RCPT TO message to server
    char *rcpt_to_message = "RCPT TO: <recipient@example.com>\r\n";
    write_socket(sockfd, rcpt_to_message);
    read_socket(sockfd, buffer);
    printf("%s", buffer);

    // Send DATA message to server
    char *data_message = "DATA\r\n";
    write_socket(sockfd, data_message);
    read_socket(sockfd, buffer);
    printf("%s", buffer);

    // Send email body to server
    char *body = "Subject: Test email\r\n\r\nThis is a test email.\r\n";
    write_socket(sockfd, body);
    write_socket(sockfd, "\r\n.\r\n");
    read_socket(sockfd, buffer);
    printf("%s", buffer);

    // Send QUIT message to server
    char *quit_message = "QUIT\r\n";
    write_socket(sockfd, quit_message);
    read_socket(sockfd, buffer);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}
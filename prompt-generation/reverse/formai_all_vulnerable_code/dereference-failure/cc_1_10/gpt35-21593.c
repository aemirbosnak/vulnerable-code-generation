//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void send_mail(char *mail_server, int port) {
    struct hostent *he;
    struct sockaddr_in server_address;
    int socket_fd;
    char message[MAX_LINE_LENGTH];

    // Resolve server name to IP address
    if ((he = gethostbyname(mail_server)) == NULL) {
        perror("Unable to resolve server name");
        exit(1);
    }

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Unable to create socket");
        exit(1);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr *)he->h_addr);
    server_address.sin_port = htons(port);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Unable to connect to server");
        close(socket_fd);
        exit(1);
    }

    // Read greeting from server
    if (recv(socket_fd, message, MAX_LINE_LENGTH, 0) < 0) {
        perror("Error receiving message from server");
        close(socket_fd);
        exit(1);
    }
    printf("%s", message);

    // Send EHLO command
    sprintf(message, "EHLO client.example.com\r\n");
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        close(socket_fd);
        exit(1);
    }

    // Read response from server
    if (recv(socket_fd, message, MAX_LINE_LENGTH, 0) < 0) {
        perror("Error receiving message from server");
        close(socket_fd);
        exit(1);
    }
    printf("%s", message);

    // Send MAIL FROM command
    sprintf(message, "MAIL FROM:<sender@example.com>\r\n");
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        close(socket_fd);
        exit(1);
    }

    // Read response from server
    if (recv(socket_fd, message, MAX_LINE_LENGTH, 0) < 0) {
        perror("Error receiving message from server");
        close(socket_fd);
        exit(1);
    }
    printf("%s", message);

    // Send RCPT TO command
    sprintf(message, "RCPT TO:<recipient@example.com>\r\n");
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        close(socket_fd);
        exit(1);
    }

    // Read response from server
    if (recv(socket_fd, message, MAX_LINE_LENGTH, 0) < 0) {
        perror("Error receiving message from server");
        close(socket_fd);
        exit(1);
    }
    printf("%s", message);

    // Send DATA command
    sprintf(message, "DATA\r\n");
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        close(socket_fd);
        exit(1);
    }

    // Read response from server
    if (recv(socket_fd, message, MAX_LINE_LENGTH, 0) < 0) {
        perror("Error receiving message from server");
        close(socket_fd);
        exit(1);
    }
    printf("%s", message);

    // Send message body
    sprintf(message, "Subject: Test\r\n\r\nThis is a test message\r\n.");
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        close(socket_fd);
        exit(1);
    }

    // Read response from server
    if (recv(socket_fd, message, MAX_LINE_LENGTH, 0) < 0) {
        perror("Error receiving message from server");
        close(socket_fd);
        exit(1);
    }
    printf("%s", message);

    // Send QUIT command
    sprintf(message, "QUIT\r\n");
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        close(socket_fd);
        exit(1);
    }

    // Read response from server
    if (recv(socket_fd, message, MAX_LINE_LENGTH, 0) < 0) {
        perror("Error receiving message from server");
        close(socket_fd);
        exit(1);
    }
    printf("%s", message);

    // Close socket
    close(socket_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s mail_server port\n", argv[0]);
        exit(1);
    }

    send_mail(argv[1], atoi(argv[2]));

    return 0;
}
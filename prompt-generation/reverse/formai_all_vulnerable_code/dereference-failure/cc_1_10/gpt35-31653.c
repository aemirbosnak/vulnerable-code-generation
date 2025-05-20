//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_MESSAGE_LENGTH 1000
#define DEFAULT_PORT 25

void send_message(int sock_fd, char *message);
char *receive_message(int sock_fd);

int main(int argc, char *argv[]) {
    char *server_address;
    int port_number = DEFAULT_PORT;
    
    if (argc < 2) {
        printf("Please provide a server address\n");
        return 1;
    }

    server_address = argv[1];
    if (argc == 3) {
        port_number = atoi(argv[2]);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        printf("Error getting host\n");
        return 1;
    }

    struct sockaddr_in server_address_struct;
    bzero((char *) &server_address_struct, sizeof(server_address_struct));
    server_address_struct.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address_struct.sin_addr.s_addr, server->h_length);
    server_address_struct.sin_port = htons(port_number);

    if (connect(sock_fd, (struct sockaddr *) &server_address_struct, sizeof(server_address_struct)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    char *greeting = receive_message(sock_fd);

    printf("%s", greeting);

    char *username = "USER email@example.com\r\n";
    send_message(sock_fd, username);

    char *password = "PASS mypassword\r\n";
    send_message(sock_fd, password);

    char *message = "MAIL FROM:<email@example.com>\r\n";
    send_message(sock_fd, message);

    message = "RCPT TO:<recipient@example.com>\r\n";
    send_message(sock_fd, message);

    message = "DATA\r\n";
    send_message(sock_fd, message);

    message = "From: email@example.com\r\n";
    send_message(sock_fd, message);

    message = "To: recipient@example.com\r\n";
    send_message(sock_fd, message);

    message = "Subject: Test Email\r\n\r\n";
    send_message(sock_fd, message);

    message = "Hello, this is a test email.\r\n.\r\n";
    send_message(sock_fd, message);

    message = "QUIT\r\n";
    send_message(sock_fd, message);

    char *closing_message = receive_message(sock_fd);

    printf("%s", closing_message);

    close(sock_fd);

    return 0;
}

void send_message(int sock_fd, char *message) {
    if (send(sock_fd, message, strlen(message), 0) < 0) {
        printf("Error sending message\n");
        exit(1);
    }
}

char *receive_message(int sock_fd) {
    char *message = (char *) malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    bzero(message, MAX_MESSAGE_LENGTH);

    if (recv(sock_fd, message, MAX_MESSAGE_LENGTH, 0) < 0) {
        printf("Error receiving message\n");
        exit(1);
    }

    return message;
}
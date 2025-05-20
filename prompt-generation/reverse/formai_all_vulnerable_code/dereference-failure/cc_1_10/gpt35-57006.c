//FormAI DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define POP3_PORT "110"
#define SMTP_PORT "25"
#define MAX_DATA_SIZE 1024

void handle_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void send_message(int socket_fd, const char *message) {
    ssize_t n = send(socket_fd, message, strlen(message), 0);

    if (n < 0) {
        handle_error("Error sending message");
    }
}

void receive(int socket_fd, char *buffer, size_t buffer_size) {
    ssize_t n = recv(socket_fd, buffer, buffer_size - 1, 0);

    if (n < 0) {
        handle_error("Error receiving message");
    }

    buffer[n] = '\0';
}

void receive_multiline(int socket_fd, char *buffer, size_t buffer_size) {
    size_t pos = 0;
    char *last_line = NULL;

    do {
        receive(socket_fd, buffer + pos, buffer_size - pos);
        last_line = strrchr(buffer, '\n');
        pos = last_line - buffer + 1;
    } while (pos < buffer_size - 1 && last_line != NULL && *(last_line - 1) == '-');
}

void prepare_address(struct addrinfo *hints, struct addrinfo **server_addr, const char *host, const char *port) {
    memset(hints, 0, sizeof(*hints));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;
    getaddrinfo(host, port, hints, server_addr);
}

void connect_to_server(int *socket_fd, struct addrinfo *server_addr) {
    *socket_fd = socket(server_addr->ai_family, server_addr->ai_socktype, server_addr->ai_protocol);
    if (*socket_fd < 0) {
        handle_error("Error creating socket");
    }

    if (connect(*socket_fd, server_addr->ai_addr, server_addr->ai_addrlen) < 0) {
        handle_error("Error connecting to server");
    }
}

int main() {
    struct addrinfo hints, *server_addr_info;
    int pop3_socket, smtp_socket;
    char buffer[MAX_DATA_SIZE];

    // Connect to POP3 server
    prepare_address(&hints, &server_addr_info, "pop3.example.com", POP3_PORT);
    connect_to_server(&pop3_socket, server_addr_info);
    freeaddrinfo(server_addr_info);

    receive(pop3_socket, buffer, MAX_DATA_SIZE);  // Wait for server greeting
    printf("%s\n", buffer);

    // Log in to POP3 server
    send_message(pop3_socket, "USER john@example.com\r\n");
    receive(pop3_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    send_message(pop3_socket, "PASS secret\r\n");
    receive(pop3_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    // Retrieve first email from the server
    send_message(pop3_socket, "RETR 1\r\n");
    receive_multiline(pop3_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    // Connect to SMTP server
    prepare_address(&hints, &server_addr_info, "smtp.example.com", SMTP_PORT);
    connect_to_server(&smtp_socket, server_addr_info);
    freeaddrinfo(server_addr_info);

    receive(smtp_socket, buffer, MAX_DATA_SIZE);  // Wait for server greeting
    printf("%s\n", buffer);

    // Log in to SMTP server
    send_message(smtp_socket, "EHLO example.com\r\n");
    receive_multiline(smtp_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    // Send an email
    send_message(smtp_socket, "MAIL FROM:<john@example.com>\r\n");
    receive(smtp_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    send_message(smtp_socket, "RCPT TO:<jane@example.com>\r\n");
    receive(smtp_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    send_message(smtp_socket, "DATA\r\n");
    receive(smtp_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    send_message(smtp_socket, "Subject: Test email\r\n\r\nHello Jane,\r\nThis is a test email. Regards,\r\nJohn\r\n.\r\n");
    receive(smtp_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    // Log out from SMTP server
    send_message(smtp_socket, "QUIT\r\n");
    receive(smtp_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    // Log out from POP3 server
    send_message(pop3_socket, "QUIT\r\n");
    receive(pop3_socket, buffer, MAX_DATA_SIZE);
    printf("%s\n", buffer);

    // Close sockets
    close(smtp_socket);
    close(pop3_socket);

    return 0;
}
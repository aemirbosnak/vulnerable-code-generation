//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./smtp_client <server_ip> <server_port>\n");
        exit(1);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        fprintf(stderr, "Error: Could not create socket.\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Could not connect to server.\n");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int recv_size;

    // Receive greeting message from server
    recv_size = recv(client_socket, buffer, MAX_SIZE, 0);
    buffer[recv_size] = '\0';
    printf("Server response: %s\n", buffer);

    // Send EHLO command
    char ehlo_msg[MAX_SIZE];
    sprintf(ehlo_msg, "EHLO client\r\n");
    send(client_socket, ehlo_msg, strlen(ehlo_msg), 0);

    // Receive response to EHLO command
    recv_size = recv(client_socket, buffer, MAX_SIZE, 0);
    buffer[recv_size] = '\0';
    printf("Server response: %s\n", buffer);

    // Send MAIL FROM command
    char mail_from_msg[MAX_SIZE];
    sprintf(mail_from_msg, "MAIL FROM: <user@example.com>\r\n");
    send(client_socket, mail_from_msg, strlen(mail_from_msg), 0);

    // Receive response to MAIL FROM command
    recv_size = recv(client_socket, buffer, MAX_SIZE, 0);
    buffer[recv_size] = '\0';
    printf("Server response: %s\n", buffer);

    // Send RCPT TO command
    char rcpt_to_msg[MAX_SIZE];
    sprintf(rcpt_to_msg, "RCPT TO: <recipient@example.com>\r\n");
    send(client_socket, rcpt_to_msg, strlen(rcpt_to_msg), 0);

    // Receive response to RCPT TO command
    recv_size = recv(client_socket, buffer, MAX_SIZE, 0);
    buffer[recv_size] = '\0';
    printf("Server response: %s\n", buffer);

    // Send DATA command
    char data_msg[MAX_SIZE];
    sprintf(data_msg, "DATA\r\n");
    send(client_socket, data_msg, strlen(data_msg), 0);

    // Receive response to DATA command
    recv_size = recv(client_socket, buffer, MAX_SIZE, 0);
    buffer[recv_size] = '\0';
    printf("Server response: %s\n", buffer);

    // Send email message
    char email_msg[MAX_SIZE];
    sprintf(email_msg, "From: user@example.com\r\nTo: recipient@example.com\r\nSubject: Test email\r\n\r\nThis is the body of the email.\r\n.\r\n");
    send(client_socket, email_msg, strlen(email_msg), 0);

    // Receive response to email message
    recv_size = recv(client_socket, buffer, MAX_SIZE, 0);
    buffer[recv_size] = '\0';
    printf("Server response: %s\n", buffer);

    // Send QUIT command
    char quit_msg[MAX_SIZE];
    sprintf(quit_msg, "QUIT\r\n");
    send(client_socket, quit_msg, strlen(quit_msg), 0);

    // Receive response to QUIT command
    recv_size = recv(client_socket, buffer, MAX_SIZE, 0);
    buffer[recv_size] = '\0';
    printf("Server response: %s\n", buffer);

    close(client_socket);

    return 0;
}
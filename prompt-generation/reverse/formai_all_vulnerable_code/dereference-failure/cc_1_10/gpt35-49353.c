//FormAI DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_USER_INPUT_SIZE 255

struct addrinfo hints, *server_info;
int sockfd;

void handle_error(const char* error_message) {
    printf("Error: %s\n", error_message);
    exit(EXIT_FAILURE);
}

void setup_socket_connection(char* server_address, char* server_port) {
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(server_address, server_port, &hints, &server_info);
    if (status != 0) {
        handle_error("Could not get address info");
    }

    sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd == -1) {
        handle_error("Could not create a socket");
    }

    status = connect(sockfd, server_info->ai_addr, server_info->ai_addrlen);
    if (status != 0) {
        handle_error("Could not connect to the server");
    }

    freeaddrinfo(server_info);
    printf("Connection to the server has been established.\n");
}

void send_email(char* recipient_email, char* email_subject, char* email_body) {
    char command[MAX_BUFFER_SIZE];

    sprintf(command, "RCPT TO:<%s>\r\n", recipient_email);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        handle_error("Could not send recipient email command to the server");
    }

    sprintf(command, "DATA\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        handle_error("Could not send data command to the server");
    }

    sprintf(command, "Subject: %s\r\n", email_subject);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        handle_error("Could not send email subject to the server");
    }

    if (send(sockfd, email_body, strlen(email_body), 0) == -1) {
        handle_error("Could not send email body to the server");
    }

    sprintf(command, "\r\n.\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        handle_error("Could not send the termination command to the server");
    }

    printf("Email sent to %s successfully!\n", recipient_email);
}

int main() {
    char server_address[MAX_BUFFER_SIZE];
    char server_port[MAX_BUFFER_SIZE];
    char sender_email[MAX_BUFFER_SIZE];
    char sender_password[MAX_BUFFER_SIZE];
    char recipient_email[MAX_BUFFER_SIZE];
    char email_subject[MAX_BUFFER_SIZE];
    char email_body[MAX_BUFFER_SIZE];
    char user_input[MAX_USER_INPUT_SIZE];

    printf("Please enter the email server address: ");
    fgets(user_input, MAX_USER_INPUT_SIZE, stdin);
    sscanf(user_input, "%s", server_address);

    printf("Please enter the email server port: ");
    fgets(user_input, MAX_USER_INPUT_SIZE, stdin);
    sscanf(user_input, "%s", server_port);

    printf("Please enter the sender email address: ");
    fgets(user_input, MAX_USER_INPUT_SIZE, stdin);
    sscanf(user_input, "%s", sender_email);

    printf("Please enter the sender email password: ");
    fgets(user_input, MAX_USER_INPUT_SIZE, stdin);
    sscanf(user_input, "%s", sender_password);

    printf("Please enter the recipient email address: ");
    fgets(user_input, MAX_USER_INPUT_SIZE, stdin);
    sscanf(user_input, "%s", recipient_email);

    printf("Please enter the email subject: ");
    fgets(user_input, MAX_USER_INPUT_SIZE, stdin);
    sscanf(user_input, "%s", email_subject);

    printf("Please enter the email body: ");
    fgets(user_input, MAX_USER_INPUT_SIZE, stdin);
    sscanf(user_input, "%s", email_body);

    printf("\nEstablishing connection with the email server...\n");
    setup_socket_connection(server_address, server_port);

    printf("\nSending email...\n");
    send_email(recipient_email, email_subject, email_body);

    printf("\nClosing the connection...\n");
    close(sockfd);

    return 0;
}
//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/* Function declaration */
int connect_to_smtp_server(char* server_ip, int server_port);
int send_command(int sock_fd, char* command);
int read_response(int sock_fd, char* buffer, int buffer_size, char* expected_response_code);

int main(int argc, char** argv) {
    if(argc != 4) {
        printf("USAGE: <program> <server_ip> <server_port> <email_address>\n");
        exit(1);
    }

    char* server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char* email_address = argv[3];

    /* Connect to SMTP server */
    int sock_fd = connect_to_smtp_server(server_ip, server_port);

    /* Introduce ourselves */
    send_command(sock_fd, "EHLO chatbot");

    /* Send mail from */
    char mail_from[256];
    sprintf(mail_from, "MAIL FROM: <%s>", email_address);
    send_command(sock_fd, mail_from);

    /* Send rcpt to */
    char rcpt_to[256];
    printf("Enter recipient email address: ");
    scanf("%255s", rcpt_to);
    send_command(sock_fd, rcpt_to);

    /* Send data */
    send_command(sock_fd, "DATA");

    /* Compose email */
    char email_body[BUFFER_SIZE];
    printf("Enter email body:\n");
    fgets(email_body, BUFFER_SIZE, stdin);

    /* Send email body */
    send_command(sock_fd, email_body);

    /* Send message end character */
    send_command(sock_fd, ".");

    /* Say goodbye */
    send_command(sock_fd, "QUIT");

    /* Close socket */
    close(sock_fd);

    return 0;
}

/*
 * This function creates a socket and connects to the SMTP server.
 * Returns the socket file descriptor if successful, -1 if unsuccessful.
 */
int connect_to_smtp_server(char* server_ip, int server_port) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(sock_fd < 0) {
        perror("Error creating socket");
        return -1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    if(connect(sock_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    return sock_fd;
}

/*
 * This function sends a command to the SMTP server and checks the response code against the expected code.
 * Returns 0 if successful, -1 if unsuccessful.
 */
int send_command(int sock_fd, char* command) {
    printf(">> %s\n", command);

    if(send(sock_fd, command, strlen(command), 0) < 0) {
        perror("Error sending command");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    return read_response(sock_fd, buffer, BUFFER_SIZE, "2");
}

/*
 * This function reads the server's response and checks if it matches the expected response code (first digit).
 * Returns 0 if successful, -1 if unsuccessful.
 */
int read_response(int sock_fd, char* buffer, int buffer_size, char* expected_response_code) {
    if(recv(sock_fd, buffer, buffer_size, 0) < 0) {
        perror("Error reading response");
        return -1;
    }

    printf("<< %s", buffer);

    if(buffer[0] != expected_response_code[0]) {
        printf("Unexpected response code: %c\n", buffer[0]);
        return -1;
    }

    return 0;
}
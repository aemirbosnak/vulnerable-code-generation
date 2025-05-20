//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024
#define MAX_ADDR_SIZE 256

/* Function to send a message to the SMTP server */
int send_msg(int sock, char *msg)
{
    int msg_len = strlen(msg);
    if (send(sock, msg, msg_len, 0) != msg_len) {
        return -1;
    }
    return 0;
}

/* Function to receive a message from the SMTP server */
int recv_msg(int sock, char *response)
{
    int bytes_recv = recv(sock, response, MAX_MSG_SIZE - 1, 0);
    if (bytes_recv <= 0) {
        return -1;
    }
    response[bytes_recv] = '\0';
    return 0;
}

/* Main function */
int main(int argc, char *argv[]) {
    int sock;
    char server_address[MAX_ADDR_SIZE], email_to[MAX_ADDR_SIZE], email_from[MAX_ADDR_SIZE], response[MAX_MSG_SIZE];
    int server_port;
    char *message = "Hello, World!";

    // Get the server address and port from the command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <server_port>\n", argv[0]);
        return 1;
    }
    strcpy(server_address, argv[1]);
    server_port = atoi(argv[2]);

    // Get the email addresses from the user
    printf("Enter your email address: ");
    fgets(email_from, MAX_ADDR_SIZE, stdin);
    email_from[strcspn(email_from, "\n")] = '\0';  // Remove newline character

    printf("Enter recipient email address: ");
    fgets(email_to, MAX_ADDR_SIZE, stdin);
    email_to[strcspn(email_to, "\n")] = '\0';  // Remove newline character

    // Create a socket for the connection
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_address, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Receive the server's banner message
    if (recv_msg(sock, response) == -1) {
        perror("recv");
        return 1;
    }

    // Send the HELO message
    sprintf(response, "HELO %s\r\n", server_address);
    if (send_msg(sock, response) == -1) {
        perror("send");
        return 1;
    }
    if (recv_msg(sock, response) == -1) {
        perror("recv");
        return 1;
    }

    // Send the MAIL FROM message
    sprintf(response, "MAIL FROM: <%s>\r\n", email_from);
    if (send_msg(sock, response) == -1) {
        perror("send");
        return 1;
    }
    if (recv_msg(sock, response) == -1) {
        perror("recv");
        return 1;
    }

    // Send the RCPT TO message
    sprintf(response, "RCPT TO: <%s>\r\n", email_to);
    if (send_msg(sock, response) == -1) {
        perror("send");
        return 1;
    }
    if (recv_msg(sock, response) == -1) {
        perror("recv");
        return 1;
    }

    // Send the DATA message
    if (send_msg(sock, "DATA\r\n") == -1) {
        perror("send");
        return 1;
    }
    if (recv_msg(sock, response) == -1) {
        perror("recv");
        return 1;
    }

    // Send the message body
    sprintf(response, "%s\r\n.\r\n", message);
    if (send_msg(sock, response) == -1) {
        perror("send");
        return 1;
    }
    if (recv_msg(sock, response) == -1) {
        perror("recv");
        return 1;
    }

    // Send the QUIT message
    if (send_msg(sock, "QUIT\r\n") == -1) {
        perror("send");
        return 1;
    }
    if (recv_msg(sock, response) == -1) {
        perror("recv");
        return 1;
    }
    
    // Close the socket
    close(sock);

    printf("Message sent successfully.\n");
    return 0;
}
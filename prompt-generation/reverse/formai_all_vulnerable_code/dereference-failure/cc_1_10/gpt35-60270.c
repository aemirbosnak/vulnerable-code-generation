//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: mathematical
// SMTP Client example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define FROM_ADDR "sender@example.com" // your email address
#define TO_ADDR "recipient@example.com" // recipient email address
#define SERVER_NAME "smtp.example.com" // your SMTP server name
#define SERVER_PORT 25 // SMTP port number

typedef enum {
    SUCCESS, FAILURE
} result_t;

result_t send_data(int sock, char *data) {
    if (send(sock, data, strlen(data), 0) == -1) {
        perror("Error sending data");
        return FAILURE;
    }
    return SUCCESS;
}

result_t receive_data(int sock, char *buf, int buflen) {
    int len = recv(sock, buf, buflen, 0);
    if (len < 0) {
        perror("Error receiving data");
        return FAILURE;
    }
    buf[len] = '\0';
    return SUCCESS;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    struct hostent *server = gethostbyname(SERVER_NAME);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host: %s\n", SERVER_NAME);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    char buf[1024];
    receive_data(sock, buf, sizeof(buf)); // receive the server's greeting
    printf("Server Greeting: %s\n", buf);

    // send HELO command
    char helo_cmd[512];
    sprintf(helo_cmd, "HELO %s\r\n", SERVER_NAME);
    send_data(sock, helo_cmd);
    receive_data(sock, buf, sizeof(buf));
    printf("Response to HELO: %s\n", buf);

    // send MAIL FROM command
    char mail_from[512];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", FROM_ADDR);
    send_data(sock, mail_from);
    receive_data(sock, buf, sizeof(buf));
    printf("Response to MAIL FROM: %s\n", buf);

    // send RCPT TO command
    char rcpt_to[512];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", TO_ADDR);
    send_data(sock, rcpt_to);
    receive_data(sock, buf, sizeof(buf));
    printf("Response to RCPT TO: %s\n", buf);

    // send DATA command
    char data_cmd[512];
    sprintf(data_cmd, "DATA\r\n");
    send_data(sock, data_cmd);
    receive_data(sock, buf, sizeof(buf));
    printf("Response to DATA: %s\n", buf);

    // send email body
    char email_body[1024];
    sprintf(email_body, "From: <%s>\r\nTo: <%s>\r\nSubject: Test Email\r\n\r\nHello World!\r\n.\r\n", FROM_ADDR, TO_ADDR);
    send_data(sock, email_body);
    receive_data(sock, buf, sizeof(buf));
    printf("Response to email body: %s\n", buf);

    // send QUIT command
    char quit_cmd[512];
    sprintf(quit_cmd, "QUIT\r\n");
    send_data(sock, quit_cmd);
    receive_data(sock, buf, sizeof(buf));
    printf("Response to QUIT: %s\n", buf);

    close(sock);
    return EXIT_SUCCESS;
}
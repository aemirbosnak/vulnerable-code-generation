//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_ADDRESS_LENGTH 100

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct email *email;
    email = malloc(sizeof(struct email));
    if (email == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Prompt user for email details
    printf("Enter sender's email address: ");
    fgets(email->from, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter recipient's email address: ");
    fgets(email->to, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter subject: ");
    fgets(email->subject, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter message: ");
    fgets(email->message, MAX_MESSAGE_LENGTH, stdin);

    // Connect to SMTP server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25);
    inet_pton(AF_INET, "localhost", &server_address.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send email
    char send_buffer[1024];
    sprintf(send_buffer, "HELO introspective_client\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "MAIL FROM:<%s>\r\n", email->from);
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "RCPT TO:<%s>\r\n", email->to);
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "DATA\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);
    send(sock, email->message, strlen(email->message), 0);
    sprintf(send_buffer, "\r\n.QUIT\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);

    // Close connection
    char recv_buffer[1024];
    recv(sock, recv_buffer, 1024, 0);
    printf("SMTP server response: %s\n", recv_buffer);
    close(sock);

    free(email);
    return 0;
}
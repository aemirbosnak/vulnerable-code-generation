//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

void connect_to_server(int sock);
void send_email(int sock, struct email *email);
void recv_email(int sock, struct email *email);
void close_socket(int sock);

int main() {
    int sock;
    struct email email;

    // Connect to the server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    connect_to_server(sock);

    // Prompt the user for the recipient's email address
    printf("Enter the recipient's email address: ");
    fgets(email.to, MAX_MESSAGE_LENGTH, stdin);

    // Prompt the user for the subject and message
    printf("Enter the subject: ");
    fgets(email.subject, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter the message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    // Send the email
    send_email(sock, &email);

    // Close the socket
    close_socket(sock);

    return 0;
}

void connect_to_server(int sock) {
    struct sockaddr_in server_addr;

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
}

void send_email(int sock, struct email *email) {
    char buffer[MAX_MESSAGE_LENGTH];

    // Format the email message
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n%s",
            email->from, email->to, email->subject, email->message);

    // Send the email message
    send(sock, buffer, strlen(buffer), 0);
}

void recv_email(int sock, struct email *email) {
    char buffer[MAX_MESSAGE_LENGTH];

    // Receive the email message
    recv(sock, buffer, MAX_MESSAGE_LENGTH, 0);

    // Parse the email message
    sscanf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n%s",
            email->from, email->to, email->subject, email->message);
}

void close_socket(int sock) {
    close(sock);
}
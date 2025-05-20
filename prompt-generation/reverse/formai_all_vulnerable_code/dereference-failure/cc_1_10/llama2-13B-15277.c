//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

void send_email(struct email *email) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return;
    }

    char message[MAX_MESSAGE_LENGTH];
    snprintf(message, sizeof(message), "From: %s\r\nTo: %s\r\nSubject: %s\r\n%s",
             email->from, email->to, email->subject, email->message);

    send(sock, message, strlen(message), 0);

    char buffer[MAX_MESSAGE_LENGTH];
    recv(sock, buffer, MAX_MESSAGE_LENGTH, 0);

    printf("Received message: %s\n", buffer);

    close(sock);
}

int main() {
    struct email email = {
        .from = "john@example.com",
        .to = "jane@example.com",
        .subject = "Hello from C!",
        .message = "This is a test email from C."
    };

    send_email(&email);

    return 0;
}
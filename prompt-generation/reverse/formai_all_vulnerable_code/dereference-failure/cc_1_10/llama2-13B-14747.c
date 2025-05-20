//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25
#define HOST "smtp.gmail.com"

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

void send_email(struct email *email) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, HOST, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    char *message = email->message;
    int message_len = strlen(message);
    char *message_copy = malloc(message_len);
    strcpy(message_copy, message);

    send(sock, message_copy, message_len, 0);

    free(message_copy);
    close(sock);
}

int main() {
    struct email email = {
        .from = "user@example.com",
        .to = "recipient@example.com",
        .subject = "Test Email",
        .message = "This is a test email sent using C."
    };

    send_email(&email);

    return 0;
}
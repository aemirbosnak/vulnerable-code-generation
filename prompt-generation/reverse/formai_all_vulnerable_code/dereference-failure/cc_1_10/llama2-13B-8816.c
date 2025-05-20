//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

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

    char *message = malloc(MAX_MESSAGE_LENGTH);
    snprintf(message, MAX_MESSAGE_LENGTH, "%s <%s> %s\r\n%s", email->from, email->to, email->subject, email->message);

    send(sock, message, strlen(message), 0);

    free(message);
    close(sock);
}

int main() {
    struct email email = {
        .from = "john@example.com",
        .to = "jane@example.com",
        .subject = "Hello from C!",
        .message = "This is the first email sent from C."
    };

    send_email(&email);

    return 0;
}
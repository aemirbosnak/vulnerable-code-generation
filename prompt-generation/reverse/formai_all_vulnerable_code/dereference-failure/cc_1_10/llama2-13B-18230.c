//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_SIZE 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct email email;
    email.from = argv[1];
    email.to = argv[2];
    email.subject = "Test Email";
    email.message = "This is a test email sent using the C email client.";

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    char buffer[MAX_MESSAGE_SIZE];
    snprintf(buffer, MAX_MESSAGE_SIZE, "FROM: %s\r\nTO: %s\r\nSUBJECT: %s\r\nMESSAGE: %s\r\n\r\n", email.from, email.to, email.subject, email.message);

    send(sock, buffer, strlen(buffer), 0);

    char line[1024];
    while (recv(sock, line, 1024, 0) > 0) {
        printf("%s", line);
    }

    close(sock);
    return 0;
}
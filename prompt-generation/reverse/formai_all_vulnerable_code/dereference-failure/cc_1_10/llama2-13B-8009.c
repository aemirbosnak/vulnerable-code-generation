//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

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
        exit(1);
    }

    struct email email;
    printf("Enter sender's email: ");
    fgets(email.from, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter recipient's email: ");
    fgets(email.to, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter subject: ");
    fgets(email.subject, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    // Send email
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("smtp.gmail.com")
    };
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    char buffer[1024];
    sprintf(buffer, "HELO %s\r\n", "localhost");
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "MAIL FROM: <%s>\r\n", email.from);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "RCPT TO: <%s>\r\n", email.to);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);

    send(sock, email.message, strlen(email.message), 0);

    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);

    close(sock);
    return 0;
}
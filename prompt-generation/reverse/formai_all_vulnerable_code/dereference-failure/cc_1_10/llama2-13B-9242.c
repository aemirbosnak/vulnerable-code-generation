//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 25
#define MAX_LENGTH 256

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
    printf("Enter from address: ");
    fgets(email.from, MAX_LENGTH, stdin);
    email.from[strcspn(email.from, "\n")] = 0;

    printf("Enter to address: ");
    fgets(email.to, MAX_LENGTH, stdin);
    email.to[strcspn(email.to, "\n")] = 0;

    printf("Enter subject: ");
    fgets(email.subject, MAX_LENGTH, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0;

    printf("Enter message: ");
    fgets(email.message, MAX_LENGTH, stdin);
    email.message[strcspn(email.message, "\n")] = 0;

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(1);
    }

    send(sock, email.message, strlen(email.message), 0);

    char buffer[1024];
    recv(sock, buffer, 1024, 0);

    printf("Server response: %s\n", buffer);

    close(sock);
    return 0;
}
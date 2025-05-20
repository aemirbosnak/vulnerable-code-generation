//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MESSAGE_LENGTH 512
#define MAX_USERNAME_LENGTH 64
#define MAX_HOSTNAME_LENGTH 64

typedef struct {
    char *username;
    char *hostname;
    char *message;
} email_t;

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    email_t email;
    printf("Enter your username: ");
    fgets(email.username, MAX_USERNAME_LENGTH, stdin);
    printf("Enter your message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    send(sock, email.username, strlen(email.username), 0);
    send(sock, email.message, strlen(email.message), 0);

    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("Server response: %s\n", buffer);

    close(sock);
    return 0;
}
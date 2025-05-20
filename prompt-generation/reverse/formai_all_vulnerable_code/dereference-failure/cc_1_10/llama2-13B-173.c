//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EMAIL_LENGTH 512
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char *username;
    char *password;
    char *email;
} user_info_t;

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(25),
        .sin_addr.s_addr = inet_addr("smtp.example.com")
    };

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    user_info_t user_info;
    printf("Enter your email address: ");
    fgets(user_info.email, MAX_EMAIL_LENGTH, stdin);
    printf("Enter your username: ");
    fgets(user_info.username, MAX_USERNAME_LENGTH, stdin);
    printf("Enter your password: ");
    fgets(user_info.password, MAX_PASSWORD_LENGTH, stdin);

    char command[1024];
    sprintf(command, "USER %s %s", user_info.username, user_info.password);
    send(sock, command, strlen(command), 0);

    char response[1024];
    recv(sock, response, 1024, 0);
    printf("%s\n", response);

    sprintf(command, "MAIL FROM:<%s>", user_info.email);
    send(sock, command, strlen(command), 0);

    char recipient[1024];
    printf("Enter the recipient's email address: ");
    fgets(recipient, MAX_EMAIL_LENGTH, stdin);
    sprintf(command, "RCPT TO:<%s>", recipient);
    send(sock, command, strlen(command), 0);

    char subject[1024];
    printf("Enter the email subject: ");
    fgets(subject, MAX_EMAIL_LENGTH, stdin);
    sprintf(command, "DATA\r\nSubject: %s\r\n\r\n", subject);
    send(sock, command, strlen(command), 0);

    char body[1024];
    printf("Enter the email body: ");
    fgets(body, MAX_EMAIL_LENGTH, stdin);
    sprintf(command, "DATA\r\nBody: %s\r\n\r\n", body);
    send(sock, command, strlen(command), 0);

    char quit[1024];
    sprintf(quit, "QUIT\r\n");
    send(sock, quit, strlen(quit), 0);

    recv(sock, response, 1024, 0);
    printf("%s\n", response);

    close(sock);
    return 0;
}
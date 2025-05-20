//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_LENGTH 500

typedef struct {
    char *email;
    char *password;
} user_info;

user_info *user_list = NULL;
int sock;

void init_user_list() {
    user_list = (user_info *)malloc(sizeof(user_info));
    user_list->email = "example@example.com";
    user_list->password = "password123";
}

void connect_to_server() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }
}

void send_email(char *to, char *subject, char *message) {
    char buffer[MAX_LENGTH];
    snprintf(buffer, MAX_LENGTH, "To: %s\nSubject: %s\n%s", to, subject, message);
    send(sock, buffer, strlen(buffer), 0);
}

void receive_email() {
    char buffer[MAX_LENGTH];
    recv(sock, buffer, MAX_LENGTH, 0);
    printf("%s", buffer);
}

int main() {
    init_user_list();
    connect_to_server();

    while (1) {
        printf("Welcome to the email client!\n");
        printf("Email: ");
        char email[50];
        scanf("%s", email);
        send_email(email, "Subject", "Hello from the email client!");

        printf("Subject: ");
        char subject[50];
        scanf("%s", subject);
        send_email(email, subject, "Hello from the email client!");

        printf("Message: ");
        char message[500];
        scanf("%s", message);
        send_email(email, subject, message);

        receive_email();
    }

    return 0;
}
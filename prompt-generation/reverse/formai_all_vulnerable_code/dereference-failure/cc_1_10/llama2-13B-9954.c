//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

void print_menu();
void send_email(struct email *);
void recv_email(struct email *);
void quit();

int main() {
    struct email email;

    print_menu();

    while (1) {
        scanf("%c", &email.from[0]);
        if (email.from[0] == 'q') {
            quit();
            break;
        }

        scanf("%c", &email.to[0]);
        scanf("%c", &email.subject[0]);
        scanf("%c", &email.message[0]);

        send_email(&email);
    }

    return 0;
}

void print_menu() {
    printf("Email Client Menu\n");
    printf("-----------------\n");
    printf("q: Quit\n");
    printf("s: Send Email\n");
    printf("r: Recieve Email\n");
    printf("e: Edit Email\n");
    printf("d: Delete Email\n");
    printf("p: Print Email\n");
    printf("-------------\n");
}

void send_email(struct email *email) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    char *message = email->message;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    send(sock, message, strlen(message), 0);

    close(sock);
}

void recv_email(struct email *email) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    buffer[1024 - 1] = '\0';

    email->message = buffer;

    close(sock);
}

void quit() {
    printf("Goodbye!\n");
    exit(0);
}
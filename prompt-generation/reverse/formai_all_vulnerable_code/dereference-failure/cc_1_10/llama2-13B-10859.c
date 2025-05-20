//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <resolv.h>
#include <unistd.h>
#include <sys/select.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 256

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
        exit(EXIT_FAILURE);
    }

    struct email email;
    printf("Enter sender's email address: ");
    scanf("%s", email.from);
    printf("Enter recipient's email address: ");
    scanf("%s", email.to);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);
    email.message[strcspn(email.message, "\n")] = 0;

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    send(sock, email.message, strlen(email.message), 0);
    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("Server response: %s\n", buffer);

    close(sock);
    return 0;
}
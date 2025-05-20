//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 25
#define MAX_LENGTH 1024

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    struct email email;
    printf("Enter sender's email: ");
    fgets(email.from, MAX_LENGTH, stdin);
    printf("Enter recipient's email: ");
    fgets(email.to, MAX_LENGTH, stdin);
    printf("Enter subject: ");
    fgets(email.subject, MAX_LENGTH, stdin);
    printf("Enter message: ");
    fgets(email.message, MAX_LENGTH, stdin);

    char *message = NULL;
    message = malloc(strlen(email.message) + 1);
    strcpy(message, email.message);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    send(sock, message, strlen(message), 0);

    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("%s\n", buffer);

    close(sock);
    free(message);
    return 0;
}
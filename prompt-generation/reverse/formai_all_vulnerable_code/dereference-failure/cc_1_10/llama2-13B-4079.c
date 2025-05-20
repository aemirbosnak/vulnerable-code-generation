//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25

#define MAX_MESSAGE_LENGTH 512
#define MAX_ADDRESS_LENGTH 100

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
    fgets(email.from, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter recipient's email: ");
    fgets(email.to, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter subject: ");
    fgets(email.subject, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    char buffer[1024];
    sprintf(buffer, "HELO %s\r\n", email.from);
    send(sock, buffer, strlen(buffer), 0);

    char *line;
    while ((line = fgets(buffer, 1024, stdin)) != NULL) {
        sprintf(buffer, "%s\r\n", line);
        send(sock, buffer, strlen(buffer), 0);
    }

    char *message = malloc(MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);

    recv(sock, buffer, 1024, 0);
    printf("Server response: %s\n", buffer);

    free(message);
    close(sock);

    return 0;
}
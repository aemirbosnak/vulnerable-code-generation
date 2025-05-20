//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

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
        perror("socket creation failed");
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

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    char *message = "Hello, this is a test email from the C client!";
    send(sock, message, strlen(message), 0);

    char buffer[MAX_LENGTH];
    recv(sock, buffer, MAX_LENGTH, 0);
    printf("Received message: %s\n", buffer);

    close(sock);
    return 0;
}
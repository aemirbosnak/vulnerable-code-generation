//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 256

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
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

    // Connect to the server
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send the email
    char buffer[1024];
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n%s\r\n",
            email.from, email.to, email.subject, email.message);
    send(sock, buffer, strlen(buffer), 0);

    // Receive the response
    char response[1024];
    recv(sock, response, 1024, 0);
    printf("Server response: %s\n", response);

    // Close the connection
    close(sock);

    return 0;
}
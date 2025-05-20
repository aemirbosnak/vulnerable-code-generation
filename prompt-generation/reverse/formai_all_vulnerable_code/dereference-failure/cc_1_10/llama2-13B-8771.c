//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024
#define PORT 25

struct email {
    char from[50];
    char to[50];
    char subject[50];
    char message[100];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct email email;
    printf("Enter sender's email: ");
    fgets(email.from, 50, stdin);
    printf("Enter recipient's email: ");
    fgets(email.to, 50, stdin);
    printf("Enter subject: ");
    fgets(email.subject, 50, stdin);
    printf("Enter message: ");
    fgets(email.message, 100, stdin);

    // Create the email message
    char *message = malloc(strlen(email.message) + 1);
    strcpy(message, email.message);

    // Set up the email headers
    char *headers = malloc(100);
    sprintf(headers, "From: %s\r\nTo: %s\r\nSubject: %s\r\n", email.from, email.to, email.subject);

    // Send the email
    send(sock, headers, strlen(headers), 0);
    send(sock, message, strlen(message), 0);

    // Close the socket
    close(sock);

    return 0;
}
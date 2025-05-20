//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    int sock;
    struct email email;
    char buffer[MAX_MESSAGE_LENGTH];

    // Connect to the server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("mail.example.com")
    };

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Prompt the user for the email details
    printf("Enter the sender's email address: ");
    fgets(email.from, MAX_MESSAGE_LENGTH, stdin);
    email.from[strcspn(email.from, "\n")] = 0;

    printf("Enter the recipient's email address: ");
    fgets(email.to, MAX_MESSAGE_LENGTH, stdin);
    email.to[strcspn(email.to, "\n")] = 0;

    printf("Enter the subject: ");
    fgets(email.subject, MAX_MESSAGE_LENGTH, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0;

    printf("Enter the message: ");
    fgets(buffer, MAX_MESSAGE_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    // Send the email
    send(sock, email.from, strlen(email.from), 0);
    send(sock, email.to, strlen(email.to), 0);
    send(sock, email.subject, strlen(email.subject), 0);
    send(sock, buffer, strlen(buffer), 0);

    // Close the connection
    close(sock);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

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
        exit(EXIT_FAILURE);
    }

    struct email email;
    printf("Enter from address: ");
    fgets(email.from, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter to address: ");
    fgets(email.to, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter subject: ");
    fgets(email.subject, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    // Build the email message
    char message[MAX_MESSAGE_LENGTH];
    sprintf(message, "%s\n%s\n%s\n%s", email.from, email.subject, email.message, email.to);

    // Connect to the SMTP server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send the email
    send(sock, message, strlen(message), 0);

    // Receive the response
    char response[MAX_MESSAGE_LENGTH];
    recv(sock, response, MAX_MESSAGE_LENGTH, 0);

    // Print the response
    printf("%s\n", response);

    // Close the socket
    close(sock);

    return 0;
}
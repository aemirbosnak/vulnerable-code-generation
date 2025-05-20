//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Print a happy message
    printf("😊 Welcome to the happy email client! 😊\n");

    // Loop forever to handle incoming messages
    while (1) {
        // Receive a message from the server
        struct email message;
        recv(sock, (char *)&message, sizeof(message), 0);

        // Print the message
        printf("📧 New message from %s to %s with subject %s:\n%s\n", message.from, message.to, message.subject, message.message);

        // Send a response back to the server
        char *response = "😊 Thank you for your email! 😊";
        send(sock, response, strlen(response), 0);

        // Free the memory for the message
        free(message.from);
        free(message.to);
        free(message.subject);
        free(message.message);
    }

    return 0;
}
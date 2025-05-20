//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8025

#define MAX_MESSAGE_LENGTH 256
#define MAX_EMAIL_LENGTH 1024

struct email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[MAX_MESSAGE_LENGTH];
};

int main() {
    int sock, client_sock;
    struct email email;
    char buffer[1024];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a specific address and port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept an incoming connection
    client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("Error accepting incoming connection");
        exit(1);
    }

    printf("Connection accepted from client...\n");

    // Read email from client
    while (fgets(buffer, 1024, client_sock) != NULL) {
        // Parse email from client
        char *email_ptr = strtok(buffer, "\n");
        email.sender[0] = '\0';
        email.recipient[0] = '\0';
        email.subject[0] = '\0';
        email.message[0] = '\0';

        // Extract email fields from client message
        if (email_ptr != NULL) {
            strcpy(email.sender, email_ptr);
            email_ptr = strtok(NULL, " ");
            strcpy(email.recipient, email_ptr);
            email_ptr = strtok(NULL, " ");
            strcpy(email.subject, email_ptr);
            email_ptr = strtok(NULL, "\n");
            strcpy(email.message, email_ptr);
        }

        // Send email to recipient
        if (send(client_sock, email.message, strlen(email.message), 0) < 0) {
            perror("Error sending email");
            exit(1);
        }

        printf("Email sent to %s\n", email.recipient);
    }

    // Close the client socket
    close(client_sock);

    // Close the server socket
    close(sock);

    return 0;
}
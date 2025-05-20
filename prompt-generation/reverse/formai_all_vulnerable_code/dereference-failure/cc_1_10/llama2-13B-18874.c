//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold the email data
typedef struct {
    char *from;
    char *to;
    char *subject;
    char *body;
} Email;

// Function to send an email
void send_email(Email *email) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send the email data
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s\n%s\n%s\n%s", email->from, email->to, email->subject, email->body);
    send(sock, buffer, strlen(buffer), 0);

    // Close the socket
    close(sock);
}

// Function to handle incoming email messages
void handle_message(int sock) {
    char buffer[1024];
    // Receive the email message
    recv(sock, buffer, sizeof(buffer), 0);

    // Parse the email message
    Email *email = malloc(sizeof(Email));
    email->from = strtok(buffer, "\n");
    email->to = strtok(NULL, "\n");
    email->subject = strtok(NULL, "\n");
    email->body = strtok(NULL, "\n");

    // Send the email to the next process in the chain
    if (email->from && email->to && email->subject && email->body) {
        send_email(email);
    }

    // Free the email structure
    free(email);
}

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    // Fork a new process to handle incoming messages
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process, handle incoming messages
        while (1) {
            int client_sock = accept(sock, NULL, NULL);
            handle_message(client_sock);
        }
    } else {
        // Parent process, just keep listening
        while (1) {
            // Do nothing, just keep listening
        }
    }

    return 0;
}
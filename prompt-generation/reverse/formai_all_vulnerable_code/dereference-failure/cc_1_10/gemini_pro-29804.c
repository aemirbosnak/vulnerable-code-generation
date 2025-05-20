//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Defines the SMTP port number
#define SMTP_PORT 25

// Defines the maximum size of the message to be sent
#define MAX_MESSAGE_SIZE 1024

// Defines the maximum number of recipients for the message
#define MAX_RECIPIENTS 10

// Creates a socket for communication with the SMTP server
int create_socket() {
    // Creates a socket for communication with the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Connects to the SMTP server
void connect_to_server(int sockfd, char *server_ip) {
    // Creates a sockaddr_in structure for the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connects to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
}

// Sends a message to the SMTP server
void send_message(int sockfd, char *message, char **recipients, int num_recipients) {
    // Sends the message to the SMTP server
    if (write(sockfd, message, strlen(message)) == -1) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Sends the recipients to the SMTP server
    for (int i = 0; i < num_recipients; i++) {
        if (write(sockfd, recipients[i], strlen(recipients[i])) == -1) {
            perror("Error sending recipient");
            exit(EXIT_FAILURE);
        }
    }
}

// Closes the connection to the SMTP server
void close_connection(int sockfd) {
    // Closes the connection to the SMTP server
    if (close(sockfd) == -1) {
        perror("Error closing connection");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Checks if the correct number of arguments have been provided
    if (argc != 4) {
        printf("Usage: %s <server_ip> <message> <recipient1> [recipient2] ... [recipientN]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creates a socket for communication with the SMTP server
    int sockfd = create_socket();

    // Connects to the SMTP server
    connect_to_server(sockfd, argv[1]);

    // Creates the message to be sent
    char message[MAX_MESSAGE_SIZE];
    snprintf(message, MAX_MESSAGE_SIZE, "Subject: %s\n\n%s", argv[2], argv[3]);

    // Creates an array of recipients for the message
    char *recipients[MAX_RECIPIENTS];
    recipients[0] = argv[3];
    for (int i = 4; i < argc; i++) {
        recipients[i - 3] = argv[i];
    }

    // Sends the message to the SMTP server
    send_message(sockfd, message, recipients, argc - 3);

    // Closes the connection to the SMTP server
    close_connection(sockfd);

    return EXIT_SUCCESS;
}
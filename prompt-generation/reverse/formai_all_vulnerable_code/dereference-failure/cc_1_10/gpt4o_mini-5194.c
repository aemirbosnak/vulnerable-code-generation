//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

// Function to connect to the POP3 server
int connect_to_pop3(const char *hostname) {
    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to POP3 server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send and receive messages from the server
void send_message(int sock, const char *message) {
    send(sock, message, strlen(message), 0);
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[sizeof(buffer) - 1] = '\0'; // null-terminate the buffer
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Connect to the POP3 server
    int sock = connect_to_pop3(hostname);
    send_message(sock, "USER ");  // Sending the USER command
    send_message(sock, username); // Username
    send_message(sock, "\r\n"); // Ending the command

    send_message(sock, "PASS ");  // Sending the PASS command
    send_message(sock, password); // Password
    send_message(sock, "\r\n"); // Ending the command

    // Get the list of emails
    send_message(sock, "LIST\r\n");  // Requesting the email list

    // Retrieve email details
    char option;
    printf("Do you want to read an email? (y/n): ");
    scanf(" %c", &option);
    
    if (option == 'y') {
        int email_number;
        printf("Enter email number: ");
        scanf("%d", &email_number);

        // Retrieve the email with RETR command
        char retr_command[BUFFER_SIZE];
        sprintf(retr_command, "RETR %d\r\n", email_number);
        send_message(sock, retr_command); // Requesting the specific email

    }

    // Disconnect from server
    send_message(sock, "QUIT\r\n");
    close(sock);
    return EXIT_SUCCESS;
}
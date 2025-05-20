//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

// Struct to store email information
typedef struct {
    char* uid;
    char* subject;
} Email;

// Function to connect to the POP3 server
int pop3_connect(const char* server, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send command to the server and read response
char* pop3_send_command(int sockfd, const char* command) {
    static char response[BUFFER_SIZE];
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, sizeof(response), 0);
    return response;
}

// Function to authenticate with the POP3 server
void pop3_authenticate(int sockfd, const char* username, const char* password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    printf("%s", pop3_send_command(sockfd, command));

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    printf("%s", pop3_send_command(sockfd, command));
}

// Function to list messages from the server
void pop3_list_messages(int sockfd) {
    char* response = pop3_send_command(sockfd, "LIST\r\n");
    printf("Message List:\n%s", response);
}

// Function to retrieve an email by its index
Email* pop3_retrieve_email(int sockfd, int index) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", index);
    char* response = pop3_send_command(sockfd, command);

    Email* email = (Email*)malloc(sizeof(Email));
    email->uid = strdup("uid_example"); // Extract UID from response if needed
    email->subject = strdup("subject_example"); // Extract subject from response if needed

    printf("Email #%d:\n%s\n", index, response);
    return email;
}

// Function to delete an email
void pop3_delete_email(int sockfd, int index) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "DELE %d\r\n", index);
    printf("%s", pop3_send_command(sockfd, command));
}

// Function to quit the POP3 session
void pop3_quit(int sockfd) {
    printf("%s", pop3_send_command(sockfd, "QUIT\r\n"));
    close(sockfd);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* server = argv[1];
    const char* username = argv[2];
    const char* password = argv[3];

    int sockfd = pop3_connect(server, POP3_PORT);
    printf("%s\n", pop3_send_command(sockfd, "+OK POP3 server ready"));

    pop3_authenticate(sockfd, username, password);
    pop3_list_messages(sockfd);

    for (int i = 1; i <= 3; i++) { // Retrieve first 3 messages (if available)
        Email* email = pop3_retrieve_email(sockfd, i);
        free(email->uid);
        free(email->subject);
        free(email);
    }

    pop3_delete_email(sockfd, 1); // Delete first email for example
    pop3_quit(sockfd); // Close the connection

    return EXIT_SUCCESS;
}
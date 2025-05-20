//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "pop.example.com" // Replace with actual POP3 server
#define PORT 110
#define BUFFER_SIZE 1024

void print_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void pop3_send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0); // POP3 command ends with CRLF
}

char *pop3_receive_response(int sockfd) {
    char *response = (char *)malloc(BUFFER_SIZE);
    int bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        print_error("Error in receiving response");
    }
    response[bytes_received] = '\0'; // NULL terminate the response
    return response;
}

void pop3_authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    pop3_send_command(sockfd, command);
    
    char *response = pop3_receive_response(sockfd);
    printf("Response: %s\n", response);
    free(response);

    snprintf(command, sizeof(command), "PASS %s", password);
    pop3_send_command(sockfd, command);
    
    response = pop3_receive_response(sockfd);
    printf("Response: %s\n", response);
    free(response);
}

void pop3_list_mails(int sockfd) {
    pop3_send_command(sockfd, "LIST");

    char *response = pop3_receive_response(sockfd);
    printf("Mail List Response: %s\n", response);
    free(response);
}

void pop3_retrieve_mail(int sockfd, int mail_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d", mail_number);
    pop3_send_command(sockfd, command);

    char *response = pop3_receive_response(sockfd);
    printf("Email #%d Content:\n%s\n", mail_number, response);
    free(response);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        print_error("Could not create socket");
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("123.456.789.000"); // Replace with actual server IP

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        print_error("Connection failed");
    }

    // Print server welcome message
    char *welcome_msg = pop3_receive_response(sockfd);
    printf("Server: %s\n", welcome_msg);
    free(welcome_msg);

    // User authentication
    const char *username = "your_email@example.com"; // Replace with your username
    const char *password = "your_password"; // Replace with your password
    pop3_authenticate(sockfd, username, password);

    // List mails
    pop3_list_mails(sockfd);

    // Retrieve a specific mail, e.g., mail #1
    pop3_retrieve_mail(sockfd, 1);

    // Close the socket
    close(sockfd);
    return 0;
}
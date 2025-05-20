//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

// Function to send and receive data
void send_receive(int sockfd, const char *msg, char *buffer) {
    send(sockfd, msg, strlen(msg), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
}

// Function to implement the POP3 client
void pop3_client(const char* server_ip, const char* username, const char* password) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive welcome message
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server: %s\n", buffer);

    // USER command
    char user_command[100];
    snprintf(user_command, sizeof(user_command), "USER %s\r\n", username);
    send_receive(sockfd, user_command, buffer);
    printf("Server: %s\n", buffer);

    // PASS command
    char pass_command[100];
    snprintf(pass_command, sizeof(pass_command), "PASS %s\r\n", password);
    send_receive(sockfd, pass_command, buffer);
    printf("Server: %s\n", buffer);

    // LIST command to get email headers
    send_receive(sockfd, "LIST\r\n", buffer);
    printf("Server: %s\n", buffer);
    printf("Email Headers:\n");

    // Read the list of messages
    while (1) {
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (strcasecmp(buffer, ".\r\n") == 0) {
            break; // End of the list
        }
        printf("%s", buffer);
    }

    // QUIT command to log out
    send_receive(sockfd, "QUIT\r\n", buffer);
    printf("Server: %s\n", buffer);

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* server_ip = argv[1];
    const char* username = argv[2];
    const char* password = argv[3];

    pop3_client(server_ip, username, password);
    
    return 0;
}
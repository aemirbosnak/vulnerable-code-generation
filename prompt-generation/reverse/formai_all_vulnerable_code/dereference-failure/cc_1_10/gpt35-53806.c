//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 25             // SMTP server port
#define MAX_MESSAGE_LENGTH 1024    // Maximum message length

// Function to send a message to the server
void send_message(int sockfd, char* message) {
    int message_len = strlen(message);
    int bytes_sent = send(sockfd, message, message_len, 0);
    if(bytes_sent == -1) {
        perror("Error in sending message");
        exit(1);
    }
}

// Function to receive a message from the server
void receive_message(int sockfd) {
    char buffer[MAX_MESSAGE_LENGTH];
    int bytes_received = recv(sockfd, buffer, MAX_MESSAGE_LENGTH, 0);
    if(bytes_received == -1) {
        perror("Error in receiving message");
        exit(1);
    }
    printf("%s", buffer);       // Print the message received
}

int main(int argc, char* argv[]) {
    int sockfd;             // Socket file descriptor
    struct sockaddr_in server_addr;     // Server address structure
    struct hostent* server_host;        // Server host structure
    char message[MAX_MESSAGE_LENGTH];   // Message buffer

    // Check if command line arguments are correct
    if(argc != 3) {
        printf("Usage: %s <server_address> <recipient_address>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Error in creating socket");
        exit(1);
    }

    // Get server host information
    server_host = gethostbyname(argv[1]);
    if(server_host == NULL) {
        perror("Error in getting host information");
        exit(1);
    }

    // Fill server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, server_host->h_addr, server_host->h_length);

    // Connect to the server
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error in connecting to server");
        exit(1);
    }

    // Receive server welcome message
    receive_message(sockfd);

    // Send EHLO message
    sprintf(message, "EHLO %s\r\n", argv[1]);
    send_message(sockfd, message);
    receive_message(sockfd);

    // Send MAIL FROM message
    sprintf(message, "MAIL FROM: <%s>\r\n", "sender@example.com");
    send_message(sockfd, message);
    receive_message(sockfd);

    // Send RCPT TO message
    sprintf(message, "RCPT TO: <%s>\r\n", argv[2]);
    send_message(sockfd, message);
    receive_message(sockfd);

    // Send DATA message
    sprintf(message, "DATA\r\n");
    send_message(sockfd, message);
    receive_message(sockfd);

    // Send message content
    sprintf(message, "Subject: Test email from SMTP client\r\n\r\n");
    send_message(sockfd, message);
    sprintf(message, "This is a test email from SMTP client.\r\n");
    send_message(sockfd, message);
    sprintf(message, ".\r\n");
    send_message(sockfd, message);
    receive_message(sockfd);

    // Send QUIT message
    sprintf(message, "QUIT\r\n");
    send_message(sockfd, message);
    receive_message(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 25
#define BUFFER_SIZE 1024

// A noble structure to hold the details of our messenger
typedef struct {
    char *sender;
    char *recipient;
    char *subject;
    char *message;
} Letter;

// A grand function to forge a connection with yonder SMTP server
int forge_connection(const char *server) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        fprintf(stderr, "Alas! The socket could not be forged.\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Alas! The connection to the SMTP server hath failed.\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// A mystical function to send a command unto the server
void send_command(int sockfd, const char *command, char *response) {
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, BUFFER_SIZE, 0);
}

// A ceremonious function to craft and send the letter
void send_letter(int sockfd, Letter *letter) {
    char response[BUFFER_SIZE];

    // Introduce ourselves to the SMTP server
    send_command(sockfd, "HELO noble.client\r\n", response);
    printf("Server Response: %s", response);
    
    // Declare the sender
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", letter->sender);
    send_command(sockfd, command, response);
    printf("Server Response: %s", response);
    
    // Declare the recipient
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", letter->recipient);
    send_command(sockfd, command, response);
    printf("Server Response: %s", response);
    
    // Begin the message
    send_command(sockfd, "DATA\r\n", response);
    printf("Server Response: %s", response);

    // Sending the message's content
    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.\r\n", letter->subject, letter->message);
    send_command(sockfd, command, response);
    printf("Server Response: %s", response);
    
    // End the transmission
    send_command(sockfd, "QUIT\r\n", response);
    printf("Server Response: %s", response);
}

// The main quest to send forth thine letter
int main() {
    Letter *letter = malloc(sizeof(Letter));
    letter->sender = "noble.sender@medievalrealm.com";
    letter->recipient = "trusted.recipient@medievalrealm.com";
    letter->subject = "A Decree from the Noble House";
    letter->message = "Hark! Mine noble friend, prepare thine army for the swift march towards glory!";

    const char *server = "127.0.0.1"; // The abode of our SMTP server
    int sockfd = forge_connection(server);
    
    send_letter(sockfd, letter);

    close(sockfd);
    free(letter);
    return 0;
}
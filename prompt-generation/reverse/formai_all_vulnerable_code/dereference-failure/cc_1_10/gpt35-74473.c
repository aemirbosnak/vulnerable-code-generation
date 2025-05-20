//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

char *receive_message(int sockfd) {
    char *message = (char *) malloc(BUFFER_SIZE);
    memset(message, 0, BUFFER_SIZE);
    recv(sockfd, message, BUFFER_SIZE, 0);
    return message;
}

void send_message(int sockfd, char *message) {
    send(sockfd, message, strlen(message), 0);
}

int main() {
    char *hostname = "mail.example.com"; // Replace with your mail server's hostname
    int port = 143; // Port number for IMAP service
    struct hostent *host = gethostbyname(hostname);
    struct sockaddr_in serv_address;
    char buffer[BUFFER_SIZE];
    printf("IMAP Client Started\n");

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Configure server address
    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(port);
    memcpy(&serv_address.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *) &serv_address, sizeof(serv_address))==-1) {
        perror("Connection failed");
        exit(1);
    }

    // Receive server greeting message
    char *message = receive_message(sockfd);
    printf("Server: %s", message);
    free(message);

    // Login to the server
    char *login_message = "A001 LOGIN user@domain.com password\n";
    send_message(sockfd, login_message);
    message = receive_message(sockfd);
    printf("Server: %s", message);
    free(message);

    // Select a mailbox
    char *select_message = "A002 SELECT INBOX\n";
    send_message(sockfd, select_message);
    message = receive_message(sockfd);
    printf("Server: %s", message);
    free(message);

    // Logout and close connection
    char *logout_message = "A003 LOGOUT\n";
    send_message(sockfd, logout_message);
    message = receive_message(sockfd);
    printf("Server: %s", message);
    free(message);
    close(sockfd);
    return 0;
}
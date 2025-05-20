//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the maximum buffer size for receiving data
#define MAX_BUFF 1024

// Function to send messages to the server
void send_message(int sockfd, char *message) {
    send(sockfd, message, strlen(message), 0);
}

// Function to receive messages from the server
void receive_message(int sockfd) {
    char buffer[MAX_BUFF];
    recv(sockfd, buffer, MAX_BUFF, 0);
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {

    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Get server information
    struct hostent *he;
    if ((he = gethostbyname(argv[1])) == NULL) {  
        perror("gethostbyname");
        exit(1);
    }

    // Define server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    // Create a socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Receive a welcome message from the server
    receive_message(sockfd);

    // Send the HELO command
    send_message(sockfd, "HELO smtp.gmail.com\n");
    receive_message(sockfd);

    // Send the MAIL FROM command
    send_message(sockfd, "MAIL FROM: <myemail@gmail.com>\n");
    receive_message(sockfd);

    // Send the RCPT TO command
    send_message(sockfd, "RCPT TO: <friendemail@gmail.com>\n");
    receive_message(sockfd);

    // Send the DATA command
    send_message(sockfd, "DATA\n");
    receive_message(sockfd);

    // Send the email message
    send_message(sockfd, "Subject: SMTP Client Example\n");
    send_message(sockfd, "From: <myemail@gmail.com>\n");
    send_message(sockfd, "To: <friendemail@gmail.com>\n");
    send_message(sockfd, "\n");
    send_message(sockfd, "Hello,\n\nThis is an example email sent using a SMTP client.\n\nThanks,\nMe\n");
    send_message(sockfd, "\n.\n");

    receive_message(sockfd);

    // Send the QUIT command
    send_message(sockfd, "QUIT\n");
    receive_message(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}
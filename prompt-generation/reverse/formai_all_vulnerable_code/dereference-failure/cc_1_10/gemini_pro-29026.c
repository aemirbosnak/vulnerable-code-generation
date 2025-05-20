//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

// Function to send a message to the SMTP server
int send_message(int sockfd, char *message) {
    // Send the message to the server
    int n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Read the response from the server
    char response[1024];
    n = read(sockfd, response, sizeof(response));
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }

    // Check if the message was sent successfully
    if (strncmp(response, "250", 3) != 0) {
        fprintf(stderr, "ERROR sending message: %s\n", response);
        return -1;
    }

    return 0;
}

// Function to send the email header
int send_header(int sockfd, char *from, char *to, char *subject) {
    // Create the header
    char header[1024];
    sprintf(header, "From: %s\nTo: %s\nSubject: %s\n\n", from, to, subject);

    // Send the header to the server
    return send_message(sockfd, header);
}

// Function to send the email body
int send_body(int sockfd, char *body) {
    // Send the body to the server
    return send_message(sockfd, body);
}

// Function to send the email footer
int send_footer(int sockfd) {
    // Send the footer to the server
    return send_message(sockfd, "\n.\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <server> <port> <from> <to> <subject>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server address and port
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Get the sender and recipient addresses
    char *from = argv[3];
    char *to = argv[4];

    // Get the subject of the email
    char *subject = argv[5];

    // Get the body of the email
    char *body = NULL;
    size_t len = 0;
    getline(&body, &len, stdin);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &serv_addr.sin_addr) <= 0) {
        perror("ERROR converting server address");
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to server");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    if (send_message(sockfd, "HELO localhost\n") < 0) {
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    if (send_header(sockfd, from, to, subject) < 0) {
        return EXIT_FAILURE;
    }

    // Send the DATA command
    if (send_message(sockfd, "DATA\n") < 0) {
        return EXIT_FAILURE;
    }

    // Send the body of the email
    if (send_body(sockfd, body) < 0) {
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    if (send_footer(sockfd) < 0) {
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}
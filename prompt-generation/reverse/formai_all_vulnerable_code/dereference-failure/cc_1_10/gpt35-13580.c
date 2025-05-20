//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 25
#define MAX_MESSAGE_LENGTH 1024

// Function to send data to the server
bool send_data(int socket_fd, char *data) {
    int bytes_sent = send(socket_fd, data, strlen(data), 0);
    if (bytes_sent == -1) {
        perror("Error in sending data");
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    // Check if server address is provided as command line argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Get server address
    char *server_address = argv[1];
    struct hostent *he = gethostbyname(server_address);
    if (he == NULL) {
        herror("Error in resolving server hostname");
        exit(EXIT_FAILURE);
    }

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    // Configure server details
    struct sockaddr_in server_details;
    memset(&server_details, 0, sizeof(server_details));
    server_details.sin_family = AF_INET;
    server_details.sin_port = htons(SERVER_PORT);
    server_details.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_details, sizeof(server_details)) == -1) {
        perror("Error in connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive greeting message from server
    char response[MAX_MESSAGE_LENGTH];
    if (recv(socket_fd, response, MAX_MESSAGE_LENGTH, 0) == -1) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response); // Print greeting message

    // Send HELO message to server
    if (!send_data(socket_fd, "HELO example.com\r\n")) {
        exit(EXIT_FAILURE);
    }

    // Receive response to HELO message
    if (recv(socket_fd, response, MAX_MESSAGE_LENGTH, 0) == -1) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response); // Print response to HELO message

    // Send MAIL FROM message to server
    if (!send_data(socket_fd, "MAIL FROM: <example@example.com>\r\n")) {
        exit(EXIT_FAILURE);
    }

    // Receive response to MAIL FROM message
    if (recv(socket_fd, response, MAX_MESSAGE_LENGTH, 0) == -1) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response); // Print response to MAIL FROM message

    // Send RCPT TO message to server
    if (!send_data(socket_fd, "RCPT TO: <example@gmail.com>\r\n")) {
        exit(EXIT_FAILURE);
    }

    // Receive response to RCPT TO message
    if (recv(socket_fd, response, MAX_MESSAGE_LENGTH, 0) == -1) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response); // Print response to RCPT TO message

    // Send DATA message to server
    if (!send_data(socket_fd, "DATA\r\n")) {
        exit(EXIT_FAILURE);
    }

    // Receive response to DATA message
    if (recv(socket_fd, response, MAX_MESSAGE_LENGTH, 0) == -1) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response); // Print response to DATA message

    // Send message body to server
    if (!send_data(socket_fd, "From: example@example.com\r\n"
                            "To: example@gmail.com\r\n"
                            "Subject: SMTP Client Example Program\r\n"
                            "\r\n"
                            "This is a test message sent through an SMTP client.\r\n"
                            ".\r\n")) {
        exit(EXIT_FAILURE);
    }

    // Receive response to message body
    if (recv(socket_fd, response, MAX_MESSAGE_LENGTH, 0) == -1) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response); // Print response to message body

    // Send QUIT message to server
    if (!send_data(socket_fd, "QUIT\r\n")) {
        exit(EXIT_FAILURE);
    }

    // Receive response to QUIT message
    if (recv(socket_fd, response, MAX_MESSAGE_LENGTH, 0) == -1) {
        perror("Error in receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response); // Print response to QUIT message

    // Close socket
    close(socket_fd);

    return 0;
}
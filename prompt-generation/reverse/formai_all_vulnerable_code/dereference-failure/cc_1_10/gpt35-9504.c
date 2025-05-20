//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function to check the server response
void check_response(char* response) {
    if (strstr(response, "OK") != NULL) {
        printf("Server response: %s\n", response);
    } else {
        printf("Error: %s\n", response);
        exit(1);
    }
}

// Function to receive the server response and return it as a string
char* receive_response(int sock) {
    char* buffer = (char*) malloc(BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive failed");
        exit(1);
    }
    return buffer;
}

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char* response;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Initialize the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993); // IMAP SSL port
    if (inet_pton(AF_INET, "localhost", &server_addr.sin_addr) <= 0) {
        perror("Invalid server address");
        exit(1);
    }    

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Receive the server greeting
    response = receive_response(sock);
    check_response(response);

    // Send the login command
    char* username = "myusername";
    char* password = "mypassword";
    char command[BUFFER_SIZE];
    sprintf(command, "LOGIN %s %s\r\n", username, password);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Send failed");
        exit(1);
    }

    // Receive and check the server response
    response = receive_response(sock);
    check_response(response);

    // Send the select command to select the inbox folder
    char* folder_name = "INBOX";
    sprintf(command, "SELECT %s\r\n", folder_name);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Send failed");
        exit(1);
    }

    // Receive and check the server response
    response = receive_response(sock);
    check_response(response);

    // Send the list command to list all emails in the folder
    sprintf(command, "UID SEARCH ALL\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Send failed");
        exit(1);
    }

    // Receive and print the server response
    response = receive_response(sock);
    printf("Server response:\n%s\n", response);

    // Close the socket
    close(sock);

    return 0;
}
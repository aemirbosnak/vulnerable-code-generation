//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to print error messages
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int main(int argc, char **argv) {
    // Check if the user entered the correct number of arguments
    if (argc != 3) {
        error("Usage: ./pop3client <hostname> <port>");
    }

    // Define variables for the hostname and port
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a variable to store the server address
    struct hostent *server_address;

    // Get the server address by hostname
    server_address = gethostbyname(hostname);

    // Check if server address is valid
    if (!server_address) {
        error("Error: Invalid server address");
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket was created successfully
    if (sockfd < 0) {
        error("Error: Failed to create socket");
    }

    // Define the socket address for the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server_address->h_addr, server_address->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    int connect_result = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    // Check if connection was successful
    if (connect_result < 0) {
        error("Error: Failed to connect to server");
    }

    // Receive the server's welcome message
    char buffer[BUFFER_SIZE] = {0};
    read(sockfd, buffer, BUFFER_SIZE);

    // Print the server's welcome message
    printf("%s", buffer);

    // Send the username to the server
    char username[BUFFER_SIZE] = "USER myusername\n";
    write(sockfd, username, strlen(username));

    // Receive the server's response to the username
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);

    // Print the server's response to the username
    printf("%s", buffer);

    // Send the password to the server
    char password[BUFFER_SIZE] = "PASS mypassword\n";
    write(sockfd, password, strlen(password));

    // Receive the server's response to the password
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);

    // Print the server's response to the password
    printf("%s", buffer);

    // Send the command to list all emails
    char list_command[BUFFER_SIZE] = "LIST\n";
    write(sockfd, list_command, strlen(list_command));

    // Receive the server's response to the list command
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);

    // Print the server's response to the list command
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}
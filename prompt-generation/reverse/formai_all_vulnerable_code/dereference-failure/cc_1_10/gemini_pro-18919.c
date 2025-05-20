//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_BUFFER_SIZE 1024

void parse_pop3_response(char *response, char *command, char *args) {
    int i = 0;
    while (response[i] != ' ') {
        command[i] = response[i];
        i++;
    }
    command[i] = '\0';

    i++;
    int j = 0;
    while (response[i] != '\0') {
        args[j] = response[i];
        i++;
        j++;
    }
    args[j] = '\0';
}

int main(int argc, char **argv) {
    // Check if the user has provided the hostname and username as arguments
    if (argc != 3) {
        printf("Usage: %s <hostname> <username>", argv[0]);
        return EXIT_FAILURE;
    }

    // Hostname and username
    char hostname[MAX_BUFFER_SIZE];
    strcpy(hostname, argv[1]);

    char username[MAX_BUFFER_SIZE];
    strcpy(username, argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect() failed");
        return EXIT_FAILURE;
    }

    // Receive the initial server response
    char buffer[MAX_BUFFER_SIZE];
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Parse the initial server response
    char command[MAX_BUFFER_SIZE];
    char args[MAX_BUFFER_SIZE];
    parse_pop3_response(buffer, command, args);

    // Check if the initial server response is a welcome message
    if (strcmp(command, "+OK") != 0) {
        printf("Error: Unexpected server response: %s", buffer);
        return EXIT_FAILURE;
    }

    // Send the USER command
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server response to the USER command
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Parse the server response to the USER command
    parse_pop3_response(buffer, command, args);

    // Check if the server response to the USER command is a positive response
    if (strcmp(command, "+OK") != 0) {
        printf("Error: Unexpected server response to USER command: %s", buffer);
        return EXIT_FAILURE;
    }

    // Send the PASS command
    sprintf(buffer, "PASS %s\r\n", &username[5]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server response to the PASS command
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Parse the server response to the PASS command
    parse_pop3_response(buffer, command, args);

    // Check if the server response to the PASS command is a positive response
    if (strcmp(command, "+OK") != 0) {
        printf("Error: Unexpected server response to PASS command: %s", buffer);
        return EXIT_FAILURE;
    }

    // Send the STAT command
    strcpy(buffer, "STAT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server response to the STAT command
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Parse the server response to the STAT command
    parse_pop3_response(buffer, command, args);

    // Check if the server response to the STAT command is a positive response
    if (strcmp(command, "+OK") != 0) {
        printf("Error: Unexpected server response to STAT command: %s", buffer);
        return EXIT_FAILURE;
    }

    // Print the number of messages and the total size of the messages
    printf("%s\n", args);

    // Send the LIST command
    strcpy(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server response to the LIST command
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Parse the server response to the LIST command
    parse_pop3_response(buffer, command, args);

    // Check if the server response to the LIST command is a positive response
    if (strcmp(command, "+OK") != 0) {
        printf("Error: Unexpected server response to LIST command: %s", buffer);
        return EXIT_FAILURE;
    }

    // Print the list of messages
    printf("%s\n", args);

    // Send the QUIT command
    strcpy(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server response to the QUIT command
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Parse the server response to the QUIT command
    parse_pop3_response(buffer, command, args);

    // Check if the server response to the QUIT command is a positive response
    if (strcmp(command, "+OK") != 0) {
        printf("Error: Unexpected server response to QUIT command: %s", buffer);
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}
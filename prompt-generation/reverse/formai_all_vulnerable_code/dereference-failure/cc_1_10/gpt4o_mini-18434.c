//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 1024

// Function to send a command to the server and receive a response
void send_command(int sockfd, const char *command, char *response) {
    int n;
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0'; // Null-terminate the response
}

// Function for authentication (LOGIN command)
void authenticate(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // Construct and send the login command
    snprintf(command, sizeof(command), "a1 LOGIN %s %s\r\n", username, password);
    send_command(sockfd, command, response);
    printf("Server response: %s\n", response);
}

// Function to retrieve the list of available mail folders (LIST command)
void list_folders(int sockfd) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // Construct and send the LIST command
    snprintf(command, sizeof(command), "a2 LIST \"\" \"*\"\r\n");
    send_command(sockfd, command, response);
    printf("Server response: %s\n", response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Initiating the connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Specifying server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    
    // Resolving the server address
    if (inet_pton(AF_INET, server, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or address not supported\n");
        exit(EXIT_FAILURE);
    }

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Now is the time to engage with the server!
    printf("Connected to %s:%d\n", server, SERVER_PORT);

    // Authenticating the user
    authenticate(sockfd, username, password);
    
    // Let's see what folders we have in this mailbox
    list_folders(sockfd);

    // Closing the socket
    close(sockfd);
    printf("Connection closed.\n");
    return 0;
}
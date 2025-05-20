//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143

// To store the username and password
char username[256];
char password[256];

// To store the authentication credentials
char auth_credentials[512];

// Function to authenticate with the IMAP server
int authenticate(int sockfd) {
    // Send the AUTHENTICATE command
    char auth_cmd[] = "AUTHENTICATE PLAIN\r\n";
    if (send(sockfd, auth_cmd, strlen(auth_cmd), 0) == -1) {
        perror("send()");
        return -1;
    }

    // Receive the response from the server
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv()");
        return -1;
    }

    // Check if the authentication was successful
    if (strstr(response, "+") == NULL) {
        printf("Authentication failed: %s\n", response);
        return -1;
    }

    // Send the authentication credentials
    sprintf(auth_credentials, "%s\0%s", username, password);
    if (send(sockfd, auth_credentials, strlen(auth_credentials), 0) == -1) {
        perror("send()");
        return -1;
    }

    // Receive the response from the server
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv()");
        return -1;
    }

    // Check if the authentication was successful
    if (strstr(response, "+") == NULL) {
        printf("Authentication failed: %s\n", response);
        return -1;
    }

    return 0;
}

// Function to list the mailboxes on the IMAP server
int list_mailboxes(int sockfd) {
    // Send the LIST command
    char list_cmd[] = "LIST \"\" *\r\n";
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) == -1) {
        perror("send()");
        return -1;
    }

    // Receive the response from the server
    char response[1024];
    while (1) {
        if (recv(sockfd, response, sizeof(response), 0) == -1) {
            perror("recv()");
            return -1;
        }

        // Check if the end of the mailbox list has been reached
        if (strstr(response, "OK") != NULL) {
            break;
        }

        // Display the mailbox name
        char mailbox_name[256];
        sscanf(response, "* LIST (\\Noselect) \"/%s\"", mailbox_name);
        printf("%s\n", mailbox_name);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // Check the command line arguments
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return -1;
    }

    // Get the host and port from the command line arguments
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket()");
        return -1;
    }

    // Connect to the IMAP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect()");
        return -1;
    }

    // Receive the welcome message from the server
    char welcome_msg[1024];
    if (recv(sockfd, welcome_msg, sizeof(welcome_msg), 0) == -1) {
        perror("recv()");
        return -1;
    }
    printf("Welcome message: %s\n", welcome_msg);

    // Prompt the user for their username and password
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Authenticate with the IMAP server
    if (authenticate(sockfd) == -1) {
        return -1;
    }

    // List the mailboxes on the IMAP server
    if (list_mailboxes(sockfd) == -1) {
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}
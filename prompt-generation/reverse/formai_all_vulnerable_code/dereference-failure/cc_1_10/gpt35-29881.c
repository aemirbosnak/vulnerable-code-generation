//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LENGTH 4096

void displayError(const char message[]) {
    perror(message);
    exit(EXIT_FAILURE);
}

void receiveMessage(int sockfd, char buffer[]) {
    int n;
    if ((n = recv(sockfd, buffer, MAX_LENGTH, 0)) < 0) {
        displayError("Error receiving message from server.");
    }
    buffer[n] = '\0';
}

void sendMessage(int sockfd, const char message[]) {
    if (send(sockfd, message, strlen(message), 0) < 0) {
        displayError("Error sending message to server.");
    }
}

void checkOKResponse(char response[]) {
    if (strncmp(response, "+OK", 3) != 0) {
        printf("Error response received: %s", response);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, const char * argv[]) {
    int sockfd = 0;
    char buffer[MAX_LENGTH] = {0};
    char username[MAX_LENGTH] = {0};
    char password[MAX_LENGTH] = {0};
    char popServerAddress[MAX_LENGTH] = {0};
    char message[MAX_LENGTH] = {0};
    char response[MAX_LENGTH] = {0};
    bool authenticated = false;

    printf("Welcome to POP3 client.\n");

    // Retrieve server and login information from the user
    printf("\nEnter the IP address or domain name of the POP server: ");
    scanf("%s", popServerAddress);
    printf("\nEnter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        displayError("Error creating socket.");
    }

    // Connect to the server
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(110);
    if (inet_pton(AF_INET, popServerAddress, &serverAddress.sin_addr) <= 0) {
        displayError("Invalid address/ Address not supported.");
    }
    if (connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        displayError("Connection Failed.");
    }

    // Receive and display POP server banner
    receiveMessage(sockfd, buffer);
    printf("\nServer Banner: %s", buffer);

    // Authenticate the user
    sprintf(message, "USER %s\r\n", username);
    sendMessage(sockfd, message);
    receiveMessage(sockfd, response);
    checkOKResponse(response);

    sprintf(message, "PASS %s\r\n", password);
    sendMessage(sockfd, message);
    receiveMessage(sockfd, response);
    checkOKResponse(response);
    authenticated = true;

    // Retrieve mailbox statistics
    sprintf(message, "STAT\r\n");
    sendMessage(sockfd, message);
    receiveMessage(sockfd, response);
    checkOKResponse(response);
    printf("\nMailbox Statistic: %s", response);

    // Quit POP session
    sprintf(message, "QUIT\r\n");
    sendMessage(sockfd, message);
    receiveMessage(sockfd, response);
    checkOKResponse(response);

    printf("\nPOP3 session terminated successfully.\n");

    close(sockfd);
    exit(EXIT_SUCCESS);
}
//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

// Function declarations
void error(char* message);
void connectToServer(int* sockFd, char* hostname, int portNumber);
void login(int sockFd, char* username, char* password);
void listMailboxes(int sockFd);
void selectMailbox(int sockFd, char* mailboxName);
void fetchEmails(int sockFd, int numEmails);
void quit(int sockFd);

// Main function
int main() {
    int sockFd, portNumber;
    char* hostname = "imap.gmail.com";
    char* username = "<your email>";
    char* password = "<your password>";
    char* mailboxName = "<mailbox name>";
    int numEmails = 5;
    
    portNumber = 993; // IMAP4 SSL port
    
    connectToServer(&sockFd, hostname, portNumber);
    login(sockFd, username, password);
    listMailboxes(sockFd);
    selectMailbox(sockFd, mailboxName);
    fetchEmails(sockFd, numEmails);
    quit(sockFd);
    
    return 0;
}

// Function to handle error
void error(char* message) {
    perror(message);
    exit(1);
}

// Function to connect to the server
void connectToServer(int* sockFd, char* hostname, int portNumber) {
    struct hostent* server;
    struct sockaddr_in serverAddress;

    *sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockFd < 0) {
        error("Error: Failed to create a socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        error("Error: No such host exists");
    }

    bzero((char*) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(portNumber);

    if (connect(*sockFd, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
        error("Error: Failed to connect to the server");
    }
}

// Function to login to the server
void login(int sockFd, char* username, char* password) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Send login command
    sprintf(buffer, ". login %s %s\r\n", username, password);
    send(sockFd, buffer, strlen(buffer), 0);

    // Receive response from server
    recv(sockFd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
}

// Function to list mailboxes
void listMailboxes(int sockFd) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Send list command
    sprintf(buffer, ". list \"\" *\r\n");
    send(sockFd, buffer, strlen(buffer), 0);

    // Receive response from server
    recv(sockFd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
}

// Function to select a mailbox
void selectMailbox(int sockFd, char* mailboxName) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Send select command
    sprintf(buffer, ". select %s\r\n", mailboxName);
    send(sockFd, buffer, strlen(buffer), 0);

    // Receive response from server
    recv(sockFd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
}

// Function to fetch emails
void fetchEmails(int sockFd, int numEmails) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Send fetch command
    sprintf(buffer, ". fetch 1:%d body[header]\r\n", numEmails);
    send(sockFd, buffer, strlen(buffer), 0);

    // Receive response from server
    recv(sockFd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
}

// Function to quit from the server
void quit(int sockFd) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Send logout command
    sprintf(buffer, ". logout\r\n");
    send(sockFd, buffer, strlen(buffer), 0);

    // Receive response from server
    recv(sockFd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    
    // Close socket
    close(sockFd);
}
//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define BUF_SIZE 1024

// Function to establish connection with the IMAP server
int connectToIMAPServer(char* hostname, char* username, char* password) {
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Failed to resolve host.\n");
        return -1;
    }

    // Create a socket
    int socketDesc = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDesc == -1) {
        fprintf(stderr, "Error: Failed to create socket.\n");
        return -1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(993);
    serverAddr.sin_addr.s_addr = * (long *)(host -> h_addr);

    // Connect to the server
    if (connect(socketDesc, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1) {
        fprintf(stderr, "Error: Failed to connect to the server.\n");
        return -1;
    }

    // Receive the server banner
    char buffer[BUF_SIZE];
    memset(buffer, '\0', BUF_SIZE);
    recv(socketDesc, buffer, BUF_SIZE, 0);
    printf("%s", buffer);

    // Enter username
    char command[BUF_SIZE];
    sprintf(command, "tag1 LOGIN %s %s\n", username, password);
    send(socketDesc, command, strlen(command), 0);
    memset(buffer, '\0', BUF_SIZE);
    recv(socketDesc, buffer, BUF_SIZE, 0);

    // Check if login was successful
    if (strncmp(buffer, "tag1 OK", 7) != 0) {
        fprintf(stderr, "Error: Failed to login to the server.\n");
        return -1;
    }

    return socketDesc;
}

// Function to fetch all the emails
void fetchAllEmails(int socketDesc) {
    // Fetch all the email ids
    char command[BUF_SIZE];
    sprintf(command, "tag2 UID SEARCH ALL\n");
    send(socketDesc, command, strlen(command), 0);

    char buffer[BUF_SIZE];
    memset(buffer, '\0', BUF_SIZE);
    recv(socketDesc, buffer, BUF_SIZE, 0);

    // Parse the list of email IDs
    char* start = strstr(buffer, "* SEARCH");
    char* end = strstr(buffer, "tag2 OK");
    *(end - 2) = '\0';
    start += 9;

    printf("Fetching all emails...\n");

    // Loop through all the email IDs and fetch the email
    char* emailId = strtok(start, " ");
    while (emailId != NULL) {
        memset(command, '\0', BUF_SIZE);
        sprintf(command, "tag3 UID FETCH %s BODY[HEADER.FIELDS (FROM TO CC SUBJECT DATE)]\n", emailId);
        send(socketDesc, command, strlen(command), 0);
        memset(buffer, '\0', BUF_SIZE);
        recv(socketDesc, buffer, BUF_SIZE, 0);

        // Parse the email details
        char* emailStart = strstr(buffer, "Date:");
        char* emailEnd = strstr(buffer, "tag3 OK");
        *(emailEnd - 2) = '\0';

        printf("%s", emailStart);
        printf("\n-----------------------------------\n");

        emailId = strtok(NULL, " ");
    }

    printf("Done fetching all emails.\n\n");
}

// Function to logout and close the connection
void logout(int socketDesc) {
    char command[BUF_SIZE];
    sprintf(command, "tag4 LOGOUT\n");
    send(socketDesc, command, strlen(command), 0);
    close(socketDesc);
}

int main() {
    char hostname[BUF_SIZE];
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    char username[BUF_SIZE];
    printf("Enter the username: ");
    scanf("%s", username);

    char password[BUF_SIZE];
    printf("Enter the password: ");
    scanf("%s", password);

    // Connect to the server
    int socketDesc = connectToIMAPServer(hostname, username, password);
    if (socketDesc == -1) {
        exit(1);
    }

    // Fetch all the emails
    fetchAllEmails(socketDesc);

    // Logout and close the connection
    logout(socketDesc);

    return 0;
}
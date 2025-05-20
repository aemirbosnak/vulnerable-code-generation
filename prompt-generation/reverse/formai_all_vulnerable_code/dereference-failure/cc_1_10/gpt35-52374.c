//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

/* Function to check if a string starts with a specific prefix */
int starts_with(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

/* Function to read a line from the server */
char *read_line(int socket) {
    char *buffer = malloc(BUFFER_SIZE * sizeof(char));
    int received = recv(socket, buffer, BUFFER_SIZE, 0);
    buffer[received] = '\0';
    return buffer;
}

/* Function to extract the response code from a server response */
int get_response_code(char *response) {
    char code[4];
    strncpy(code, response, 3);
    code[3] = '\0';
    return atoi(code);
}

/* Main function */
int main() {
    char *hostname = "imap.gmail.com";
    int port = 993;

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to %s:%d\n", hostname, port);

    // Read the welcome message from the server
    char *response = read_line(sock);
    printf("%s", response);

    // Send login command
    char *user = "example@gmail.com";
    char *password = "mypassword";
    char login_command[100];
    memset(login_command, 0, 100);
    sprintf(login_command, "LOGIN %s %s\r\n", user, password);
    send(sock, login_command, strlen(login_command), 0);

    // Read the response and check if the login was successful
    response = read_line(sock);
    int response_code = get_response_code(response);
    if (response_code != 2) {
        printf("Login failed. Error code %d: %s", response_code, response + 4);
        exit(1);
    }

    printf("Login successful!\n");

    // Send list command to get a list of mailboxes
    send(sock, "LIST \"\" *\r\n", 10, 0);

    // Read the response and print the list of mailboxes
    response = read_line(sock);
    while (response != NULL) {
        if (starts_with(response, "* LIST")) {
            char *mailbox = strtok(response + 7, "\"");
            printf("%s\n", mailbox);
        } else if (starts_with(response, "OK")) {
            break;
        }
        response = read_line(sock);
    }

    // Logout
    send(sock, "LOGOUT\r\n", 8, 0);

    // Close the socket
    close(sock);

    return 0;
}
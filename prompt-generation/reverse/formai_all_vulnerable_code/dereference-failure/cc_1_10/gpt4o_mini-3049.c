//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to create a TCP connection
int create_connection(const char *hostname) {
    struct sockaddr_in server_addr;
    int sock;

    // Resolve hostname to IP address
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        error("gethostbyname");
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }

    return sock;
}

// Function to send a command and receive a response
char* send_command(int sock, const char *command) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    // Sending command
    if (send(sock, command, strlen(command), 0) == -1) {
        error("send");
    }

    // Receiving response
    if (recv(sock, buffer, sizeof(buffer) - 1, 0) == -1) {
        error("recv");
    }

    return strdup(buffer);
}

// Main function to demonstrate IMAP client functionality
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];

    // Establish a connection to the IMAP server
    int sock = create_connection(hostname);
    printf("Connected to IMAP server: %s\n", hostname);

    // Send login command (you would need a password to do this correctly)
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s password\r\n", username);
    char *response = send_command(sock, command);
    printf("Response from server: %s\n", response);
    free(response);

    // Send a list command to get mail folders
    snprintf(command, sizeof(command), "A002 LIST \"\" \"*\"\r\n");
    response = send_command(sock, command);
    printf("Response from server: %s\n", response);
    free(response);

    // Send logout command
    snprintf(command, sizeof(command), "A003 LOGOUT\r\n");
    response = send_command(sock, command);
    printf("Response from server: %s\n", response);
    free(response);

    // Closing the socket
    close(sock);
    printf("Disconnected from IMAP server.\n");

    return 0;
}
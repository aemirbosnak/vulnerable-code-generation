//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// IMAP server settings
#define IMAP_PORT 993
#define BUFFER_SIZE 2048

// Function to establish a connection to the IMAP server
int connect_to_imap(const char *server) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sock;

    // Resolve the host name
    host = gethostbyname(server);
    if (host == NULL) {
        perror("Could not resolve host");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    
    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send IMAP command and get the server response
void send_imap_command(int sock, const char *command, char *response) {
    sprintf(response, "");
    send(sock, command, strlen(command), 0);
    send(sock, "\r\n", 2, 0); // CRLF for ending command

    // Receive response
    recv(sock, response, BUFFER_SIZE, 0);
}

// Function to authenticate to the IMAP server
int imap_authenticate(int sock, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    // Send LOGIN command
    send_imap_command(sock, "a001 LOGIN ", response);
    strcat(response, username);
    strcat(response, " ");
    strcat(response, password);

    // Check if login was successful
    printf("Sending LOGIN command...\n");
    send(sock, response, strlen(response), 0);
    send(sock, "\r\n", 2, 0);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Response: %s\n", response);

    if (strstr(response, "OK")) {
        printf("Login successful!\n");
        return 1;
    }
    
    printf("Login failed!\n");
    return 0;
}

// Function to list all mail folders
void list_mail_folders(int sock) {
    char response[BUFFER_SIZE];
    
    // Send LIST command
    send_imap_command(sock, "a002 LIST \"\" \"*\"", response);
    
    printf("Mail folders:\n%s\n", response);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <imap_server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *imap_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Connect to the IMAP server
    int sock = connect_to_imap(imap_server);
    if (sock < 0) {
        fprintf(stderr, "Failed to connect to IMAP server.\n");
        return EXIT_FAILURE;
    }

    char response[BUFFER_SIZE];

    // Authenticate user
    if (!imap_authenticate(sock, username, password)) {
        close(sock);
        return EXIT_FAILURE;
    }

    // List mail folders
    list_mail_folders(sock);

    // Close the socket
    close(sock);
    return EXIT_SUCCESS;
}
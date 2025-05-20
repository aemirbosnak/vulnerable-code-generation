//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 16384

int main(int argc, char *argv[]) {
    // Define variables
    int sock = -1, bytes_received;
    struct hostent *host_info = NULL;
    struct sockaddr_in server_info = {0};
    char command[MAX_COMMAND_LENGTH] = {0};
    char response[MAX_RESPONSE_LENGTH] = {0};
    char buffer[BUFFER_SIZE] = {0};

    // Check for correct arguments
    if(argc < 4) {
        printf("Usage: %s servername port username password\n", argv[0]);
        return 0;
    }

    // Retrieve server information
    host_info = gethostbyname(argv[1]);
    if(host_info == NULL) {
        printf("Invalid server name.\n");
        return 0;
    }

    // Set up server information
    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(atoi(argv[2]));
    memcpy(&server_info.sin_addr, host_info->h_addr, host_info->h_length);

    // Open socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        printf("Failed to open socket.\n");
        return 0;
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_info, sizeof(server_info)) < 0) {
        printf("Failed to connect to server.\n");
        return 0;
    }

    // Receive server greeting
    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if(bytes_received < 0) {
        printf("Failed to receive response from server.\n");
        return 0;
    }
    buffer[bytes_received] = 0;
    printf("%s", buffer);

    // Log in to server
    sprintf(command, "LOGIN %s %s\n", argv[3], argv[4]);
    send(sock, command, strlen(command), 0);

    // Receive server response
    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if(bytes_received < 0) {
        printf("Failed to receive response from server.\n");
        return 0;
    }
    buffer[bytes_received] = 0;
    printf("%s", buffer);

    // Prompt user for command input
    while(1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin); // Get user input
        command[strlen(command) - 1] = 0; // Remove newline

        // Send command to server
        send(sock, command, strlen(command), 0);

        // Receive server response
        bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if(bytes_received < 0) {
            printf("Failed to receive response from server.\n");
            return 0;
        }
        buffer[bytes_received] = 0;
        printf("%s", buffer);
    }

    // Close socket
    close(sock);
    return 0;
}
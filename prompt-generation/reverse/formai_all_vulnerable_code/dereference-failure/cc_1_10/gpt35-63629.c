//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to validate command syntax
int validate_syntax(char command[]) {
    char* cmd = strtok(command, " \n");
    if (strcmp(cmd, "ftp") != 0) {
        printf("Invalid command: ftp command not found.\n");
        return 0;
    }
    char* subcmd = strtok(NULL, " \n");
    if (subcmd == NULL) {
        printf("Invalid command: subcommand not found.\n");
        return 0;
    }
    if (strcmp(subcmd, "get") != 0 && strcmp(subcmd, "put") != 0) {
        printf("Invalid subcommand: get or put expected.\n");
        return 0;
    }
    char* filename = strtok(NULL, " \n");
    if (filename == NULL) {
        printf("Invalid command: file not specified.\n");
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ftpclient <ip_address> <port>\n");
        return 1;
    }

    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    // Set server details
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server.\n");
        return 1;
    }

    // Greet user
    printf("FTP client connected to %s on port %s.\n", argv[1], argv[2]);
    printf("Enter 'ftp get <filename>' to download a file.\n");
    printf("Enter 'ftp put <filename>' to upload a file.\n");
    printf("Enter 'exit' to quit.\n");

    // Loop to accept user commands
    while (1) {
        // Get command from user
        printf("ftp> ");
        fgets(command, BUFFER_SIZE, stdin);

        // Remove newline from command
        command[strcspn(command, "\n")] = 0;

        // Check for exit command
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Validate syntax of command
        if (validate_syntax(command) == 0) {
            continue;
        }

        // Send command to server
        write(sockfd, command, strlen(command));

        // Get response from server
        memset(response, 0, BUFFER_SIZE);
        read(sockfd, response, BUFFER_SIZE);

        // Handle response
        printf("%s", response);
    }

    // Close socket
    close(sockfd);

    printf("FTP client disconnected.\n");
    return 0;
}
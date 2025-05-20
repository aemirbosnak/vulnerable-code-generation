//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the IP address and port number from the command line arguments
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Create a socket for communicating with the FTP server
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message from the FTP server
    char welcome_msg[MAX_DATA_SIZE];
    memset(welcome_msg, 0, MAX_DATA_SIZE);
    int bytes_received = recv(socket_fd, welcome_msg, MAX_DATA_SIZE - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", welcome_msg);

    // Enter the FTP command loop
    while (1) {
        // Prompt the user for a command
        printf("Enter an FTP command: ");
        char command[MAX_DATA_SIZE];
        memset(command, 0, MAX_DATA_SIZE);
        fgets(command, MAX_DATA_SIZE - 1, stdin);

        // Remove the newline character from the command
        command[strcspn(command, "\n")] = '\0';

        // Check if the user entered the EXIT command
        if (strcmp(command, "EXIT") == 0) {
            break;
        }

        // Send the command to the FTP server
        if (send(socket_fd, command, strlen(command), 0) == -1) {
            perror("send");
            return EXIT_FAILURE;
        }

        // Receive the response from the FTP server
        char response[MAX_DATA_SIZE];
        memset(response, 0, MAX_DATA_SIZE);
        bytes_received = recv(socket_fd, response, MAX_DATA_SIZE - 1, 0);
        if (bytes_received == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }

        // Print the response to the user
        printf("%s", response);
    }

    // Close the socket
    close(socket_fd);

    return EXIT_SUCCESS;
}
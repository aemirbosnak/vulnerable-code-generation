//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 100

int main(int argc, char *argv[]) {
    int data_socket;
    int command_socket;
    char buffer[BUFFER_SIZE];
    char command[MAX_COMMAND_LENGTH];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char server_address[BUFFER_SIZE];
    char file_path[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s server_address\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strcpy(server_address, argv[1]);

    // Create data socket
    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating data socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    server_addr.sin_port = htons(21);
    if (connect(data_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server\n");

    // Recive server response
    memset(&buffer, 0, sizeof(buffer));
    read(data_socket, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    // Send username
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n"); // remove new line from username
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    write(data_socket, buffer, strlen(buffer));

    // Recive server response
    memset(&buffer, 0, sizeof(buffer));
    read(data_socket, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    // Send password
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n"); // remove new line from password
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    write(data_socket, buffer, strlen(buffer));

    // Recive server response
    memset(&buffer, 0, sizeof(buffer));
    read(data_socket, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    // Listen for commands
    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        strtok(command, "\n"); // remove new line from command

        // Send command
        snprintf(buffer, sizeof(buffer), "%s\r\n", command);
        write(data_socket, buffer, strlen(buffer));

        // Handle command
        memset(&response, 0, sizeof(response));
        read(data_socket, response, sizeof(response));
        printf("%s", response);

        if (strncmp(command, "QUIT", 4) == 0) {
            break;
        }
    }

    printf("Disconnected from server\n");
    close(data_socket);
    exit(EXIT_SUCCESS);
}
//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char command[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: ./ftp_client hostname port_number\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Fill in server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Loop to prompt for commands and execute them
    while (1) {
        // Prompt for command
        printf("ftp_client> ");
        fgets(command, BUFFER_SIZE, stdin);

        // Remove newline character from command
        strtok(command, "\n");

        // Handle the command
        if (strcmp(command, "ls") == 0) {
            // Send ls command to server
            send(client_socket, command, strlen(command), 0);

            // Receive and print server response
            memset(buffer, 0, sizeof(buffer));
            recv(client_socket, buffer, sizeof(buffer), 0);
            printf("%s\n", buffer);
        } else if (strcmp(command, "get") == 0) {
            // Prompt for filename
            printf("Filename: ");
            fgets(filename, BUFFER_SIZE, stdin);

            // Remove newline character from filename
            strtok(filename, "\n");

            // Send get command and filename to server
            sprintf(buffer, "%s %s", command, filename);
            send(client_socket, buffer, strlen(buffer), 0);

            // Receive and save file from server
            FILE *file = fopen(filename, "wb");
            int bytes_received = 0;

            while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
                fwrite(buffer, 1, bytes_received, file);
            }

            fclose(file);
            printf("File received successfully\n");
        } else if (strcmp(command, "quit") == 0) {
            // Send quit command to server and exit loop
            send(client_socket, command, strlen(command), 0);
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    // Close socket
    close(client_socket);

    return 0;
}
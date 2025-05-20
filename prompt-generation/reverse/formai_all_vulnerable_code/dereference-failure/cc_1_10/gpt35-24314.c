//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket for connecting to the server
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get the server details using gethostbyname and fill in the server address structure
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send the username to the server
    printf("Enter username: ");
    char username[MAX_SIZE];
    scanf("%s", username);
    int username_len = strlen(username);
    send(client_socket, username, username_len, 0);

    // Receive the response from the server
    char response[MAX_SIZE];
    recv(client_socket, response, MAX_SIZE, 0);
    printf("%s", response);

    // Send the password to the server
    printf("Enter password: ");
    char password[MAX_SIZE];
    scanf("%s", password);
    int password_len = strlen(password);
    send(client_socket, password, password_len, 0);

    // Receive the response from the server
    recv(client_socket, response, MAX_SIZE, 0);
    printf("%s", response);

    // Enter the FTP client loop
    while (1) {
        // Prompt the user to enter the command
        printf("ftp> ");
        char command[MAX_SIZE];
        fgets(command, MAX_SIZE, stdin);

        // Strip the newline character from the command
        command[strcspn(command, "\n")] = 0;

        // Send the command to the server
        int command_len = strlen(command);
        send(client_socket, command, command_len, 0);

        // Receive the response from the server
        recv(client_socket, response, MAX_SIZE, 0);
        printf("%s", response);

        // Exit the loop if the command is quit
        if (strcmp(command, "quit") == 0) {
            break;
        }
    }

    // Close the client socket
    close(client_socket);

    return 0;
}
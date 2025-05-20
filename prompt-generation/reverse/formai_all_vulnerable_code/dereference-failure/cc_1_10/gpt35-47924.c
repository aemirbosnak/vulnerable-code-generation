//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LEN 256
#define BUFFER_SIZE 1024
#define MAX_TOKENS 4

// Function prototypes
void get_user_input(char *buffer, size_t buffer_size);
void parse_user_input(char *buffer, char **tokens, int *num_tokens);
void ftp_client(char *server_ip, int server_port);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    ftp_client(server_ip, server_port);

    return 0;
}

void get_user_input(char *buffer, size_t buffer_size) {
    printf("> ");
    fgets(buffer, buffer_size, stdin);

    // Remove newline character from the end of the string
    buffer[strcspn(buffer, "\n")] = 0;
}

void parse_user_input(char *buffer, char **tokens, int *num_tokens) {
    char *delimiter = " ";
    char *ptr = strtok(buffer, delimiter);
    int i = 0;

    while (ptr != NULL) {
        tokens[i] = ptr;
        i++;

        if (i >= MAX_TOKENS) {
            break;
        }

        ptr = strtok(NULL, delimiter);
    }

    *num_tokens = i;
}

void ftp_client(char *server_ip, int server_port) {
    // Create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // Specify the address of the server that the client wants to connect to
    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        perror("Error converting server IP address");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from the server
    char welcome_message[BUFFER_SIZE] = {0};
    if (recv(client_socket, welcome_message, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", welcome_message);

    // Main loop for user input and processing FTP commands
    char command[MAX_COMMAND_LEN];
    char *tokens[MAX_TOKENS];
    int num_tokens;

    while (1) {
        get_user_input(command, MAX_COMMAND_LEN);
        parse_user_input(command, tokens, &num_tokens);

        if (strcmp(tokens[0], "quit") == 0) {
            break;
        } else if (strcmp(tokens[0], "ls") == 0) {
            // Send LIST command to the server
            if (send(client_socket, "LIST", strlen("LIST"), 0) < 0) {
                perror("Error sending command to server");
                continue;
            }

            // Receive directory listing from the server
            char directory_listing[BUFFER_SIZE] = {0};
            if (recv(client_socket, directory_listing, BUFFER_SIZE, 0) < 0) {
                perror("Error receiving directory listing from server");
                continue;
            }

            printf("%s\n", directory_listing);
        } else if (strcmp(tokens[0], "get") == 0) {
            if (num_tokens != 2) {
                printf("Usage: get <filename>\n");
                continue;
            }

            // Send RETR command to the server
            if (send(client_socket, command, strlen(command), 0) < 0) {
                perror("Error sending command to server");
                continue;
            }

            // Receive file data from the server
            FILE *file = fopen(tokens[1], "wb");
            if (file == NULL) {
                printf("Error opening file for writing\n");
                continue;
            }

            char file_buffer[BUFFER_SIZE];
            int num_bytes_read;

            while ((num_bytes_read = recv(client_socket, file_buffer, BUFFER_SIZE, 0)) > 0) {
                fwrite(file_buffer, sizeof(char), num_bytes_read, file);
            }

            fclose(file);

        } else if (strcmp(tokens[0], "put") == 0) {
            if (num_tokens != 2) {
                printf("Usage: put <filename>\n");
                continue;
            }

            // Send STOR command to the server
            if (send(client_socket, command, strlen(command), 0) < 0) {
                perror("Error sending command to server");
                continue;
            }

            // Send file data to the server
            FILE *file = fopen(tokens[1], "rb");
            if (file == NULL) {
                printf("Error opening file for reading\n");
                continue;
            }

            char file_buffer[BUFFER_SIZE];
            int num_bytes_read;

            while ((num_bytes_read = fread(file_buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
                if (send(client_socket, file_buffer, num_bytes_read, 0) < 0) {
                    perror("Error sending file data to server");
                    break;
                }
            }

            fclose(file);
        } else {
            printf("Invalid command\n");
        }
    }

    // Close the client socket
    close(client_socket);
}
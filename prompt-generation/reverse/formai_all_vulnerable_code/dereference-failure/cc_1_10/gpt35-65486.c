//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define MAX_COMMAND 128

/* Function prototypes */
int connect_to_server(const char *server_address, int port);
void send_command(int sock, const char *command);
int receive_response(int sock, char *response_buffer, size_t buffer_size);
void logout(int sock);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int port = atoi(argv[2]);
    int sock = connect_to_server(argv[1], port);
    char response_buffer[MAX_BUFFER] = {0};
    char command_buffer[MAX_COMMAND] = {0};
    
    // Login prompt
    printf("Welcome to the IMAP client!\n\n");
    printf("Please enter your login credentials:\n");
    printf("Username: ");
    fgets(command_buffer, MAX_COMMAND, stdin);
    printf("Password: ");
    fgets(command_buffer, MAX_COMMAND, stdin);
    send_command(sock, "LOGIN");
    send_command(sock, command_buffer);
    
    // Main loop
    printf("Connected to server. Enter commands below.\n");
    while (1) {
        printf("> ");
        fgets(command_buffer, MAX_COMMAND, stdin);
        send_command(sock, command_buffer);
        int bytes_received = receive_response(sock, response_buffer, MAX_BUFFER);
        if (bytes_received > 0) {
            response_buffer[bytes_received] = '\0';
            printf("%s", response_buffer);
        }
        if (strncmp(command_buffer, "LOGOUT", 6) == 0) {
            logout(sock);
            break;
        }
    }

    printf("Client disconnected.\n");
    close(sock);
    return EXIT_SUCCESS;
}

/**
 * Connects to the specified server and port using a TCP socket.
 *
 * @param server_address The server address to connect to.
 * @param port The port number to connect to.
 * @return The resulting socket file descriptor.
 */
int connect_to_server(const char *server_address, int port) {
    int sock = 0;
    struct sockaddr_in server_sockaddr;
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_address, &server_sockaddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    
    if (connect(sock, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    
    return sock;
}

/**
 * Sends the specified command string to the server over the specified socket.
 *
 * @param sock The socket file descriptor to send the command on.
 * @param command The command to send.
 */
void send_command(int sock, const char *command) {
    char buffer[MAX_COMMAND + 3] = {0};
    sprintf(buffer, "%s\r\n", command);
    send(sock, buffer, strlen(buffer), 0);
}

/**
 * Receives and stores the server's response in the specified buffer, up to the given buffer size.
 *
 * @param sock The socket file descriptor to receive the response from.
 * @param response_buffer The buffer to store the response in.
 * @param buffer_size The size of the response buffer.
 * @return The number of bytes received.
 */
int receive_response(int sock, char *response_buffer, size_t buffer_size) {
    int bytes_received = 0;
    char ch = 0;
    do {
        recv(sock, &ch, 1, 0);
        response_buffer[bytes_received++] = ch;
    } while (ch != '\n' && bytes_received < buffer_size - 1);
    return bytes_received;
}

/**
 * Sends a logout command to the server and closes the specified socket file descriptor.
 *
 * @param sock The socket file descriptor to close.
 */
void logout(int sock) {
    send_command(sock, "LOGOUT");
    close(sock);
}
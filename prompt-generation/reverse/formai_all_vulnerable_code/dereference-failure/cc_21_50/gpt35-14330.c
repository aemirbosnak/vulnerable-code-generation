//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: ./pop3client [hostname] [port] [username]\n");
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    // Create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Get server information using gethostbyname
    struct hostent* server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Could not find host %s\n", hostname);
        exit(1);
    }

    // Set up the client address struct and connect to server
    struct sockaddr_in client_addr = {0};
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);
    client_addr.sin_addr = *((struct in_addr*)server->h_addr);

    if (connect(client_socket, (struct sockaddr*)&client_addr, sizeof(client_addr)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server %s:%d\n", hostname, port);

    // Receive greeting message
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving greeting message");
    }
    else {
        printf("Server greeting: %s", buffer);
    }

    // Send username to server
    char username_buffer[BUFFER_SIZE];
    snprintf(username_buffer, BUFFER_SIZE, "USER %s\n", username);
    ssize_t bytes_sent = send(client_socket, username_buffer, strlen(username_buffer), 0);
    if (bytes_sent == -1) {
        perror("Error sending username");
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response");
    }
    else {
        printf("Server response: %s", buffer);
    }

    // Prompt for password and send to server
    char password_buffer[BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password_buffer, BUFFER_SIZE, stdin);
    printf("\n");

    char *newline_ptr = strchr(password_buffer, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    char password_command[BUFFER_SIZE];
    snprintf(password_command, BUFFER_SIZE, "PASS %s\n", password_buffer);
    bytes_sent = send(client_socket, password_command, strlen(password_command), 0);
    if (bytes_sent == -1) {
        perror("Error sending password");
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response");
    }
    else {
        printf("Server response: %s", buffer);
    }

    // Send STAT command to server
    char stat_command[] = "STAT\n";
    bytes_sent = send(client_socket, stat_command, strlen(stat_command), 0);
    if (bytes_sent == -1) {
        perror("Error sending STAT command");
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response");
    }
    else {
        printf("Server response: %s", buffer);
    }

    // Extract number of messages and total size from STAT response
    int num_messages, total_size;
    char *token = strtok(buffer, " ");
    token = strtok(NULL, " ");
    num_messages = atoi(token);
    token = strtok(NULL, " ");
    total_size = atoi(token);

    printf("You have %d messages with a total size of %d bytes\n", num_messages, total_size);

    // Send LIST command to server
    char list_command[] = "LIST\n";
    bytes_sent = send(client_socket, list_command, strlen(list_command), 0);
    if (bytes_sent == -1) {
        perror("Error sending LIST command");
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response");
    }
    else {
        printf("Server response: %s", buffer);
    }

    // Extract message sizes from LIST response
    char *size_token;
    int message_num = 0;
    while ((token = strtok_r(buffer, "\r\n", &buffer)) != NULL) {
        if (message_num == 0) {
            // Skip first line of response
            message_num++;
            continue;
        }
        size_token = strtok(token, " ");
        printf("Message %d size: %s bytes\n", message_num++, size_token);
    }

    // Prompt for message number
    char message_num_buffer[BUFFER_SIZE];
    printf("Enter message number to read: ");
    fgets(message_num_buffer, BUFFER_SIZE, stdin);
    printf("\n");

    int requested_message_num = atoi(message_num_buffer);

    // Send RETR command to server
    char retr_command[BUFFER_SIZE];
    snprintf(retr_command, BUFFER_SIZE, "RETR %d\n", requested_message_num);
    bytes_sent = send(client_socket, retr_command, strlen(retr_command), 0);
    if (bytes_sent == -1) {
        perror("Error sending RETR command");
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response");
    }
    else {
        printf("Server response: %s", buffer);
    }

    // Check if requested message exists
    if (strstr(buffer, "+OK") == NULL) {
        printf("Requested message number does not exist\n");
        exit(1);
    }

    printf("Message content:\n");

    // Receive message content from server
    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, stdout);
        if (buffer[bytes_received-1] == '\n') {
            break;
        }
        memset(buffer, 0, BUFFER_SIZE);        
    }

    // Send QUIT command to server
    char quit_command[] = "QUIT\n";
    bytes_sent = send(client_socket, quit_command, strlen(quit_command), 0);
    if (bytes_sent == -1) {
        perror("Error sending QUIT command");
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response");
    }
    else {
        printf("Server response: %s", buffer);
    }

    printf("Closing connection...\n");

    close(client_socket);

    return 0;
}
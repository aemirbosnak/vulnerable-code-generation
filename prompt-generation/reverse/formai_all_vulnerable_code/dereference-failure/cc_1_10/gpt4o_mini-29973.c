//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to read server response
void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    if (received < 0) {
        error("Error reading from socket");
    }
    buffer[received] = '\0'; // Null-terminate the string
    printf("Server: %s", buffer);
}

// Function to send command and read response
void send_command(int socket, const char *command) {
    printf("Client: %s\n", command);
    if (send(socket, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
    read_response(socket);
}

// Function to connect to the POP3 server
int connect_to_pop3(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host_entry;

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Error creating socket");
    }

    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        error("Error resolving hostname");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host_entry->h_addr, host_entry->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    read_response(socket_fd); // Read server greeting
    return socket_fd;
}

// Function to authenticate to the POP3 server
void authenticate(int socket_fd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(socket_fd, command);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(socket_fd, command);
}

// Function to list messages in the inbox
void list_messages(int socket_fd) {
    send_command(socket_fd, "LIST\r\n");
}

// Function to retrieve a specific message by its number
void retrieve_message(int socket_fd, int message_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", message_number);
    send_command(socket_fd, command);
}

// Function to quit the POP3 session
void quit_session(int socket_fd) {
    send_command(socket_fd, "QUIT\r\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int socket_fd = connect_to_pop3(hostname);
    
    authenticate(socket_fd, username, password);
    
    list_messages(socket_fd);

    int message_number;
    printf("Enter message number to retrieve (0 to quit): ");
    scanf("%d", &message_number);
    
    if (message_number > 0) {
        retrieve_message(socket_fd, message_number);
    }

    quit_session(socket_fd);

    close(socket_fd);
    return 0;
}
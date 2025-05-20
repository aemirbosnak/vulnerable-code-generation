//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 110 // Typically used for POP3
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int socket, const char *command) {
    if (send(socket, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the buffer
    printf("%s", buffer);
}

int main() {
    int socket_desc;
    struct sockaddr_in server;
    struct hostent *host;

    // Get host information
    host = gethostbyname("pop.example.com"); // Replace with actual POP3 server
    if (host == NULL) {
        error("Could not find host");
    }

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        error("Could not create socket");
    }

    // Setup server address structure
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    memcpy(&server.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    // Connect to the server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }
    printf("Connected to POP3 server\n");

    // Receive greeting from the server
    receive_response(socket_desc);

    // Log in to the server
    char username[] = "your_username"; // Replace with actual username
    char password[] = "your_password"; // Replace with actual password
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(socket_desc, command);
    receive_response(socket_desc);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(socket_desc, command);
    receive_response(socket_desc);

    // List messages
    send_command(socket_desc, "LIST\r\n");
    receive_response(socket_desc);

    // Fetch individual message
    snprintf(command, sizeof(command), "RETR 1\r\n"); // Replace '1' with the message number
    send_command(socket_desc, command);
    receive_response(socket_desc);

    // Quit session
    send_command(socket_desc, "QUIT\r\n");
    receive_response(socket_desc);

    // Close socket
    close(socket_desc);
    printf("Disconnected from server\n");

    return 0;
}
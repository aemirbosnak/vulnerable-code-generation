//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int socket_fd, const char *cmd) {
    write(socket_fd, cmd, strlen(cmd));
    write(socket_fd, "\r\n", 2);
}

void read_response(int socket_fd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    bytes_received = read(socket_fd, buffer, sizeof(buffer) - 1);
    if (bytes_received < 0) {
        error("Error reading response");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct sockaddr_in server_address;
    int socket_fd;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Error opening socket");
    }

    // Setup server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(POP3_PORT);
    server_address.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the POP3 server
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Unable to connect to server");
    }

    // Read server response
    read_response(socket_fd);

    // AUTHENTICATE
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "USER %s", username);
    send_command(socket_fd, cmd);
    read_response(socket_fd);

    snprintf(cmd, sizeof(cmd), "PASS %s", password);
    send_command(socket_fd, cmd);
    read_response(socket_fd);

    // LIST messages
    send_command(socket_fd, "LIST");
    read_response(socket_fd);

    // Retrieve the first message
    send_command(socket_fd, "RETR 1");
    read_response(socket_fd);

    // Log out
    send_command(socket_fd, "QUIT");
    read_response(socket_fd);

    // Close the socket
    close(socket_fd);
    
    return 0;
}
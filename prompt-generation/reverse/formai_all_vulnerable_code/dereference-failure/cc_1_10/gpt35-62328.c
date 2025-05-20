//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char *hostname = "mail.example.com";

    // Creating socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        error("Could not create socket");
    }

    // Server details
    server.sin_addr.s_addr = inet_addr(hostname);
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    // Connecting to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }
    printf("Connected to server\n");

    // Initialize input buffer and get server response
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_desc, buffer, sizeof(buffer), 0) < 0) {
        error("Error receiving server response");
    }

    // Send user command for authentication
    char user_command[256];
    sprintf(user_command, "USER %s\r\n", "yourmail@example.com");
    if (send(socket_desc, user_command, strlen(user_command), 0) < 0) {
        error("Error sending user command");
    }

    // Get server response to user command
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_desc, buffer, sizeof(buffer), 0) < 0) {
        error("Error receiving server response");
    }
    printf("%s\n", buffer);

    // Send password command for authentication
    char pass_command[256];
    sprintf(pass_command, "PASS %s\r\n", "examplepassword");
    if (send(socket_desc, pass_command, strlen(pass_command), 0) < 0) {
        error("Error sending password command");
    }

    // Get server response to password command
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_desc, buffer, sizeof(buffer), 0) < 0) {
        error("Error receiving server response");
    }
    printf("%s\n", buffer);

    // Send quit command to close connection
    char quit_command[256];
    sprintf(quit_command, "QUIT\r\n");
    if (send(socket_desc, quit_command, strlen(quit_command), 0) < 0) {
        error("Error sending quit command");
    }

    // Get server response to quit command
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_desc, buffer, sizeof(buffer), 0) < 0) {
        error("Error receiving server response");
    }
    printf("%s\n", buffer);

    // Close connection
    close(socket_desc);
    return 0;
}
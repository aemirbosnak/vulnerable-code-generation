//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void handle_socket_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *command) {
    write(sock, command, strlen(command));
    write(sock, "\r\n", 2);
}

void receive_response(int sock, char *buffer) {
    read(sock, buffer, BUFFER_SIZE);
}

void pop3_client(const char *server, const char *username, const char *password) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_socket_error("Error creating socket");
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connect to POP3 server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_socket_error("Connection failed");
    }

    // Receive server greeting
    receive_response(sock, buffer);
    printf("Server: %s", buffer);

    // Send USER command
    char user_command[BUFFER_SIZE];
    sprintf(user_command, "USER %s", username);
    send_command(sock, user_command);
    receive_response(sock, buffer);
    printf("Server: %s", buffer);

    // Send PASS command
    char pass_command[BUFFER_SIZE];
    sprintf(pass_command, "PASS %s", password);
    send_command(sock, pass_command);
    receive_response(sock, buffer);
    printf("Server: %s", buffer);

    // Send STAT command to get number of messages
    send_command(sock, "STAT");
    receive_response(sock, buffer);
    printf("Server: %s", buffer);

    // Send LIST command to list messages
    send_command(sock, "LIST");
    receive_response(sock, buffer);
    printf("Server: %s", buffer);

    // Send RETR command to retrieve the first message (assuming at least one message exists)
    send_command(sock, "RETR 1");
    receive_response(sock, buffer);
    printf("Message: \n%s\n", buffer);

    // Send QUIT command to exit
    send_command(sock, "QUIT");
    receive_response(sock, buffer);
    printf("Server: %s", buffer);

    // Close socket
    close(sock);
}

int main() {
    const char *server = "127.0.0.1";  // Replace with your POP3 server
    const char *username = "your-email@example.com";  // Your email
    const char *password = "yourpassword";  // Your password

    pop3_client(server, username, password);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define POP3_SERVER "pop.yourserver.com" // Replace with your POP3 server
#define POP3_PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *command) {
    if (send(sock, command, strlen(command), 0) < 0) {
        handle_error("send_command: send failed");
    }
}

void receive_response(int sock, char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE - 1, 0) < 0) {
        handle_error("receive_response: receive failed");
    }
}

void pop3_authenticate(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sock, command);
    receive_response(sock, response);
    printf("Server response to USER: %s", response);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sock, command);
    receive_response(sock, response);
    printf("Server response to PASS: %s", response);
}

void pop3_list_messages(int sock) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    send_command(sock, "LIST\r\n");
    receive_response(sock, response);
    printf("Server response to LIST: %s", response);
}

void pop3_retrieve_message(int sock, int message_number) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d\r\n", message_number);
    send_command(sock, command);
    receive_response(sock, response);
    printf("Server response to RETR %d: %s", message_number, response);
}

void pop3_quit(int sock) {
    char command[] = "QUIT\r\n";
    send_command(sock, command);
    char response[BUFFER_SIZE];
    receive_response(sock, response);
    printf("Server response to QUIT: %s", response);
}

int main() {
    const char *username = "your_username"; // Replace with your username
    const char *password = "your_password"; // Replace with your password

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("socket: creation failed");
    }

    struct hostent *server = gethostbyname(POP3_SERVER);
    if (server == NULL) {
        handle_error("gethostbyname: failed to resolve server");
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    server_address.sin_port = htons(POP3_PORT);

    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        handle_error("connect: connection failed");
    }

    char response[BUFFER_SIZE];
    receive_response(sock, response);
    printf("Server response: %s", response);
  
    pop3_authenticate(sock, username, password);
    pop3_list_messages(sock);
  
    // Assuming you want to retrieve the first message
    pop3_retrieve_message(sock, 1);
  
    pop3_quit(sock);
    close(sock);

    return 0;
}
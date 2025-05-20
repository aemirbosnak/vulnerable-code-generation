//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 2048

void send_command(int s, char* command) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", command);
    send(s, buffer, strlen(buffer), 0);
}

void read_response(int s) {
    char buffer[BUFFER_SIZE];
    int received = 0;
    while((received = recv(s, buffer, BUFFER_SIZE, 0)) != 0) {
        printf("%.*s", received, buffer);
        if(strstr(buffer, "\r\n") != NULL) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    char* server_address = "imap.example.com";
    int server_port = 143;

    // Parse command line arguments
    if(argc > 1) {
        server_address = argv[1];
    }
    if(argc > 2) {
        server_port = atoi(argv[2]);
    }

    // Connect to server
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    server_addr.sin_port = htons(server_port);
    if(connect(s, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Read welcome message
    read_response(s);

    // Send login details
    send_command(s, "LOGIN user@example.com password");

    // Read response
    read_response(s);

    // Select mailbox
    send_command(s, "SELECT INBOX");

    // Read response
    read_response(s);

    // Search for messages
    send_command(s, "SEARCH UNSEEN");

    // Read response
    printf("\n-----MESSAGES-----\n");
    read_response(s);
    printf("-------------------\n");

    // Logout and close connection
    send_command(s, "LOGOUT");
    read_response(s);
    close(s);

    return 0;
}
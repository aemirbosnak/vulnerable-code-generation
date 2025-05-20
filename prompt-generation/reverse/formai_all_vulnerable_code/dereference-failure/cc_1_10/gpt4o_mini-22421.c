//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110 // Standard POP3 port
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to connect to the POP3 server
int connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0)
        error("ERROR invalid address");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    return sockfd;
}

// Function to read server response
void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);
}

// Function to send a command to the server
void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    printf(">>> %s", command); // Displaying sent command
    read_response(sockfd);
}

// Function to authenticate with the server
void authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
}

// Function to list messages in the inbox
void list_messages(int sockfd) {
    send_command(sockfd, "LIST\r\n");
}

// Function to retrieve a specific message
void retrieve_message(int sockfd, const char *msg_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", msg_number);
    send_command(sockfd, command);
}

// Function to quit the session
void quit_session(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_server(hostname);
    read_response(sockfd); // Read server greeting

    authenticate(sockfd, username, password); // Authenticate

    list_messages(sockfd); // List all messages

    // Optionally retrieve a specific message, e.g., the first message
    retrieve_message(sockfd, "1"); // Retrieve the first message

    quit_session(sockfd); // Quit the session

    return 0;
}
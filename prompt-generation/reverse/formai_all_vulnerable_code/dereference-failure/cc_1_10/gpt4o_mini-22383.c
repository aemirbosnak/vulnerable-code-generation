//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *command) {
    if (send(socket, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    // Receive response from the server
    int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }
    
    // Print the response from the server
    printf("Server: %s\n", buffer);
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;

    // Set up the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    
    // Resolve the hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        close(sockfd);
        error("Error resolving hostname");
    }
    
    // Prepare the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        error("Error connecting to server");
    }

    return sockfd;
}

void login(int socket, const char *username, const char *password) {
    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "A01 LOGIN %s %s\r\n", username, password);
    
    send_command(socket, login_command);
    receive_response(socket);
}

void list_emails(int socket) {
    send_command(socket, "A02 LIST \"\" \"*\"\r\n");
    receive_response(socket);
}

void fetch_email(int socket, const char *email_id) {
    char fetch_command[BUFFER_SIZE];
    snprintf(fetch_command, sizeof(fetch_command), "A03 FETCH %s BODY[]\r\n", email_id);
    
    send_command(socket, fetch_command);
    receive_response(socket);
}

void logout(int socket) {
    send_command(socket, "A04 LOGOUT\r\n");
    receive_response(socket);
    close(socket);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Connect to the IMAP server
    int socket = connect_to_server(hostname);
    printf("Connected to %s\n", hostname);
    
    // Log in
    login(socket, username, password);
    
    // List emails
    list_emails(socket);
    
    // Optionally fetch a specific email (this would require an email ID)
    // For example, let's fetch the first email
    fetch_email(socket, "1");
    
    // Log out
    logout(socket);
    
    return EXIT_SUCCESS;
}
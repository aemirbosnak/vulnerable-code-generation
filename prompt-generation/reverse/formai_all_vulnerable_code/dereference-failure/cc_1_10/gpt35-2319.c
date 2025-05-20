//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX 1024
#define PORT 25

void send_command(int sock, char* cmd, char* response);
void get_hostname(char *hostname);
void error(char *msg);

int main() {
    
    int sock;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char hostname[MAX];
    char buffer[MAX];
    char response[MAX];
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR: Could not create socket.");
    }
    printf("Socket created successfully.\n");
    
    // Get hostname and server information
    get_hostname(hostname);
    server = gethostbyname(hostname);
    if (server == NULL) {
        error("ERROR: Could not get server information.");
    }
    printf("Server information obtained successfully.\n");
    
    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr = *((struct in_addr*)server->h_addr);
    
    // Connect to the server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR: Could not connect to server.");
    }
    printf("Connection established successfully.\n");
    
    // Get server response
    memset(response, 0, sizeof(response));
    recv(sock, response, MAX, 0);
    printf("%s", response);
    
    // Send HELO command
    send_command(sock, "HELO localhost\r\n", response);
    printf("%s", response);
    
    // Send MAIL FROM command
    send_command(sock, "MAIL FROM:<sender@example.com>\r\n", response);
    printf("%s", response);
    
    // Send RCPT TO command
    send_command(sock, "RCPT TO:<recipient@example.com>\r\n", response);
    printf("%s", response);
    
    // Send DATA command
    send_command(sock, "DATA\r\n", response);
    printf("%s", response);
    
    // Send email
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, MAX, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n");
    send(sock, buffer, strlen(buffer), 0);
    
    // Send QUIT command
    send_command(sock, "QUIT\r\n", response);
    printf("%s", response);

    // Close the socket
    close(sock);
    
    return 0;
}

void send_command(int sock, char* cmd, char* response) {
    memset(response, 0, sizeof(response));
    send(sock, cmd, strlen(cmd), 0);
    recv(sock, response, MAX, 0);
}

void get_hostname(char *hostname) {
    char buffer[MAX];
    memset(buffer, 0, sizeof(buffer));
    printf("Enter hostname: ");
    fgets(buffer, MAX, stdin);
    strtok(buffer, "\n");
    strcpy(hostname, buffer);
}

void error(char *msg) {
    perror(msg);
    exit(1);
}
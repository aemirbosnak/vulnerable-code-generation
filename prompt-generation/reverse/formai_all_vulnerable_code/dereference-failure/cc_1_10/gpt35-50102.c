//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        printf("Usage: %s <server_ip> <server_port> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int sock, port, n;
    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    
    port = atoi(argv[2]);
    
    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        error("Error opening socket");
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    
    // Setting server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }
    
    // Connecting to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }
    
    printf("Connected to server\n");
    
    // Receiving server banner
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sock, buffer, BUFFER_SIZE - 1);
    
    if (n < 0) {
        error("Error reading from socket");
    }
    
    printf("Server banner:\n%s\n", buffer);
    
    // Sending user
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "USER %s\r\n", argv[3]);
    n = write(sock, buffer, strlen(buffer));
    
    if (n < 0) {
        error("Error sending to server");
    }
    
    // Receiving response to user
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sock, buffer, BUFFER_SIZE - 1);
    
    if (n < 0) {
        error("Error reading from socket");
    }
    
    printf("Server response to user:\n%s\n", buffer);
    
    // Asking for password
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE - 1, stdin);
    password[strlen(password) - 1] = '\0';
    
    // Sending password
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sock, buffer, strlen(buffer));
    
    if (n < 0) {
        error("Error sending to server");
    }
    
    // Receiving response to password
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sock, buffer, BUFFER_SIZE - 1);
    
    if (n < 0) {
        error("Error reading from socket");
    }
    
    printf("Server response to password:\n%s\n", buffer);
    
    // Sending quit
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");
    n = write(sock, buffer, strlen(buffer));
    
    if (n < 0) {
        error("Error sending to server");
    }
    
    // Receiving response to quit
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sock, buffer, BUFFER_SIZE - 1);
    
    if (n < 0) {
        error("Error reading from socket");
    }
    
    printf("Server response to QUIT:\n%s\n", buffer);
    
    // Closing socket
    close(sock);
    
    printf("Disconnected\n");
    
    return 0;
}
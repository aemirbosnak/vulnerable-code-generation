//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function to send a message and wait for the response from the server
int send_message(int sock, char* message, char* expected_response) {
    char buffer[BUFFER_SIZE] = {0};
    int read_size = 0;
    
    // Send message to server
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("[ERROR] Could not send message to server\n");
        return 1;
    }
    
    // Wait for response from server
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%s", buffer);
        
        // Check if expected response has been received
        if (strstr(buffer, expected_response)) {
            break;
        }
        
        memset(buffer, 0, sizeof(buffer));
    }
    
    if (read_size == 0) {
        printf("[ERROR] Server disconnected\n");
        return 1;
    } else if (read_size < 0) {
        printf("[ERROR] Could not receive message from server\n");
        return 1;
    }
    
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("[ERROR] Invalid number of arguments\n");
        printf("Usage: pop3_client <server> <port> <username>\n");
        return 1;
    }
    
    char* server = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];
    
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("[ERROR] Could not create socket\n");
        return 1;
    }
    
    // Convert server IP address to binary form
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        printf("[ERROR] Invalid server IP address\n");
        return 1;
    }
    
    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("[ERROR] Could not connect to server\n");
        return 1;
    }
    
    // Wait for server response
    if (send_message(sock, "", "+OK") != 0) {
        close(sock);
        return 1;
    }
    
    // Send login credentials to server
    char login_message[BUFFER_SIZE] = {0};
    snprintf(login_message, sizeof(login_message), "USER %s\r\n", username);
    if (send_message(sock, login_message, "+OK") != 0) {
        close(sock);
        return 1;
    }
    
    char password[BUFFER_SIZE] = {0};
    printf("Password: ");
    scanf("%s", password);
    char password_message[BUFFER_SIZE] = {0};
    snprintf(password_message, sizeof(password_message), "PASS %s\r\n", password);
    if (send_message(sock, password_message, "+OK") != 0) {
        close(sock);
        return 1;
    }
    
    // List all emails
    if (send_message(sock, "LIST\r\n", "+OK") != 0) {
        close(sock);
        return 1;
    }
    
    // Quit POP3 session
    if (send_message(sock, "QUIT\r\n", "+OK") != 0) {
        close(sock);
        return 1;
    }
    
    close(sock);
    return 0;
}
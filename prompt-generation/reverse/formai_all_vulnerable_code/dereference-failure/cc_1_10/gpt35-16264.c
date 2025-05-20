//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

char *IMAP_SERVER = "imap.gmail.com";
int IMAP_PORT = 993;

// Function to create a socket and connect to the IMAP server
int createSocketAndConnect() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    struct hostent* hostInfo;
    
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("[ERROR] Unable to create socket");
        return -1;
    }
    
    hostInfo = gethostbyname(IMAP_SERVER);
    if (hostInfo == NULL) {
        perror("[ERROR] Unable to resolve server name");
        return -1;
    }
    
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(IMAP_PORT);
    memcpy(&serverAddr.sin_addr, hostInfo->h_addr, hostInfo->h_length);
    
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0) {
        perror("[ERROR] Unable to connect to server");
        return -1;
    }
    
    return clientSocket;
}

// Function to send a message to the server
int sendMessage(int sock, char* message) {
    int bytesSent = send(sock, message, strlen(message), 0);
    if (bytesSent < 0) {
        perror("[ERROR] Unable to send message to server");
        return -1;
    }
    
    return bytesSent;
}

// Function to receive a message from the server
int receiveMessage(int sock, char* buffer) {
    memset(buffer, 0, MAX_BUFFER_SIZE);
    int bytesRead = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    if (bytesRead < 0) {
        perror("[ERROR] Unable to receive message from server");
        return -1;
    }
    
    return bytesRead;
}

// Main function to connect to the server and retrieve mailbox information
int main() {
    char* username = "<INSERT USERNAME HERE>";
    char* password = "<INSERT PASSWORD HERE>";
    int sock = createSocketAndConnect();
    char buffer[MAX_BUFFER_SIZE];
    
    if (sock < 0) {
        fprintf(stderr, "[ERROR] Unable to connect to IMAP server %s:%d", IMAP_SERVER, IMAP_PORT);
        return -1;
    }
    
    receiveMessage(sock, buffer); // Receive the server greeting message
    
    sprintf(buffer, "a001 LOGIN %s %s\r\n", username, password);
    sendMessage(sock, buffer); // Send the login command to the server
    receiveMessage(sock, buffer); // Receive the server response for the login command
    
    sprintf(buffer, "a002 SELECT INBOX\r\n");
    sendMessage(sock, buffer); // Send the select command to the server
    receiveMessage(sock, buffer); // Receive the server response for the select command
    
    printf("[INFO] Mailbox information:\n%s", buffer);
    
    sprintf(buffer, "a003 LOGOUT\r\n");
    sendMessage(sock, buffer); // Send the logout command to the server
    receiveMessage(sock, buffer); // Receive the server response for the logout command
    
    printf("[INFO] Connection closed by server\n");
    
    close(sock); // Close the socket
    
    return 0;
}
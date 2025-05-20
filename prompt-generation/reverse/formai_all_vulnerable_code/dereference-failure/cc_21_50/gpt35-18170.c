//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char* argv[]) {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[MAX_BUFFER];
    char* serverIP;
    int serverPort;

    if(argc < 3) {
        printf("Usage: %s <server IP> <server port>\n", argv[0]);
        exit(1);
    }

    // Parse command line arguments
    serverIP = argv[1];
    serverPort = atoi(argv[2]);

    // Create socket
    if((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set up address for server
    memset(&serverAddr, 0, sizeof(serverAddr)); // Zero out structure
    serverAddr.sin_family = AF_INET; // Internet address family
    serverAddr.sin_addr.s_addr = inet_addr(serverIP); // Server IP address
    serverAddr.sin_port = htons(serverPort); // Server port number

    // Connect to server
    if(connect(clientSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Failed to connect");
        exit(1);
    }

    // Receive greeting message from server
    if(recv(clientSocket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send HELO message to server
    char heloMsg[MAX_BUFFER];
    sprintf(heloMsg, "HELO %s\r\n", serverIP);
    if(send(clientSocket, heloMsg, strlen(heloMsg), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }

    // Receive response from server
    if(recv(clientSocket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send MAIL FROM message to server
    char fromMsg[MAX_BUFFER];
    printf("Please enter your email address: ");
    fflush(stdout);
    if(fgets(buffer, MAX_BUFFER, stdin) == NULL) {
        perror("Failed to read email address from stdin");
        exit(1);
    }
    buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline character
    sprintf(fromMsg, "MAIL FROM: <%s>\r\n", buffer);
    if(send(clientSocket, fromMsg, strlen(fromMsg), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }

    // Receive response from server
    if(recv(clientSocket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send RCPT TO message to server
    char toMsg[MAX_BUFFER];
    printf("Please enter the recipient's email address: ");
    fflush(stdout);
    if(fgets(buffer, MAX_BUFFER, stdin) == NULL) {
        perror("Failed to read email address from stdin");
        exit(1);
    }
    buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline character
    sprintf(toMsg, "RCPT TO: <%s>\r\n", buffer);
    if(send(clientSocket, toMsg, strlen(toMsg), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }

    // Receive response from server
    if(recv(clientSocket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send DATA message to server
    char dataMsg[MAX_BUFFER];
    sprintf(dataMsg, "DATA\r\n");
    if(send(clientSocket, dataMsg, strlen(dataMsg), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }

    // Receive response from server
    if(recv(clientSocket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send message body to server
    printf("Please enter the message body:\n");
    fflush(stdout);
    char line[MAX_BUFFER];
    while(fgets(line, MAX_BUFFER, stdin) != NULL) {
        if(line[0] == '.' && line[1] == '\n') {
            break; // End of message body
        }
        if(send(clientSocket, line, strlen(line), 0) < 0) {
            perror("Failed to send message to server");
            exit(1);
        }
    }

    // Send QUIT message to server
    char quitMsg[MAX_BUFFER];
    sprintf(quitMsg, "QUIT\r\n");
    if(send(clientSocket, quitMsg, strlen(quitMsg), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }

    // Receive response from server
    if(recv(clientSocket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(clientSocket);

    return 0;
}
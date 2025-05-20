//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 110 // POP3 port number

int main(int argc, char *argv[]) {
    int clientSocket, n;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    // Create a new client socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify the server address and connection details
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

    // Convert the server address to the appropriate format and connect to it
    addr_size = sizeof serverAddr;
    connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

    // Receive the welcome message from the server
    recv(clientSocket, buffer, 1024, 0);
    printf("%s", buffer);

    // Send the login credentials to the server
    char username[] = "example@pop3.com";
    char password[] = "password123";
    char loginCommand[100];
    sprintf(loginCommand, "USER %s\r\nPASS %s\r\n", username, password);
    send(clientSocket, loginCommand, strlen(loginCommand), 0);

    // Receive the response from the server
    recv(clientSocket, buffer, 1024, 0);
    printf("%s", buffer);

    // Send the command to list all messages in the mailbox
    char listCommand[] = "LIST\r\n";
    send(clientSocket, listCommand, strlen(listCommand), 0);

    // Receive the list of messages from the server
    recv(clientSocket, buffer, 1024, 0);
    printf("%s", buffer);

    // Send the command to quit the session and close the connection
    char quitCommand[] = "QUIT\r\n";
    send(clientSocket, quitCommand, strlen(quitCommand), 0);

    // Receive the response from the server and close the socket
    recv(clientSocket, buffer, 1024, 0);
    printf("%s", buffer);
    close(clientSocket);

    return 0;
}
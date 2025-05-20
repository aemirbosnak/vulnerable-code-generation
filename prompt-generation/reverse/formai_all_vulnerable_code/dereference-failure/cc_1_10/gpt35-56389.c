//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Declare helper functions
void error(char *msg);
int createClientSocket(char *server, char *port);
void sendRequest(int clientSocket, char *request);
void receiveResponse(int clientSocket);

int main()
{
    // Set server and port to connect to
    char *server = "example.com";
    char *port = "80";
    
    // Construct HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    
    // Create client socket
    int clientSocket = createClientSocket(server, port);
    
    // Send HTTP request
    sendRequest(clientSocket, request);
    
    // Receive HTTP response
    receiveResponse(clientSocket);
    
    // Close client socket
    close(clientSocket);
    
    return 0;
}

// Display error message and exit program
void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

// Create client socket and connect to server
int createClientSocket(char *server, char *port)
{
    // Declare variables
    struct addrinfo hints, *res;
    int status, clientSocket;
    
    // Set up hints struct
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    // Get address info for server
    if ((status = getaddrinfo(server, port, &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }
    
    // Create client socket
    clientSocket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (clientSocket == -1)
        error("socket error");
    
    // Connect to server
    if (connect(clientSocket, res->ai_addr, res->ai_addrlen) == -1)
        error("connect error");
    
    // Free memory allocated for address info
    freeaddrinfo(res);
    
    return clientSocket;
}

// Send HTTP request to server
void sendRequest(int clientSocket, char *request)
{
    // Send HTTP request
    int bytesSent = send(clientSocket, request, strlen(request), 0);
    if (bytesSent == -1)
        error("send error");
}

// Receive HTTP response from server
void receiveResponse(int clientSocket)
{
    // Declare variables
    char response[1024];
    int bytesRead;
    
    // Receive HTTP response
    while ((bytesRead = recv(clientSocket, response, sizeof(response)-1, 0)) > 0)
    {
        response[bytesRead] = '\0';
        printf("%s", response);
    }
    
    if (bytesRead == -1)
        error("recv error");
}
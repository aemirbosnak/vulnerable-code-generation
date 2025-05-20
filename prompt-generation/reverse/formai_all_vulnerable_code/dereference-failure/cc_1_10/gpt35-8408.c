//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int proxy (int clientSock, char *hostName, int portNumber) {
    struct sockaddr_in proxyServAddr;
    struct hostent *server;

    // Create a socket for the proxy server
    int proxySock = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (proxySock < 0) {
        perror("Proxy server error: Unable to create socket");
        return -1;
    }

    // Get the server details from the hostname
    server = gethostbyname(hostName);

    // Check if the server details were obtained successfully
    if (server == NULL) {
        fprintf(stderr, "Proxy server error: Unable to resolve host %s\n", hostName);
        return -1;
    }

    // Set the proxy server address details
    bzero((char *) &proxyServAddr, sizeof(proxyServAddr));
    proxyServAddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &proxyServAddr.sin_addr.s_addr, server->h_length);
    proxyServAddr.sin_port = htons(portNumber);

    // Connect to the server via the proxy server
    if (connect(proxySock, (struct sockaddr *) &proxyServAddr, sizeof(proxyServAddr)) < 0) {
        perror("Proxy server error: Unable to connect to server");
        return -1;
    }

    // Create buffers for reading data
    char requestBuffer[BUFFER_SIZE];
    char responseBuffer[BUFFER_SIZE];

    // Clear buffers
    bzero(requestBuffer, BUFFER_SIZE);
    bzero(responseBuffer, BUFFER_SIZE);

    // Read the client request
    int n = read(clientSock, requestBuffer, BUFFER_SIZE - 1);

    // Check if the client request was read successfully
    if (n < 0) {
        perror("Proxy server error: Unable to read client request");
        return -1;
    }

    // Send the client request to the server via the proxy server
    n = write(proxySock, requestBuffer, strlen(requestBuffer));

    // Check if the client request was sent successfully to the server via the proxy server
    if (n < 0) {
        perror("Proxy server error: Unable to send client request to server via proxy server");
        return -1;
    }

    // Read the server response
    n = read(proxySock, responseBuffer, BUFFER_SIZE - 1);

    // Check if the server response was read successfully
    if (n < 0) {
        perror("Proxy server error: Unable to read server response");
        return -1;
    }

    // Send the server response to the client
    n = write(clientSock, responseBuffer, strlen(responseBuffer));

    // Check if the server response was sent successfully to the client
    if (n < 0) {
        perror("Proxy server error: Unable to send server response to client");
        return -1;
    }

    // Close the sockets
    close(clientSock);
    close(proxySock);

    // Return success code
    return 0;
}

int main(int argc, char *argv[]) {
    int serverSock, clientSock, portNumber;
    socklen_t clientLength;
    struct sockaddr_in serverAddr, clientAddr;

    // Check if the port number has been specified in the arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
        exit(1);
    }

    // Create a socket for the proxy server
    serverSock = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (serverSock < 0) {
        perror("Proxy server error: Unable to create socket");
        exit(1);
    }

    // Set the server address details
    bzero((char *) &serverAddr, sizeof(serverAddr));
    portNumber = atoi(argv[1]);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(portNumber);

    // Bind the socket to the server address
    if (bind(serverSock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Proxy server error: Unable to bind socket to server address");
        exit(1);
    }

    // Listen for incoming requests
    listen(serverSock, 5);

    // Loop infinitely to handle requests
    while (1) {
        // Accept incoming requests
        clientLength = sizeof(clientAddr);
        clientSock = accept(serverSock, (struct sockaddr *) &clientAddr, &clientLength);
        
        // Check if the client request was accepted successfully
        if (clientSock < 0) {
            perror("Proxy server error: Unable to accept client request");
            exit(1);
        }

        // Get the client IP address and port number
        char clientIpAddr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddr.sin_addr), clientIpAddr, INET_ADDRSTRLEN);
        int clientPortNumber = ntohs(clientAddr.sin_port);

        // Print the client details
        printf("Connection accepted from %s:%d\n", clientIpAddr, clientPortNumber);

        // Handle request via proxy
        if (proxy(clientSock, "www.example.com", 80) < 0) {
            perror("Proxy server error: Unable to handle request via proxy");
            exit(1);
        }

        // Print the client details
        printf("Connection closed with %s:%d\n", clientIpAddr, clientPortNumber);
    }

    // Close the server socket
    close(serverSock);

    // Return success code
    return 0;
}
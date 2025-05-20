//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT "8080"     // the port users will be connecting to
#define BUFFER_SIZE 1024

// Get the address information of the host
int getServerAddress(struct addrinfo **serverAddrInfo) {
    // Set up hints for getaddrinfo
    struct addrinfo hints;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status;
    if ((status = getaddrinfo(NULL, PORT, &hints, serverAddrInfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }
    return 0;
}

// Create a socket and bind it to the server address
int bindSocket(int *serverSocket, struct addrinfo *serverAddrInfo) {
    // Create a socket
    *serverSocket = socket(serverAddrInfo->ai_family, serverAddrInfo->ai_socktype, serverAddrInfo->ai_protocol);
    if (*serverSocket < 0) {
        fprintf(stderr, "socket error\n");
        return 1;
    }

    // Bind the socket to the server address
    int yes = 1;
    if (setsockopt(*serverSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt error");
        return 1;
    }
    if (bind(*serverSocket, serverAddrInfo->ai_addr, serverAddrInfo->ai_addrlen) < 0) {
        fprintf(stderr, "bind error\n");
        return 1;
    }
    return 0;
}

int main(void) {
    struct addrinfo *serverAddrInfo;
    int serverSocket;
    char buffer[BUFFER_SIZE];

    // Get address information of host
    if (getServerAddress(&serverAddrInfo)) {
        fprintf(stderr, "Error getting server address information\n");
        exit(1);
    }

    // Bind socket to server address
    if (bindSocket(&serverSocket, serverAddrInfo)) {
        fprintf(stderr, "Error binding socket to server address\n");
        exit(1);
    }

    freeaddrinfo(serverAddrInfo); // Free the address information structure

    // Listen for incoming connections
    if (listen(serverSocket, 10) != 0) {
        fprintf(stderr, "listen error\n");
        exit(1);
    }

    printf("Server is now listening on port %s\n", PORT);

    while (1) { // Keep accepting connections
        struct sockaddr_storage clientAddr;
        socklen_t clientAddrSize = sizeof clientAddr;
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrSize);
        if (clientSocket < 0) {
            fprintf(stderr, "accept error\n");
            continue;
        }

        // Get the IP address of the client
        char clientIP[INET6_ADDRSTRLEN];
        inet_ntop(clientAddr.ss_family, &((struct sockaddr_in *)&clientAddr)->sin_addr, clientIP, sizeof clientIP);
        printf("Connection from %s\n", clientIP);

        // Receive and print data from client
        ssize_t numBytesReceived = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
        if (numBytesReceived < 0) {
            fprintf(stderr, "receive error\n");
            close(clientSocket);
            continue;
        }
        buffer[numBytesReceived] = '\0';
        printf("Received message: %s", buffer);

        // Send response back to client
        char response[BUFFER_SIZE];
        time_t currentTime = time(NULL);
        sprintf(response, "Server time: %s", ctime(&currentTime));
        ssize_t numBytesSent = send(clientSocket, response, strlen(response), 0);
        if (numBytesSent < 0) {
            fprintf(stderr, "send error\n");
        }

        close(clientSocket); // Close the connection with the client
    }

    close(serverSocket); // Close the server socket
    return 0;
}
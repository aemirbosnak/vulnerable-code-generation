//FormAI DATASET v1.0 Category: Chat server ; Style: invasive
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXPENDING 5    // Maximum number of simultaneous connections allowed
#define BUFFSIZE 32     // Size of the buffer for receiving messages

int main(int argc, char *argv[])
{
    int serverSock; // Socket descriptor for server
    int clientSock; // Socket descriptor for client
    struct sockaddr_in echoServerAddr; // Local address
    struct sockaddr_in echoClientAddr; // Client address
    unsigned short echoServerPort; // Server port
    unsigned int clientLen; 

    if (argc != 2) // Test for correct number of arguments
    {
        fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }

    echoServerPort = atoi(argv[1]); // First arg: local port

    // Create socket for incoming connections
    if ((serverSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("socket() failed");
        exit(1);
    }

    // Construct local address structure
    memset(&echoServerAddr, 0, sizeof(echoServerAddr)); // Zero out structure
    echoServerAddr.sin_family = AF_INET; // Internet address family
    echoServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface
    echoServerAddr.sin_port = htons(echoServerPort); // Local port

    // Bind to the local address
    if (bind(serverSock, (struct sockaddr *)&echoServerAddr, sizeof(echoServerAddr)) < 0)
    {
        perror("bind() failed");
        exit(1);
    }

    // Mark the socket so it will listen for incoming connections
    if (listen(serverSock, MAXPENDING) < 0)
    {
        perror("listen() failed");
        exit(1);
    }

    // Set up the echo server to receive messages
    while (1)
    {
        clientLen = sizeof(echoClientAddr);

        // Wait for a client to connect
        if ((clientSock = accept(serverSock, (struct sockaddr *)&echoClientAddr, &clientLen)) < 0)
        {
            perror("accept() failed");
            exit(1);
        }

        // Check if client IP is invasive
        if (strstr(inet_ntoa(echoClientAddr.sin_addr), "127.0.0.1"))
        {
            printf("Connection from invasive IP: %s\n", inet_ntoa(echoClientAddr.sin_addr));
            close(clientSock);
            continue;
        }

        printf("Handling client: %s\n", inet_ntoa(echoClientAddr.sin_addr));

        // Receive message from client
        char buffer[BUFFSIZE];
        int received = -1;
        if ((received = recv(clientSock, buffer, BUFFSIZE, 0)) < 0)
        {
            perror("recv() failed");
            exit(1);
        }

        // Send message back to client
        if (send(clientSock, buffer, received, 0) != received)
        {
            perror("send() failed");
            exit(1);
        }

        // Close the client socket
        close(clientSock);
    }

    // NOT REACHED
    return 0;
}
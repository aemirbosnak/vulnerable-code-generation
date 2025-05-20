//FormAI DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_CONNECTIONS 100
#define BUFFER_SIZE 1024
#define MAX_PENDING 10
#define DEFAULT_PORT 8080

int serverSocket;

void handleSigInt(int sig)
{
    close(serverSocket);
    exit(EXIT_SUCCESS);
}

void setSignalHandlers()
{
    struct sigaction newAction;
    memset(&newAction, 0, sizeof(newAction));
    newAction.sa_handler = handleSigInt;
    sigaction(SIGINT, &newAction, NULL);
}

void handleRequest(int clientSocket)
{
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);

    if (recv(clientSocket, buffer, BUFFER_SIZE, 0) <= 0)
    {
        perror("Unable to read from client");
        close(clientSocket);
        return;
    }

    if (strncmp("GET", buffer, 3) != 0)
    {
        perror("Invalid request from client");
        close(clientSocket);
        return;
    }

    const char* response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 13\n\nHello, world!";

    if (send(clientSocket, response, strlen(response), 0) == -1)
    {
        perror("Unable to send response");
        close(clientSocket);
        return;
    }

    close(clientSocket);
}

void startServer(int port)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1)
    {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) == -1)
    {
        perror("Unable to bind to socket");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, MAX_PENDING) == -1)
    {
        perror("Unable to start listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d...\n", port);

    while (1)
    {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);

        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);

        if (clientSocket == -1)
        {
            perror("Unable to accept client connection");
            continue;
        }

        handleRequest(clientSocket);
    }
}

int main(int argc, char* argv[])
{
    int port = DEFAULT_PORT;

    if (argc > 1)
    {
        port = atoi(argv[1]);
    }

    setSignalHandlers();

    startServer(port);

    return EXIT_SUCCESS;
}
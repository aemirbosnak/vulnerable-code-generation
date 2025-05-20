//FormAI DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define RESPONSE "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello World!"

int main(int argc, char *argv[]) {
    int portNumber, socketServer, socketClient, connectionResult;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientLength = sizeof(clientAddress);
    char buffer[1024];

    if (argc < 2) {
        printf("Error: please provide port number");
        exit(1);
    }

    portNumber = atoi(argv[1]);
    printf("Creating server on port %d...\n", portNumber);

    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServer < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(portNumber);

    if (bind(socketServer, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    listen(socketServer, 5);

    printf("Listening for incoming connections...\n");

    while(1) {
        socketClient = accept(socketServer, (struct sockaddr*)&clientAddress, &clientLength);
        if (socketClient < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        connectionResult = read(socketClient, buffer, 1023);
        if (connectionResult < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        printf("Incoming message: %s", buffer);

        connectionResult = write(socketClient, RESPONSE, strlen(RESPONSE));
        if (connectionResult < 0) {
            perror("Error writing to socket");
            exit(1);
        }

        close(socketClient);
    }

    return 0;
}
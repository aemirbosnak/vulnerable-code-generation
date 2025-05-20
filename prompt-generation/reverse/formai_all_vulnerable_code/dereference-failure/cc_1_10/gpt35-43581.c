//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int socketfd, newSocket, portNumber, clientLength, n;
    char buffer[1024];
    struct sockaddr_in serverAddress, clientAddress;

    if (argc < 2) {
        printf("Error! Please provide port number.\n");
        exit(1);
    }

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        printf("Error! Cannot open socket.\n");
        exit(1);
    }

    memset(&serverAddress, '\0', sizeof(serverAddress));
    portNumber = atoi(argv[1]);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(portNumber);

    if (bind(socketfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        printf("Error! Cannot bind socket.\n");
        exit(1);
    }

    listen(socketfd, 5);
    printf("Listening on port %d...\n", portNumber);
    clientLength = sizeof(clientAddress);

    while (1) {
        newSocket = accept(socketfd, (struct sockaddr*)&clientAddress, &clientLength);
        if (newSocket < 0) {
            printf("Error! Cannot accept client connection.\n");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));

        memset(buffer, '\0', 1024);
        n = read(newSocket, buffer, 1024);
        if (n < 0) {
            printf("Error! Cannot read from socket.\n");
            exit(1);
        }

        printf("Message received: %s\n", buffer);

        char response[1024];

        sprintf(response, "Hello, %s! Your message has been successfully received.", inet_ntoa(clientAddress.sin_addr));

        n = write(newSocket, response, strlen(response));
        if (n < 0) {
            printf("Error! Cannot write to socket.\n");
            exit(1);
        }

        printf("Response sent.\n");

        close(newSocket);

        printf("Client connection closed.\n");
    }

    close(socketfd);
    return 0;
}
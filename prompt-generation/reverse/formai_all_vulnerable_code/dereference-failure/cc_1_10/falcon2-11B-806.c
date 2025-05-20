//Falcon2-11B DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

void* clientThread(void* clientSocket) {
    int* clientSocketPtr = (int*)clientSocket;
    char buffer[1024];
    char serverMessage[1024];
    int messageLength;

    while (1) {
        messageLength = read(*clientSocketPtr, buffer, sizeof(buffer));
        if (messageLength <= 0) {
            printf("Error reading from socket\n");
            break;
        }
        memcpy(serverMessage, buffer, messageLength);
        printf("Received message: %s\n", serverMessage);
        if (strcmp(serverMessage, "bye") == 0) {
            printf("Closing connection\n");
            break;
        }
        send(*clientSocketPtr, "ack", sizeof("ack"), 0);
    }
    return NULL;
}

int main() {
    int serverSocketFD, newSocketFD, portNumber;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
    int clientSocketFD;
    int addrlen = sizeof(clientAddress);

    serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocketFD < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);

    if (bind(serverSocketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("ERROR on binding");
        return 1;
    }

    listen(serverSocketFD, 5);

    while (1) {
        newSocketFD = accept(serverSocketFD, (struct sockaddr*)&clientAddress, (socklen_t*)&addrlen);
        if (newSocketFD < 0) {
            perror("ERROR on accept");
            return 1;
        }
        pthread_t clientThreadID;
        pthread_create(&clientThreadID, NULL, clientThread, (void*)&newSocketFD);
    }

    return 0;
}
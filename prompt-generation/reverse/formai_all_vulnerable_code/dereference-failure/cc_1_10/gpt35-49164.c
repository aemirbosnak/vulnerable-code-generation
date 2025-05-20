//FormAI DATASET v1.0 Category: Chat server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *socketThread(void *);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[1]);

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error opening socket");
        exit(1);
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(serverSocket, 5) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server is listening on port %d\n", port);

    pthread_t tid[50];
    int i = 0;

    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientLength = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientLength);
        if (clientSocket < 0) {
            perror("Error accepting connection");
            continue;
        }

        printf("New client connection accepted\n");

        if(pthread_create(&tid[i++], NULL, socketThread, &clientSocket) != 0) {
            perror("Error creating thread");
        }

        if (i >= 50) {
            i = 0;
            while (i < 50) {
                pthread_join(tid[i++], NULL);
            }
            i = 0;
        }
    }

    return 0;
}

void *socketThread(void *arg) {
    int clientSocket = *(int *) arg;
    char message[1024];

    while (1) {
        memset(message, 0, sizeof(message));
        int bytesReceived = recv(clientSocket, message, sizeof(message), 0);
        if (bytesReceived < 0) {
            perror("Error receiving data from client");
            break;
        }

        if (bytesReceived == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received message from client: %s\n", message);

        if (send(clientSocket, message, bytesReceived, 0) < 0) {
            perror("Error sending data to client");
            break;
        }
    }

    close(clientSocket);
    pthread_exit(NULL);
}
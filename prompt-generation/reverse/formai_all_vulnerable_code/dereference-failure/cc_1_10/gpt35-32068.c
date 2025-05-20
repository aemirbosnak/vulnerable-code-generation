//FormAI DATASET v1.0 Category: Chat server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int clientCount = 0;
pthread_mutex_t mutex;

void sendToAll(int sender, char message[]) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < clientCount; i++) {
        if (clients[i] != sender) {
            send(clients[i], message, strlen(message), 0);  
        }
    }
    pthread_mutex_unlock(&mutex);
}

void *handleClient(void *arg) {
    int socket = *((int *)arg);
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (recv(socket, buffer, BUFFER_SIZE, 0) > 0) {
        sendToAll(socket, buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < clientCount; i++) {
        if (clients[i] == socket) {
            for (int j = i; j < clientCount - 1; j++) {
                clients[j] = clients[j + 1];
            }
        }
    }
    clientCount--;
    pthread_mutex_unlock(&mutex);
    close(socket);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    pthread_t tid;

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("ERROR: Could not create server socket\n");
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(atoi(argv[1]));

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("ERROR: Could not bind server socket\n");
        return 1;
    }

    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        printf("ERROR: Could not listen on server socket\n");
        return 1;
    }

    printf("Waiting for clients to connect...\n");

    while (1) {
        socklen_t clientLen = sizeof(clientAddr);
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientLen)) < 0) {
            printf("ERROR: Could not accept client connection\n");
            continue;
        } else {
            printf("Client connected successfully\n");
        }
        pthread_mutex_lock(&mutex);
        clients[clientCount] = clientSocket;
        clientCount++;
        pthread_mutex_unlock(&mutex);
        pthread_create(&tid, NULL, handleClient, &clientSocket);
    }
    close(serverSocket);
    return 0;
}
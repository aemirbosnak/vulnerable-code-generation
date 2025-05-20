//FormAI DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static int client_counter = 0;

// Client data structure
typedef struct {
    int sockfd;
    struct sockaddr_in address;
    char name[50];
} client_t;

client_t *clients[MAX_CLIENTS];

void sendToAllClients(char *message, int currentClient) {
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i] && clients[i]->sockfd != currentClient) {
            printf("Sending message to %s\n", clients[i]->name);
            send(clients[i]->sockfd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void removeClient(int clientIndex) {
    close(clients[clientIndex]->sockfd);
    free(clients[clientIndex]);
    clients[clientIndex] = NULL;
    client_counter--;
}

void *handleClient(void *arg) {
    char buffer[BUFFER_SIZE];
    int clientIndex = client_counter++;
    client_t *client = (client_t *) arg;
    clients[clientIndex] = client;
    printf("%s connected, total clients: %d\n", client->name, client_counter);
    while(1) {
        bzero(&buffer, BUFFER_SIZE);
        int readBytes = recv(client->sockfd, buffer, BUFFER_SIZE, 0);
        if(readBytes > 0){
            if(strncmp(buffer, "/quit", 5) == 0) {
                sendToAllClients(strcat(client->name, " left the chat.\n"), client->sockfd);
                printf("%s left the chat, total clients: %d\n", client->name, client_counter-1);
                removeClient(clientIndex);
                break;
            }
            else {
                printf("%s: %s", client->name, buffer);
                sendToAllClients(strcat(client->name, ": "), client->sockfd);
                sendToAllClients(buffer, client->sockfd);
            }
        }
        else {
            sendToAllClients(strcat(client->name, " left the chat.\n"), client->sockfd);
            printf("%s left the chat, total clients: %d\n", client->name, client_counter-1);
            removeClient(clientIndex);
            break;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    // Initialize socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { 
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0) {
        perror("setsockopt() error");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind() error");
        exit(EXIT_FAILURE);
    }

    // Listen on socket
    if (listen(sockfd, 3) < 0) {
        perror("listen() error");
        exit(EXIT_FAILURE);
    }

    // Accept incoming clients and spawn threads to handle them
    while(1) {
        struct sockaddr_in client_address;
        int client_sockfd, client_address_len = sizeof(client_address);
        if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_len)) < 0) {
            perror("accept() error");
            exit(EXIT_FAILURE);
        }
        char *userName = "User" + (client_counter + 1);
        client_t *client = (client_t *) malloc(sizeof(client_t));
        client->sockfd = client_sockfd;
        client->address = client_address;
        strcpy(client->name, userName);
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handleClient, (void *) client) != 0) {
            printf("Failed to create thread\n");
        }
    }

    // Close socket
    close(sockfd);
    return 0;
}
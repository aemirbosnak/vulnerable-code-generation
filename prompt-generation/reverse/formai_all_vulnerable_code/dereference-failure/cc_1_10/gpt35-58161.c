//FormAI DATASET v1.0 Category: Chat server ; Style: high level of detail
// C Chat Server Example Program

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Data structure for the client threads
typedef struct {
    int socket;
    struct sockaddr_in address;
    char *nickname;
} client_t;

client_t* clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void send_all(char *message, char *sender) {
    pthread_mutex_lock(&clients_mutex);
    for(int i=0; i<MAX_CLIENTS; i++) {
        if(clients[i]) {
            if(strcmp(clients[i]->nickname, sender)!= 0) {
                send(clients[i]->socket, message, strlen(message), 0);
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void handle_client(void *arg) {
    client_t *client = (client_t*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    while((bytes_read = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] == '\0';
        send_all(buffer, client->nickname);
        memset(buffer, 0, BUFFER_SIZE);
    }
    pthread_mutex_lock(&clients_mutex);
    for(int i=0; i<MAX_CLIENTS; i++) {
        if(clients[i] == client) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(client->nickname);
    free(client);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    char *nickname;
    pthread_t thread;

    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    port = atoi(argv[1]);

    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create server socket\n");
        exit(EXIT_FAILURE);
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind server socket\n");
        exit(EXIT_FAILURE);
    }

    if(listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Failed to listen on server socket\n");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d...\n", port);

    while(1) {
        socklen_t client_address_len = sizeof(client_address);
        if((client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len)) < 0) {
            printf("Failed to accept new client connection\n");
            continue;
        }
        if(recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
            printf("Failed to receive client nickname from %s\n", inet_ntoa(client_address.sin_addr));
            close(client_socket);
            continue;
        }
        // Allocate memory for the new client thread
        client_t *client = (client_t*)malloc(sizeof(client_t));
        client->socket = client_socket;
        client->address = client_address;
        // Allocate memory for the nickname
        nickname = (char*)malloc(strlen(buffer)+1);
        strcpy(nickname, buffer);
        client->nickname = nickname;
        // Add the client to the clients array
        pthread_mutex_lock(&clients_mutex);
        for(int i=0; i<MAX_CLIENTS; i++) {
            if(!clients[i]) {
                clients[i] = client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
        printf("%s joined the chat!\n", nickname);
        // Create a new thread to handle the client
        if(pthread_create(&thread, NULL, (void*)handle_client, (void*)client) < 0) {
            printf("Failed to create new thread for the client\n");
            break;
        }
    }
    return 0;
}
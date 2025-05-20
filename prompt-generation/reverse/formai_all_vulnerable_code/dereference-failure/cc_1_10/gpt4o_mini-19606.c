//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <arpa/inet.h>

#define PORT_NUMBER 9000
#define TALK_SPACE 2048 // Max size of a message
#define CLIENTS 100 // Maximum number of clients

int client_sockets[CLIENTS];
pthread_mutex_t client_lock;
char *nicknames[CLIENTS];

void *chat_handler(void *socket_desc);
void send_message(char *message, int exclude_socket);
void add_user(int socket, char *nickname);
void remove_user(int socket);

int main() {
    int master_socket, new_socket, addr_len, *new_sock;
    struct sockaddr_in address;

    pthread_mutex_init(&client_lock, NULL);

    // Creating socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_NUMBER);
    
    // Binding
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(master_socket);
        exit(EXIT_FAILURE);
    }
    
    // Listen
    if (listen(master_socket, 3) < 0) {
        perror("Listen failed");
        close(master_socket);
        exit(EXIT_FAILURE);
    }

    printf("🛰️ Chat Server is running on port %d...\n", PORT_NUMBER);
    
    addr_len = sizeof(address);
    
    while (true) {
        if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t *)&addr_len))) {
            printf("🌐 New connection: socket fd is %d, ip is : %s, port : %d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            
            // Spawn a thread to handle the new chat client
            pthread_t tid;
            new_sock = malloc(1);
            *new_sock = new_socket;
            if (pthread_create(&tid, NULL, chat_handler, (void *)new_sock) != 0) {
                perror("Failed to create thread");
                exit(EXIT_FAILURE);
            }
        }
    }

    close(master_socket);
    return 0;
}

void *chat_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char message[TALK_SPACE], nickname[50];
    bool nickname_set = false;

    // Set nickname for the client
    recv(sock, nickname, sizeof(nickname), 0);
    add_user(sock, nickname);

    // Main loop for handling chat messages
    while (true) {
        int message_length = recv(sock, message, sizeof(message), 0);
        if (message_length <= 0) {
            remove_user(sock);
            break;
        }

        message[message_length] = '\0'; // Ensure null-termination
        send_message(message, sock);
    }

    free(socket_desc);
    close(sock);
    return NULL;
}

void send_message(char *message, int exclude_socket) {
    pthread_mutex_lock(&client_lock);
    for (int i = 0; i < CLIENTS; i++) {
        if (client_sockets[i] > 0 && client_sockets[i] != exclude_socket) {
            if (send(client_sockets[i], message, strlen(message), 0) < 0) {
                perror("Message sending failed");
            }
        }
    }
    pthread_mutex_unlock(&client_lock);
}

void add_user(int socket, char *nickname) {
    pthread_mutex_lock(&client_lock);
    for (int i = 0; i < CLIENTS; i++) {
        if (client_sockets[i] == 0) {
            client_sockets[i] = socket;
            nicknames[i] = strdup(nickname);
            printf("👤 %s entered the chat!\n", nickname);
            break;
        }
    }
    pthread_mutex_unlock(&client_lock);
}

void remove_user(int socket) {
    pthread_mutex_lock(&client_lock);
    for (int i = 0; i < CLIENTS; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = 0;
            printf("🚪 User has left the chat.\n");
            free(nicknames[i]);
            break;
        }
    }
    pthread_mutex_unlock(&client_lock);
}
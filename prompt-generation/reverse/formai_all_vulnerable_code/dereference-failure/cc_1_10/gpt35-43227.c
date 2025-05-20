//FormAI DATASET v1.0 Category: Chat server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// struct to hold client information
typedef struct client {
    struct sockaddr_in address;
    int sockfd;
    char nickname[20];
    bool is_active;
} client_t;

client_t clients[MAX_CLIENTS];  // array of clients
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;  // lock to synchronize access to clients array

// function to handle client messages
void handle_message(int client_index, char *message) {
    char response[BUFFER_SIZE];
    snprintf(response, BUFFER_SIZE, "%s: %s", clients[client_index].nickname, message);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(i != client_index && clients[i].is_active) {
            send(clients[i].sockfd, response, strlen(response), 0);  // send message to all clients except sender
        }
    }
}

// function to handle new client connections
void *handle_connection(void *arg) {
    int client_index = -1;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    pthread_mutex_lock(&lock);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(!clients[i].is_active) {
            client_index = i;
            clients[client_index].is_active = true;
            break;
        }
    }

    if(client_index == -1) {
        printf("Maximum client limit reached. Connection rejected.\n");
        pthread_mutex_unlock(&lock);
        close(*(int *)arg);
        return NULL;
    }

    clients[client_index].sockfd = *(int *)arg;
    clients[client_index].address = *(struct sockaddr_in *)&arg;
    inet_ntop(AF_INET, &clients[client_index].address.sin_addr, clients[client_index].nickname, INET_ADDRSTRLEN);
    printf("Client %s connected on socket %d\n", clients[client_index].nickname, clients[client_index].sockfd);

    pthread_mutex_unlock(&lock);

    int bytes_received;
    char message[BUFFER_SIZE];
    while((bytes_received = recv(clients[client_index].sockfd, message, BUFFER_SIZE, 0)) > 0) {
        message[bytes_received] = '\0';
        printf("%s: %s\n", clients[client_index].nickname, message);
        handle_message(client_index, message);
        memset(message, 0, BUFFER_SIZE);
    }

    close(clients[client_index].sockfd);
    clients[client_index].is_active = false;
    printf("Client %s disconnected from server.\n", clients[client_index].nickname);

    return NULL;
}

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;

    // create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1) {
        perror("ERROR: socket creation failed");
        exit(1);
    }

    // set server socket options
    int opt = 1;
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("ERROR: setsockopt failed");
        close(server_fd);
        exit(1);
    }

    // bind server socket to port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("ERROR: bind failed");
        close(server_fd);
        exit(1);
    }

    // listen for incoming connections
    if(listen(server_fd, MAX_CLIENTS) == -1) {
        perror("ERROR: listen failed");
        close(server_fd);
        exit(1);
    }

    // set server socket to non-blocking mode
    int flags = fcntl(server_fd, F_GETFL);
    fcntl(server_fd, F_SETFL, flags | O_NONBLOCK);

    printf("Server started on port 8080...\n");

    // handle incoming connections in a new thread for each client
    pthread_t tid;
    while(true) {
        socklen_t client_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if(client_fd > 0) {
            pthread_create(&tid, NULL, handle_connection, &client_fd);
            pthread_detach(tid);
        }
        usleep(1000);  // reduce CPU usage by sleeping for 1 millisecond
    }

    return 0;
}
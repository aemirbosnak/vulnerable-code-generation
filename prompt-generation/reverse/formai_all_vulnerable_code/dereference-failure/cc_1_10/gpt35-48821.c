//FormAI DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

struct client {
    int sock_fd;
    char username[50];
    char ip_address[INET_ADDRSTRLEN];
};

struct thread_data {
    struct client *client_ptr;
};

void *handle_client(void *arg) {
    struct thread_data *thread_data_ptr = (struct thread_data *)arg;
    struct client *client_ptr = thread_data_ptr->client_ptr;
    int sock_fd = client_ptr->sock_fd;
    char buffer[BUFFER_SIZE];
    ssize_t receive_size;

    memset(buffer, 0, BUFFER_SIZE);

    while(1) {
        receive_size = recv(sock_fd, buffer, BUFFER_SIZE, 0);
        if(receive_size == -1) {
            perror("Error receiving message from client");
            break;
        }
        else if(receive_size == 0) {
            close(sock_fd);
            break;
        }
        else {
            printf("\n%s: %s", client_ptr->username, buffer);
            // Send the received message back to the client
            if(send(sock_fd, buffer, receive_size, 0) == -1) {
                perror("Error sending message to client");
                break;
            }
            memset(buffer, 0, BUFFER_SIZE);
        }
    }

    printf("\nClient with IP address %s disconnected.", client_ptr->ip_address);
    free(client_ptr);
    free(thread_data_ptr);
    return NULL;
}

int main(int argc, char *argv[]) {
    int listen_fd;
    struct sockaddr_in server_address;
    socklen_t client_address_size;
    pthread_t threads[MAX_CLIENTS];
    struct client *clients[MAX_CLIENTS];
    struct thread_data *thread_data_ptrs[MAX_CLIENTS];
    int i;

    // Create socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    if(bind(listen_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(listen_fd, MAX_CLIENTS) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server started listening on port %d\n", ntohs(server_address.sin_port));

    while(1) {
        struct sockaddr_in client_address;
        int client_fd;

        client_address_size = sizeof(client_address);
        client_fd = accept(listen_fd, (struct sockaddr*)&client_address, &client_address_size);
        if(client_fd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Check if the server is already handling the maximum number of clients
        if(i < MAX_CLIENTS) {
            // Create a new client structure
            clients[i] = (struct client*)malloc(sizeof(struct client));
            clients[i]->sock_fd = client_fd;
            inet_ntop(AF_INET, &(client_address.sin_addr), clients[i]->ip_address, INET_ADDRSTRLEN);

            // Receive the username from the client
            printf("\nClient with IP address %s connected.", clients[i]->ip_address);
            printf("\nEnter your username: ");

            if(recv(client_fd, clients[i]->username, 50, 0) == -1) {
                perror("Error receiving message from client");
                continue;
            }
            printf("\n%s has joined the chatroom.", clients[i]->username);

            // Create a thread to handle the new client
            thread_data_ptrs[i] = (struct thread_data*)malloc(sizeof(struct thread_data));
            thread_data_ptrs[i]->client_ptr = clients[i];
            if(pthread_create(&threads[i], NULL, handle_client, (void*)thread_data_ptrs[i]) != 0) {
                perror("Error creating client thread");
                continue;
            }
            i++;
        }
        else {
            printf("\nMaximum number of clients exceeded. Connection from %s refused.", inet_ntoa(client_address.sin_addr));
            close(client_fd);
        }
    }

    // Close all client connections
    for(int j=0; j<i; j++) {
        if(clients[j] != NULL) {
            close(clients[j]->sock_fd);
            free(clients[j]);
            free(thread_data_ptrs[j]);
        }
    }

    // Close server socket
    close(listen_fd);
    return 0;
}
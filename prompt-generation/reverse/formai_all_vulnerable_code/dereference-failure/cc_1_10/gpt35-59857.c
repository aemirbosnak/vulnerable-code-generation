//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Client structure to store each client's information.
typedef struct {
    int socket;
    char name[20];
} Client;

// Global variables.
Client clients[MAX_CLIENTS];
int num_clients = 0;

// Function to broadcast messages to all connected clients.
void broadcast_message(char message[], int sender_socket) {
    for(int i=0; i<num_clients; i++) {
        if(clients[i].socket != sender_socket) {
            write(clients[i].socket, message, strlen(message));
        }
    }
}

// Function to handle each client's requests.
void *handle_client(void *arg) {
    Client client = *(Client *) arg;
    char buffer[BUFFER_SIZE];

    // Receive the client's name.
    read(client.socket, client.name, sizeof(client.name));
    printf("%s has joined the chat. Socket: %d\n", client.name, client.socket);

    // Add the client to the list of connected clients.
    clients[num_clients++] = client;

    // Send welcome message to the new client.
    char welcome_msg[BUFFER_SIZE];
    sprintf(welcome_msg, "Welcome %s! There are %d participants in the chat.\n", client.name, num_clients);
    write(client.socket, welcome_msg, strlen(welcome_msg));

    // Notify all clients about the new participant.
    char new_participant_msg[BUFFER_SIZE];
    sprintf(new_participant_msg, "%s has joined the chat.\n", client.name);
    broadcast_message(new_participant_msg, client.socket);

    // Keep receiving messages from the client and broadcasting them to all other clients.
    while(1) {
        // Receive message.
        int read_size = read(client.socket, buffer, BUFFER_SIZE);
        if(read_size == 0) {
            // Client has disconnected.
            close(client.socket);

            // Notify all clients about the disconnection.
            char disconnection_msg[BUFFER_SIZE];
            sprintf(disconnection_msg, "%s has left the chat.\n", client.name);
            broadcast_message(disconnection_msg, client.socket);

            // Remove the client from the list of connected clients.
            for(int i=0; i<num_clients; i++) {
                if(clients[i].socket == client.socket) {
                    clients[i] = clients[num_clients-1];
                    num_clients--;
                    break;
                }
            }
            break;
        }
        else {
            // Broadcast message to all clients.
            buffer[read_size] = '\0';
            char message[BUFFER_SIZE + 20];
            sprintf(message, "%s: %s", client.name, buffer);
            broadcast_message(message, client.socket);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./server <port_number>\n");
        return -1;
    }

    int port_number = atoi(argv[1]);

    // Create server socket.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Could not create server socket.\n");
        return -1;
    }

    // Bind server socket to the given port number.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    if(bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Could not bind server socket to port %d.\n", port_number);
        return -1;
    }

    // Listen for incoming connections.
    if(listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Could not listen for incoming connections.\n");
        return -1;
    }

    // Accept incoming connections and create new thread to handle each one.
    while(1) {
        // Accept connection.
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if(client_socket == -1) {
            printf("Could not accept incoming connection.\n");
            continue;
        }

        // Create new thread to handle the client's requests.
        pthread_t tid;
        Client client;
        client.socket = client_socket;
        if(pthread_create(&tid, NULL, handle_client, &client) != 0) {
            printf("Could not create thread to handle client.\n");
            continue;
        }

        // Detach the thread.
        pthread_detach(tid);
    }

    close(server_socket);
    return 0;
}
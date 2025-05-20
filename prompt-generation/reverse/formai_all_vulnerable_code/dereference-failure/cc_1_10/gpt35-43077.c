//FormAI DATASET v1.0 Category: Client Server Application ; Style: multivariable
// multivariable style C client-server application example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 2
#define BUFFER_SIZE 1024

struct client_info {
    int id;
    int sockfd;
    char name[20];
    bool is_active;
};

void send_message_to_clients(struct client_info *clients, char *message, int current_client_id) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].is_active && clients[i].id != current_client_id) { 
            send(clients[i].sockfd, message, strlen(message), 0); 
        }
    }
}

void remove_client(int client_index, struct client_info *clients, int *num_clients) {
    shutdown(clients[client_index].sockfd, SHUT_RDWR); 
    close(clients[client_index].sockfd);
    clients[client_index].is_active = false;
    (*num_clients)--;
}

int main() {
    int server_sockfd, client_sockfd, max_sockfd, activity, valread, num_clients = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    char buffer[BUFFER_SIZE];
    struct client_info clients[MAX_CLIENTS];

    // initialize all clients to inactive
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].is_active = false;
        clients[i].id = i;
    }

    // create server socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket");
        return EXIT_FAILURE;
    }
  
    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // bind socket to server address
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        return EXIT_FAILURE;
    }

    // listen for incoming connections
    if (listen(server_sockfd, 2) < 0) {
        perror("Error listening for connections");
        return EXIT_FAILURE;
    }

    // print server info
    printf("Server started at %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

    while (true) {
        // clear socket file descriptors
        fd_set readfds;
        FD_ZERO(&readfds);

        // add server socket to readfds
        FD_SET(server_sockfd, &readfds);
        max_sockfd = server_sockfd;

        // add clients to readfds
        for (int i = 0; i < MAX_CLIENTS; i++) {

            if (clients[i].is_active) {

                FD_SET(clients[i].sockfd, &readfds);

                if (clients[i].sockfd > max_sockfd) {
                    max_sockfd = clients[i].sockfd;
                }
            }
        }

        // monitor all sockets for activity
        activity = select(max_sockfd + 1, &readfds, NULL, NULL, NULL);

        // accept incoming connection
        if (FD_ISSET(server_sockfd, &readfds)) {

            client_len = sizeof(client_addr);

            if ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
                perror("Error accepting connection");
                return EXIT_FAILURE;
            }

            // add client to clients array
            if (num_clients < MAX_CLIENTS) {

                for (int i = 0; i < MAX_CLIENTS; i++) {
                    if (!clients[i].is_active) {
                        clients[i].sockfd = client_sockfd;
                        clients[i].is_active = true;
                        num_clients++;

                        printf("New client connected: %s:%d (socket: %d)\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), clients[i].sockfd);

                        send(clients[i].sockfd, "Welcome to the Server!\n", strlen("Welcome to the Server!\n"), 0);
                        break;
                    }
                }
            }
            else {
                send(client_sockfd, "Max clients reached. Try again later.\n", strlen("Max clients reached. Try again later.\n"), 0);
                shutdown(client_sockfd, SHUT_RDWR);
                close(client_sockfd);
            }
        }

        // handle incoming message
        for (int i = 0; i < MAX_CLIENTS; i++) {

            if (clients[i].is_active && FD_ISSET(clients[i].sockfd, &readfds)) {

                if ((valread = read(clients[i].sockfd, buffer, BUFFER_SIZE)) == 0) {

                    printf("Client disconnected: %s:%d (socket: %d)\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), clients[i].sockfd);
                    remove_client(i, clients, &num_clients);
                    break;

                } else {
                    buffer[valread] = '\0';

                    // check if client sent their name
                    if (strlen(clients[i].name) == 0) {
                        sprintf(clients[i].name, "%s", buffer);
                        printf("%s has joined the chat\n", clients[i].name);
                        send_message_to_clients(clients, " has joined the chat\n", clients[i].id);
                    } else {
                        printf("%s: %s\n", clients[i].name, buffer);
                        send_message_to_clients(clients, buffer, clients[i].id);
                    }
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
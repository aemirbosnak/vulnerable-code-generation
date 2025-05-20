//GEMINI-pro DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// A global variable to store the listening socket.
int listenfd;

// A structure to store the client information.
struct client_info {
    int sockfd;
    struct sockaddr_in addr;
};

// A linked list to store the connected clients.
struct client_list {
    struct client_info *client;
    struct client_list *next;
};

// The head of the linked list.
struct client_list *head = NULL;

// A mutex to protect the linked list.
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// A function to send a message to a client.
void send_message(struct client_info *client, char *message) {
    // Send the message to the client.
    send(client->sockfd, message, strlen(message), 0);
}

// A function to broadcast a message to all connected clients.
void broadcast_message(char *message) {
    // Acquire the lock.
    pthread_mutex_lock(&mutex);

    // Iterate over the linked list and send the message to each client.
    struct client_list *current = head;
    while (current != NULL) {
        send_message(current->client, message);
        current = current->next;
    }

    // Release the lock.
    pthread_mutex_unlock(&mutex);
}

// A function to handle a client connection.
void *handle_client(void *arg) {
    // Get the client information.
    struct client_info *client = (struct client_info *)arg;

    // Receive the client's message.
    char buffer[1024];
    int n = recv(client->sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        // The client has disconnected.
        close(client->sockfd);
        free(client);
        return NULL;
    }

    // Process the client's message.
    printf("Received message from client: %s\n", buffer);

    // Broadcast the message to all connected clients.
    broadcast_message(buffer);

    // Loop until the client disconnects.
    while ((n = recv(client->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        // Process the client's message.
        printf("Received message from client: %s\n", buffer);

        // Broadcast the message to all connected clients.
        broadcast_message(buffer);
    }

    // The client has disconnected.
    close(client->sockfd);
    free(client);
    return NULL;
}

// The main function.
int main(int argc, char **argv) {
    // Create the listening socket.
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the listening socket to the specified port.
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listenfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections.
    if (listen(listenfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections.
    while (1) {
        // Accept the connection.
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int clientfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (clientfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new client structure.
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sockfd = clientfd;
        client->addr = client_addr;

        // Add the client to the linked list.
        pthread_mutex_lock(&mutex);
        struct client_list *new_client = malloc(sizeof(struct client_list));
        new_client->client = client;
        new_client->next = head;
        head = new_client;
        pthread_mutex_unlock(&mutex);

        // Create a new thread to handle the client.
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *)client);
    }

    // Close the listening socket.
    close(listenfd);

    return 0;
}
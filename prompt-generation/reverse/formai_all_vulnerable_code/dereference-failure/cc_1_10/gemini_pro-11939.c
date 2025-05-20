//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// The structure to hold the client information
typedef struct client_info {
    int sockfd;
    struct sockaddr_in addr;
} client_info;

// The list of clients
client_info clients[1024];
int num_clients = 0;

// The function to handle a client
void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;

    // Receive the message from the client
    char buffer[1024];
    int len = recv(client->sockfd, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("recv");
        close(client->sockfd);
        pthread_exit(NULL);
    }

    // Process the message
    printf("Received message from client %s:%d: %s\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port), buffer);

    // Send a response to the client
    char response[] = "Hello from the server!";
    len = send(client->sockfd, response, strlen(response), 0);
    if (len < 0) {
        perror("send");
        close(client->sockfd);
        pthread_exit(NULL);
    }

    // Close the client socket
    close(client->sockfd);

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 10) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept connections from clients
    while (1) {
        client_info client;
        socklen_t len = sizeof(client.addr);
        client.sockfd = accept(sockfd, (struct sockaddr *)&client.addr, &len);
        if (client.sockfd < 0) {
            perror("accept");
            continue;
        }

        // Add the client to the list of clients
        clients[num_clients] = client;
        num_clients++;

        // Create a thread to handle the client
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *)&client);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
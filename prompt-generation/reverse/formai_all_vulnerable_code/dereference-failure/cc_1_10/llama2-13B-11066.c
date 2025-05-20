//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to store client information
typedef struct {
    int sock;
    char name[50];
} client_t;

// Function to handle client connection
void handle_client(int sock) {
    char buffer[256];
    printf("New client connected...\n");

    // Receive name from client
    printf("Please enter your name: ");
    fgets(buffer, 256, stdin);
    client_t *client = (client_t *) malloc(sizeof(client_t));
    client->sock = sock;
    strcpy(client->name, buffer);

    // Broadcast client name to all connected clients
    sendto(sock, client->name, strlen(client->name), 0, (struct sockaddr *) NULL, 0);

    // Handle client requests
    while (1) {
        char command[256];
        printf("Client: ");
        fgets(command, 256, stdin);

        if (strcmp(command, "QUIT") == 0) {
            printf("Client %s disconnected\n", client->name);
            break;
        }

        // Send request to server
        sendto(sock, command, strlen(command), 0, (struct sockaddr *) NULL, 0);

        // Receive response from server
        char response[256];
        recvfrom(sock, response, 256, 0, (struct sockaddr *) NULL, NULL);

        printf("Client %s: %s\n", client->name, response);
    }

    // Free client memory
    free(client);
}

// Function to handle server
void handle_server(int sock) {
    char buffer[256];
    printf("Server started...\n");

    while (1) {
        // Receive request from client
        recvfrom(sock, buffer, 256, 0, (struct sockaddr *) NULL, NULL);

        // Send response to client
        sendto(sock, "Hello, client!", 13, 0, (struct sockaddr *) NULL, 0);

        // Broadcast response to all connected clients
        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *) NULL, 0);
    }
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind server to port
    bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(sock, 3);

    // Accept incoming connection
    int client_sock = accept(sock, (struct sockaddr *) NULL, NULL);

    // Spawn new thread for client
    pthread_t thread;
    pthread_create(&thread, NULL, handle_client, &client_sock);

    // Spawn new thread for server
    pthread_t thread2;
    pthread_create(&thread2, NULL, handle_server, sock);

    // Wait for client and server threads to finish
    pthread_join(thread, NULL);
    pthread_join(thread2, NULL);

    close(sock);
    close(client_sock);

    return 0;
}
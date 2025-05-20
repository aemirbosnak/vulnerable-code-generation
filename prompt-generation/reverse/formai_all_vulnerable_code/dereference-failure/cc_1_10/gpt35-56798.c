//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
/***
An example program demonstrating a client-server application using multi-threading.

Instructions:
1. Run the server before running the client.
2. The server will listen for incoming connections on the specified port.
3. Once the client connects, the server will spawn a new thread to deal with the communication.
4. The server will receive a string from the client, reverse it, and send it back.
5. The client will print out the reversed string received from the server and then terminate the connection.

Author: A Chatbot
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer)); // clear buffer
    read(client_socket, buffer, sizeof(buffer)); // read from client
    printf("Received message from client: %s\n", buffer);
    int len = strlen(buffer);
    for (int i = 0; i < len/2; i++) { // reverse the string
        char temp = buffer[i];
        buffer[i] = buffer[len-i-1];
        buffer[len-i-1] = temp;
    }
    write(client_socket, buffer, sizeof(buffer)); // send reversed string back to client
    printf("Sent message to client: %s\n", buffer);
    close(client_socket); // close connection
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (const struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(server_socket, 3) < 0) { // listen for incoming connections
        perror("Error listening on socket");
        exit(1);
    }
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_address;
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }
        printf("New client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        pthread_t thread;
        int *arg = malloc(sizeof(*arg));
        *arg = client_socket;
        pthread_create(&thread, NULL, handle_client, arg); // spawn new thread to handle client communication
    }

    close(server_socket); // close server socket
    return 0;
}
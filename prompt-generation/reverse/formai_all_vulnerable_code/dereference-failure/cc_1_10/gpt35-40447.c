//FormAI DATASET v1.0 Category: Socket programming ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<errno.h>

#define SERVER_PORT 3000
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    // Socket creation
    int socket_desc;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1) {
        printf("Error creating socket. Error Code : %d \n", errno);
        return 1;
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind socket to port
    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not bind to socket. Error Code : %d \n", errno);
        return 1;
    }

    printf("Socket binded successfully. Listening on port %d \n", SERVER_PORT);

    // Listen for incoming connections
    listen(socket_desc, 1);

    // Accept connection
    int client_socket;
    struct sockaddr_in client_addr;
    int client_size = sizeof(client_addr);

    printf("Waiting for incoming connections...\n");
    client_socket = accept(socket_desc, (struct sockaddr *)&client_addr, (socklen_t *)&client_size);

    if (client_socket < 0)  {
        printf("Error accepting incoming connection. Error Code : %d \n", errno);
        return 1;
    }

    printf("Connection accepted from %s:%d \n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive data from client
    memset(buffer, 0, BUFFER_SIZE);
    int recv_len = recv(client_socket, buffer, BUFFER_SIZE, 0);

    while (recv_len > 0) {
        printf("Received message from client: %s \n", buffer);

        // Echo back to client
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            printf("Error sending message to client. Error Code : %d \n", errno);
            return 1;
        }

        // Receive next message
        memset(buffer, 0, BUFFER_SIZE);
        recv_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
    }

    if (recv_len == 0) {
        printf("Client disconnected. \n");
    } else if (recv_len < 0) {
        printf("Error receiving message from client. Error Code : %d \n", errno);
        return 1;
    }

    // Close sockets
    close(client_socket);
    close(socket_desc);

    return 0;
}
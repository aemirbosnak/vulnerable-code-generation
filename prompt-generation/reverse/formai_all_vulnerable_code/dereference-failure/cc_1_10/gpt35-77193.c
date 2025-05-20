//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LENGTH 2000
#define PORT 8080

void handle_client(int sock);

int main(int argc, char *argv[])
{
    int server_sock, client_sock, c, *new_sock;
    struct sockaddr_in server, client;

    // Create a socket
    server_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (server_sock == -1)
    {
        perror("Failed to create socket");
        exit(1);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to a port
    if( bind(server_sock,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Failed to bind the socket");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_sock , 3);

    // Accept incoming connections
    printf("Server is listening on port %d\n", PORT);
    c = sizeof(struct sockaddr_in);
    while(1)
    {
        client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0)
        {
            perror("Failed to accept incoming connection");
            continue;
        }

        new_sock = malloc(1);
        *new_sock = client_sock;

        handle_client(client_sock);
    }

    return 0;
}

void handle_client(int sock)
{
    int read_size;
    char client_msg[MAX_MSG_LENGTH];

    // Receive message from client
    while ((read_size = recv(sock , client_msg , MAX_MSG_LENGTH , 0)) > 0 )
    {
        // Send the message back to client
        send(sock , client_msg , strlen(client_msg), 0);
    }

    // Check if there was an error during receive
    if(read_size == 0)
    {
        printf("Client disconnected\n");
    }
    else if(read_size == -1)
    {
        perror("Failed to receive message from client");
    }
    close(sock);
}
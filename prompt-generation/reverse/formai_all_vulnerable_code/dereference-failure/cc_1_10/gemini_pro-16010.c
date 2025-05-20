//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// I am the client, let me first try to connect to the server.
int main(int argc, char *argv[])
{
    // I am going to start by checking if I have the right number of arguments.
    if (argc != 3)
    {
        printf("Usage: %s <server IP address> <server port>\n", argv[0]);
        exit(1);
    }

    // Now, I need to create a socket.
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("socket");
        exit(1);
    }

    // I have the socket, now I need to connect to the server.
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("connect");
        exit(1);
    }

    // I am connected to the server, now I can send and receive data.
    char buffer[1024];
    while (1)
    {
        // I am going to start by sending a message to the server.
        printf("Enter a message to send to the server: ");
        fgets(buffer, 1024, stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) == -1)
        {
            perror("send");
            exit(1);
        }

        // Now, I am going to wait for a response from the server.
        if (recv(client_socket, buffer, 1024, 0) == -1)
        {
            perror("recv");
            exit(1);
        }

        // I have received a response from the server, now I am going to print it.
        printf("Received from server: %s", buffer);
    }

    // I am done, now I can close the socket.
    close(client_socket);
    return 0;
}
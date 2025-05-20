//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    int client_socket;
    struct sockaddr_in server_address;
    char buffer[MAXSIZE];
    int num_bytes;

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0)
    {
        perror("Error creating socket");
        return 2;
    }

    // Set server address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error connecting to server");
        return 3;
    }

    // Get input from user and send it to server
    while(1)
    {
        printf("Enter command: ");
        fgets(buffer, MAXSIZE, stdin);
        if(send(client_socket, buffer, strlen(buffer), 0) < 0)
        {
            perror("Error sending message to server");
            break;
        }

        // Receive response from server
        memset(buffer, 0, MAXSIZE);
        if((num_bytes = recv(client_socket, buffer, MAXSIZE, 0)) < 0)
        {
            perror("Error receiving message from server");
            break;
        }
        printf("%s", buffer);
    }

    // Close client socket
    close(client_socket);

    return 0;
}
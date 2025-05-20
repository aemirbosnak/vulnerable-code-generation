//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFSIZE 1024

void* client(void* arg)
{
    int client_socket, n;
    struct sockaddr_in server_addr;
    char buffer[BUFSIZE];
    char* command;

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set server address and port
    memset((char*)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Connection failed");
        exit(1);
    }

    // Send command to server
    while (1)
    {
        printf("Enter command: ");
        fgets(buffer, BUFSIZE, stdin);
        command = strtok(buffer, " ");

        // Send command to server
        n = send(client_socket, command, strlen(command), 0);
        if (n < 0)
        {
            perror("Error sending command");
            exit(1);
        }

        // Receive response from server
        memset(buffer, 0, BUFSIZE);
        n = recv(client_socket, buffer, BUFSIZE, 0);
        if (n < 0)
        {
            perror("Error receiving response");
            exit(1);
        }
        printf("%s\n", buffer);
    }

    // Close client socket
    close(client_socket);
}

int main()
{
    pthread_t thread;
    int status;

    // Create client thread
    if (pthread_create(&thread, NULL, client, NULL)!= 0)
    {
        perror("Error creating thread");
        exit(1);
    }

    // Wait for client thread to finish
    if (pthread_join(thread, &status)!= 0)
    {
        perror("Error joining thread");
        exit(1);
    }

    return 0;
}
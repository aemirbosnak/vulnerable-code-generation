//FormAI DATASET v1.0 Category: Networking ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server_addr;
    char *server_ip;
    unsigned short server_port;
    char message[BUFFER_SIZE];
    char server_reply[BUFFER_SIZE];

    // Check for correct number of arguments
    if (argc != 3)
    {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    // Parse command line arguments for server IP and Port
    server_ip = argv[1];
    server_port = atoi(argv[2]);

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    // Prepare server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection failed\n");
        return 1;
    }

    // Connection successful
    printf("Connected to %s:%u\n", server_ip, server_port);

    // Communication loop
    while (1)
    {
        // Prompt user for message to send
        printf("Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);

        // Send message to server
        if (send(socket_desc, message, strlen(message), 0) < 0)
        {
            printf("Send failed\n");
            return 1;
        }

        // Receive server reply
        memset(server_reply, 0, BUFFER_SIZE);
        if (recv(socket_desc, server_reply, BUFFER_SIZE, 0) < 0)
        {
            printf("Receive failed\n");
            return 1;
        }

        // Print server reply
        printf("Server reply: %s", server_reply);

        // Close connection if user types exit
        if (strcmp(message, "exit\n") == 0)
        {
            printf("Closing connection...");
            close(socket_desc);
            return 0;
        }
    }

    return 0;
}
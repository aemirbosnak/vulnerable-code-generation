//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

void romance(int socket_client, int socket_server);

int main(int argc, char *argv[])
{
    int socket_desc, client_sock, server_sock, c, port;
    struct sockaddr_in server, client;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }
    
    // Set server address and port
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
     
    // Bind socket to address and port
    if (bind(socket_desc,(struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("bind failed");
        return 1;
    }
     
    // Listen for incoming connections
    listen(socket_desc, 3);
     
    // Accept incoming connection
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)))
    {
        pid_t child_pid;
        child_pid = fork();
        
        if (child_pid == -1)
        {
            printf("Fork failed");
            return 1;
        }
        else if (child_pid == 0)
        {
            // Create new socket for server connection
            server_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (server_sock == -1)
            {
                printf("Could not create socket");
                return 1;
            }
            
            // Set server address and port
            port = atoi(argv[1]);
            server.sin_addr.s_addr = inet_addr(argv[2]);
            server.sin_family = AF_INET;
            server.sin_port = htons(port);
            
            // Connect to server
            if (connect(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0)
            {
                printf("Could not connect to server");
                return 1;
            }
            
            // Handle the connection
            romance(client_sock, server_sock);
            
            // Close the sockets
            close(client_sock);
            close(server_sock);
            exit(0);
        }
    }
     
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }

    return 0;
}

void romance(int socket_client, int socket_server)
{
    char client_message[4000], server_message[4000];
    int read_size;
    fd_set fdset;
    int maxfd;
    
    // Loop to handle incoming messages from the client and server
    while (1)
    {
        FD_ZERO(&fdset);
        FD_SET(socket_client, &fdset);
        FD_SET(socket_server, &fdset);
        maxfd = socket_server > socket_client ? socket_server : socket_client;
        
        select(maxfd + 1, &fdset, NULL, NULL, NULL);
        
        if (FD_ISSET(socket_client, &fdset))
        {
            if ((read_size = recv(socket_client, client_message, sizeof(client_message), 0)) > 0)
            {
                send(socket_server, client_message, strlen(client_message), 0);
            }
            else
            {
                break;
            }
        }
        
        if (FD_ISSET(socket_server, &fdset))
        {
            if ((read_size = recv(socket_server, server_message, sizeof(server_message), 0)) > 0)
            {
                send(socket_client, server_message, strlen(server_message), 0);
            }
            else
            {
                break;
            }
        }
    }
}
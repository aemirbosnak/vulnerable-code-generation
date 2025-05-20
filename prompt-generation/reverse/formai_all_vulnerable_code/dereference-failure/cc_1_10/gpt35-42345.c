//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define SERVER_PORT 4444
#define BUFFER_SIZE 1024
#define MAX_PENDING_CONNECTIONS 5

int server_socket_fd;
int client_socket_fd;

void handle_sigint(int sig)
{
    close(server_socket_fd);
    close(client_socket_fd);
    exit(sig);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, handle_sigint);

    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket_fd == -1)
    {
        perror("Error creating server socket");
        exit(1);
    }

    int optval = 1;
    if(setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1)
    {
        perror("Error setting socket options");
        exit(2);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    if(bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error binding server socket");
        exit(3);
    }

    if(listen(server_socket_fd, MAX_PENDING_CONNECTIONS) == -1)
    {
        perror("Error listening on server socket");
        exit(4);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while(1)
    {
        socklen_t client_address_size = sizeof(client_address);
        client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, &client_address_size);
        if(client_socket_fd == -1)
        {
            perror("Error accepting client connection");
            exit(5);
        }

        inet_ntop(AF_INET, &(client_address.sin_addr), buffer, BUFFER_SIZE);
        printf("Client %s connected\n", buffer);

        while(1)
        {
            memset(buffer, 0, BUFFER_SIZE);
            bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);
            if(bytes_received == -1)
            {
                perror("Error receiving data from client");
                exit(6);
            }
            if(bytes_received == 0)
            {
                printf("Client %s disconnected\n", buffer);
                break;
            }

            printf("Received message from client: %s", buffer);

            time_t current_time = time(NULL);
            char* formatted_time = ctime(&current_time);
            if(formatted_time == NULL)
            {
                perror("Error getting formatted time");
                exit(7);
            }

            if(send(client_socket_fd, formatted_time, strlen(formatted_time), 0) == -1)
            {
                perror("Error sending data to client");
                exit(8);
            }
        }
    }

    return 0;
}
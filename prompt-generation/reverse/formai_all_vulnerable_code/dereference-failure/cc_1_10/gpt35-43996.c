//FormAI DATASET v1.0 Category: Networking ; Style: real-life
//This program simulates a simple chat between a server and multiple clients via a TCP connection.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define PORT 8080 //server port number

//the function to handle client connections
void* connection_handler(void*);

int main(int argc, char const *argv[]) 
{
    int server_fd, client_socket, *new_sock;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    //creating the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    //setting address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //binding socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    //listening for clients
    if (listen(server_fd, 3) < 0) 
    {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    //accepting client connections
    while ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))>0) 
    {
        printf("New client connected\n");

        //creating a new thread for each client connection
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_socket;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void*)new_sock) < 0) 
        {
            perror("error: could not create thread");
            return 1;
        }

        //joining the thread
        pthread_join(sniffer_thread, NULL);
    }

    if (client_socket < 0) 
    {
        perror("accept error");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void* connection_handler(void *socket_desc)
{
    //reading client message
    int client_socket = *(int*)socket_desc;
    int valread;
    char buffer[1024] = {0};
    valread = read(client_socket, buffer, 1024);
    printf("Client message: %s\n", buffer);

    //sending message to client
    char *message = "Hello from server";
    send(client_socket, message, strlen(message), 0);

    //cleaning up
    free(socket_desc);
    close(client_socket);

    return 0;
}
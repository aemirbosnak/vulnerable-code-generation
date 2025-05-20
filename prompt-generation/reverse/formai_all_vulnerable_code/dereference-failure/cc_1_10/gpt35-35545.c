//FormAI DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8888

void *handle_client(void *args);

int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t thread_id;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    puts("Server started, waiting for connections...");

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen)))
    {
        puts("Connection accepted");

        if( pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket) < 0)
        {
            perror("could not create thread");
            return 1;
        }

        puts("Handler assigned");
    }

    if (new_socket<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void *handle_client(void *args)
{
    int sock = *(int*)args;
    int read_size;
    char message[500], client_message[500];

    while ((read_size = recv(sock , client_message , 500 , 0)) > 0 )
    {
        client_message[read_size] = '\0';
        printf("%s\n", client_message);

        printf("Enter a message: ");
        fgets(message, 500, stdin);

        if(send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return NULL;
        }

        memset(client_message, 0, strlen(client_message));
        memset(message, 0, strlen(message));
    }

    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    free(args);

    return NULL;
}
//FormAI DATASET v1.0 Category: Chat server ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

void* client_handler(void*);

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage : %s <port_number>\n", argv[0]);
        return 1;
    }

    int server_fd, client_fd, addr_size;
    struct sockaddr_in server_addr, client_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_fd == -1)
    {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        return 1;
    }

    if(listen(server_fd, 5) == -1)
    {
        perror("listen");
        return 1;
    }

    printf("Server running on port %d...\n", atoi(argv[1]));

    while(1)
    {
        addr_size = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);

        if(client_fd == -1)
        {
            perror("accept");
            continue;
        }

        pthread_t thread_id;

        printf("New client connected\n");

        if(pthread_create(&thread_id, NULL, client_handler, (void*)&client_fd) != 0)
        {
            perror("pthread_create");
            close(client_fd);
        }
    }

    return 0;
}

void* client_handler(void* arg)
{
    int client_fd = *(int*)arg;
    char buffer[256];
    int buffer_len;

    while((buffer_len = recv(client_fd, buffer, sizeof(buffer), 0)) > 0)
    {
        buffer[buffer_len] = '\0';
        printf("Message received : %s\n", buffer);
    }

    if(buffer_len == 0)
    {
        printf("Client disconnected\n");
    }

    else
    {
        perror("recv");
    }

    close(client_fd);
    pthread_detach(pthread_self());
    return NULL;
}
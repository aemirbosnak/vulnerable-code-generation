//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: distributed
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <pthread.h> 

#define PORT 8080  
#define BUFFER_SIZE 1024 

struct client_info
{
    int sockfd;
    char *ip;
    int port;
};

pthread_mutex_t lock;  

void *client_handler(void *arg)
{
    struct client_info *client = (struct client_info *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while (1)
    {
        bzero(buffer, BUFFER_SIZE);
        n = recv(client->sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0)
        {
            pthread_mutex_lock(&lock);
            printf("Client disconnected: %s:%d\n", client->ip, client->port);
            pthread_mutex_unlock(&lock);
            break;
        }

        pthread_mutex_lock(&lock);
        printf("Received message: %s\n", buffer);
        pthread_mutex_unlock(&lock);

        // Process the message and send a response back to the client
        char response[] = "Hello, world!";
        n = send(client->sockfd, response, strlen(response), 0);
        if (n < 0)
        {
            perror("Error sending response");
            break;
        }
    }

    close(client->sockfd);
    free(client->ip);
    free(client);
    return NULL;
}

int main()
{
    int sockfd, newsockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    pthread_t tid;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return -1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Error setting socket options");
        return -1;
    }

    // Bind the socket to the specified IP address and port
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        return -1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0)
    {
        perror("Error listening for connections");
        return -1;
    }

    pthread_mutex_init(&lock, NULL);

    while (1)
    {
        // Accept an incoming connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
        {
            perror("Error accepting connection");
            continue;
        }

        // Create a new thread to handle the client
        struct client_info *client = (struct client_info *)malloc(sizeof(struct client_info));
        client->sockfd = newsockfd;
        client->ip = strdup(inet_ntoa(cli_addr.sin_addr));
        client->port = ntohs(cli_addr.sin_port);
        pthread_create(&tid, NULL, client_handler, (void *)client);
    }

    close(sockfd);
    pthread_mutex_destroy(&lock);
    return 0;
}
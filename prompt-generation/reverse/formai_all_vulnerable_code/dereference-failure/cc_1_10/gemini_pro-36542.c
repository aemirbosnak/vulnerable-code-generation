//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

struct client_data {
    int sockfd;
    char *ip_addr;
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *)arg;
    char buffer[1024];
    
    while(1) {
        bzero(buffer, sizeof(buffer));
        read(client->sockfd, buffer, sizeof(buffer));
        
        printf("Received: %s\n", buffer);
        
        if(strcmp(buffer, "exit") == 0) {
            break;
        }
        
        bzero(buffer, sizeof(buffer));
        strcpy(buffer, "Hello from the server!");
        write(client->sockfd, buffer, strlen(buffer));
    }
    
    close(client->sockfd);
    free(client->ip_addr);
    free(client);
    
    return NULL;
}

int main() {
    int serverfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t tid;
    
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    
    if(bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    if(listen(serverfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        client_addr_len = sizeof(client_addr);
        newsockfd = accept(serverfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if(newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        struct client_data *client = (struct client_data *)malloc(sizeof(struct client_data));
        client->sockfd = newsockfd;
        client->ip_addr = inet_ntoa(client_addr.sin_addr);
        
        pthread_create(&tid, NULL, handle_client, (void *)client);
    }
    
    close(serverfd);
    
    return 0;
}
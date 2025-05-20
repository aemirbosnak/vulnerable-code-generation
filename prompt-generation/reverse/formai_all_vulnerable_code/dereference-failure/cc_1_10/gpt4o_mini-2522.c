//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_BUFFER 1024
#define MAX_CLIENTS 10

typedef struct {
    struct sockaddr_in client_addr;
    socklen_t addr_len;
} client_info;

void *handle_client(void *arg) {
    int sockfd = *((int *)arg);
    char buffer[MAX_BUFFER];
    client_info *client = (client_info *)arg;
    
    while(1) {
        memset(buffer, 0, MAX_BUFFER);
        int n = recvfrom(sockfd, buffer, MAX_BUFFER, 0,
                         (struct sockaddr *)&client->client_addr, &client->addr_len);
        if (n < 0) {
            perror("recvfrom error");
            close(sockfd);
            free(client);
            pthread_exit(NULL);
        }
        printf("Client: %s\n", buffer);
        
        // Echo the received message back to the client
        sendto(sockfd, buffer, n, 0, (struct sockaddr *)&client->client_addr, client->addr_len);
    }
    free(client);
    pthread_exit(NULL);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    pthread_t tid;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Chat Server is running on port %d...\n", PORT);

    while (1) {
        client_info *client = malloc(sizeof(client_info));
        client->addr_len = sizeof(client->client_addr);
        
        // Receive a message from the client
        int n = recvfrom(sockfd, NULL, 0, MSG_PEEK, 
                         (struct sockaddr *)&client->client_addr, &client->addr_len);
        if (n < 0) {
            perror("recvfrom error");
            free(client);
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client->client_addr.sin_addr), ntohs(client->client_addr.sin_port));
        pthread_create(&tid, NULL, handle_client, (void *)client);
        pthread_detach(tid);
    }
    
    close(sockfd);
    return 0;
}
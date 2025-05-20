//Falcon-180B DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in address;
    char name[20];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_sockfd = *(int *) arg;
    char buffer[BUFFER_SIZE];

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE, 0);

        if(bytes_received <= 0) {
            close(client_sockfd);
            pthread_exit(0);
        }

        printf("%s: %s\n", clients[client_sockfd].name, buffer);

        for(int i = 0; i < num_clients; i++) {
            if(i!= client_sockfd) {
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            }
        }
    }
}

int main() {
    int server_sockfd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if(bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 12345\n");

    while(1) {
        if((new_socket = accept(server_sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        clients[num_clients].sockfd = new_socket;
        strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
        printf("New client connected: %s\n", clients[num_clients].name);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket);

        num_clients++;
    }

    return 0;
}
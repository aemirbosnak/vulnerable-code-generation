//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

void *client_handler(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    struct timespec start, end;

    while (1) {
        bytes_read = recv(cli->socket, buffer, sizeof(buffer), 0);
        if (bytes_read <= 0) break;

        clock_gettime(CLOCK_MONOTONIC, &start);
        // Simulate processing delay
        usleep(rand() % 200000); // Random delay between 0 to 200ms
        clock_gettime(CLOCK_MONOTONIC, &end);

        long latency = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
        printf("Client %d: Received packet from %s:%d, Latency: %ld ms\n", cli->socket, 
               inet_ntoa(cli->address.sin_addr), ntohs(cli->address.sin_port), latency);
        
        // Simulating packet loss
        if (rand() % 10 < 1) {
            printf("Client %d: Packet Loss\n", cli->socket);
        }

        send(cli->socket, buffer, bytes_read, 0);
    }

    close(cli->socket);
    free(cli);
    return NULL;
}

int main() {
    srand(time(NULL));
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind Failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen Failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d\n", PORT);

    while (1) {
        socklen_t cli_len = sizeof(client_addr);
        int client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &cli_len);
        if (client_socket < 0) {
            perror("Connection Failed");
            continue;
        }

        printf("Connected to client: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        client_t *cli = malloc(sizeof(client_t));
        cli->socket = client_socket;
        cli->address = client_addr;

        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, cli) != 0) {
            perror("Failed to create thread");
            close(client_socket);
            free(cli);
            continue;
        }
    }

    close(server_fd);
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int len;

    while ((len = recv(client->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[len] = '\0';
        printf("Message from %s:%d: %s\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port), buffer);
        // Broadcast message to other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->sockfd != client->sockfd) {
                send(clients[i]->sockfd, buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(client->sockfd);
    free(client);
    return NULL;
}

void *client_listener(void *arg) {
    int client_sock = *(int *)arg;
    char name[BUFFER_SIZE];
    
    // Prompt for name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    while (1) {
        char msg[BUFFER_SIZE];
        printf("%s: ", name);
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0; // Remove newline
        send(client_sock, msg, strlen(msg), 0);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <port> <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    char *server_ip = argv[2];
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(port);
    
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on %s:%d\n", server_ip, port);

    while ((client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_len))) {
        printf("New connection: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        client_t *new_client = malloc(sizeof(client_t));
        new_client->sockfd = client_sock;
        new_client->addr = client_addr;

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = new_client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, new_client);
        
        // Start client listener for this new socket
        pthread_create(&thread, NULL, client_listener, &client_sock);
        pthread_detach(thread);
    }

    close(server_sock);
    return 0;
}
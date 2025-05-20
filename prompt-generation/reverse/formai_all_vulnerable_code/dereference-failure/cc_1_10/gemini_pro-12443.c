//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define MAX_MSG_SIZE 1024

typedef struct client_info {
    int sockfd;
    char username[32];
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;
    int sockfd = client->sockfd;

    char buffer[MAX_MSG_SIZE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));

        int recv_len = recv(sockfd, buffer, sizeof(buffer), 0);
        if (recv_len <= 0) {
            printf("Client %s disconnected\n", client->username);
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].sockfd == sockfd) {
                    memmove(&clients[i], &clients[i + 1], sizeof(client_info) * (num_clients - i - 1));
                    num_clients--;
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            break;
        }

        char *msg = buffer;
        char *sender = client->username;

        printf("Received message from %s: %s\n", sender, msg);

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].sockfd != sockfd) {
                send(clients[i].sockfd, msg, strlen(msg), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(sockfd);
    pthread_exit(NULL);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int bind_status = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_status == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    int listen_status = listen(sockfd, MAX_CLIENTS);
    if (listen_status == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_sockfd == -1) {
            perror("accept");
            continue;
        }

        char *client_ip = inet_ntoa(client_addr.sin_addr);
        printf("New client connected from %s\n", client_ip);

        pthread_t client_thread;
        client_info *new_client = malloc(sizeof(client_info));
        new_client->sockfd = new_sockfd;

        printf("Enter your username: ");
        scanf("%s", new_client->username);

        pthread_mutex_lock(&clients_mutex);
        clients[num_clients++] = *new_client;
        pthread_mutex_unlock(&clients_mutex);

        pthread_create(&client_thread, NULL, handle_client, (void *)new_client);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}
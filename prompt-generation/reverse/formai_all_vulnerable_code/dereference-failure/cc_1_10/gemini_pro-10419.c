//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 5000
#define MAX_CLIENTS 10

struct client {
    int sockfd;
    char username[50];
};

struct warehouse {
    int num_items;
    char items[100][50];
};

struct warehouse warehouse;

pthread_mutex_t lock;

void *client_handler(void *arg) {
    struct client *client = (struct client *)arg;
    char buffer[1024];
    int n;

    while ((n = recv(client->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        pthread_mutex_lock(&lock);
        if (strcmp(buffer, "list") == 0) {
            char list[1024] = "Items in the warehouse:\n";
            for (int i = 0; i < warehouse.num_items; i++) {
                strcat(list, warehouse.items[i]);
                strcat(list, "\n");
            }
            send(client->sockfd, list, strlen(list), 0);
        } else if (strcmp(buffer, "add") == 0) {
            char item[50];
            recv(client->sockfd, item, sizeof(item), 0);
            strcpy(warehouse.items[warehouse.num_items], item);
            warehouse.num_items++;
            send(client->sockfd, "Item added successfully", 25, 0);
        } else if (strcmp(buffer, "remove") == 0) {
            char item[50];
            recv(client->sockfd, item, sizeof(item), 0);
            int found = 0;
            for (int i = 0; i < warehouse.num_items; i++) {
                if (strcmp(warehouse.items[i], item) == 0) {
                    found = 1;
                    for (int j = i; j < warehouse.num_items - 1; j++) {
                        strcpy(warehouse.items[j], warehouse.items[j + 1]);
                    }
                    warehouse.num_items--;
                    break;
                }
            }
            if (found) {
                send(client->sockfd, "Item removed successfully", 25, 0);
            } else {
                send(client->sockfd, "Item not found", 13, 0);
            }
        } else if (strcmp(buffer, "quit") == 0) {
            close(client->sockfd);
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL);
        }
        pthread_mutex_unlock(&lock);
    }
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    int sockfd, newsockfd, client_len;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[MAX_CLIENTS];
    int num_clients = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    while (num_clients < MAX_CLIENTS) {
        client_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        struct client *client = (struct client *)malloc(sizeof(struct client));
        client->sockfd = newsockfd;
        strcpy(client->username, inet_ntoa(client_addr.sin_addr));

        pthread_create(&threads[num_clients], NULL, client_handler, (void *)client);

        num_clients++;
    }

    for (int i = 0; i < num_clients; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);

    return 0;
}
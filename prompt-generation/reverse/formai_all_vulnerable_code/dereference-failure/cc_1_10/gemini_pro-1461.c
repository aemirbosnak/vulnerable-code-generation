//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LEN 1024

struct client_info {
    int sockfd;
    char username[32];
    pthread_t thread_id;
};

struct client_info clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_lock;

void send_message(int sockfd, char *msg) {
    int len = strlen(msg);
    if (send(sockfd, &len, sizeof(len), 0) < 0) {
        perror("send");
        exit(1);
    }
    if (send(sockfd, msg, len, 0) < 0) {
        perror("send");
        exit(1);
    }
}

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;

    char msg[MAX_MSG_LEN];
    while (1) {
        int len;
        if (recv(client->sockfd, &len, sizeof(len), 0) <= 0) {
            pthread_mutex_lock(&client_lock);
            clients[client_count--] = clients[client_count];
            pthread_mutex_unlock(&client_lock);
            break;
        }
        if (recv(client->sockfd, msg, len, 0) <= 0) {
            pthread_mutex_lock(&client_lock);
            clients[client_count--] = clients[client_count];
            pthread_mutex_unlock(&client_lock);
            break;
        }

        printf("%s: %s\n", client->username, msg);

        pthread_mutex_lock(&client_lock);
        for (int i = 0; i < client_count; i++) {
            if (clients[i].sockfd != client->sockfd) {
                char buf[MAX_MSG_LEN];
                sprintf(buf, "%s: %s", client->username, msg);
                send_message(clients[i].sockfd, buf);
            }
        }
        pthread_mutex_unlock(&client_lock);
    }

    close(client->sockfd);
    return NULL;
}

int main() {
    pthread_mutex_init(&client_lock, NULL);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5000);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port 5000...\n");

    while (1) {
        struct sockaddr_in clientaddr;
        socklen_t len = sizeof(clientaddr);

        int connfd = accept(sockfd, (struct sockaddr *)&clientaddr, &len);
        if (connfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

        pthread_mutex_lock(&client_lock);
        if (client_count == MAX_CLIENTS) {
            char *msg = "Server is full. Please try again later.\n";
            send_message(connfd, msg);
            close(connfd);
            continue;
        }

        char username[32];
        if (recv(connfd, username, sizeof(username), 0) <= 0) {
            pthread_mutex_lock(&client_lock);
            clients[client_count--] = clients[client_count];
            pthread_mutex_unlock(&client_lock);
            close(connfd);
            continue;
        }

        struct client_info client;
        client.sockfd = connfd;
        strcpy(client.username, username);

        clients[client_count++] = client;
        pthread_mutex_unlock(&client_lock);

        pthread_create(&client.thread_id, NULL, handle_client, &client);
    }

    close(sockfd);
    return 0;
}
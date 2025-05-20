//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFF_SIZE 1024

struct config {
    int port;
    int max_clients;
    int backlog;
};

struct client {
    int sockfd;
    char *name;
};

void handle_client(struct client *client) {
    char buff[BUFF_SIZE];
    while (1) {
        int recv_size = recv(client->sockfd, buff, BUFF_SIZE, 0);
        if (recv_size == -1) {
            perror("recv");
            break;
        }
        if (recv_size == 0) {
            printf("Client %s disconnected\n", client->name);
            break;
        }
        buff[recv_size] = '\0';
        printf("Client %s: %s\n", client->name, buff);
        if (strcmp(buff, "exit") == 0) {
            break;
        }
        int send_size = send(client->sockfd, buff, strlen(buff), 0);
        if (send_size == -1) {
            perror("send");
            break;
        }
    }
    close(client->sockfd);
    free(client->name);
    free(client);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <config file>\n", argv[0]);
        return 1;
    }

    struct config config;
    FILE *config_file = fopen(argv[1], "r");
    if (config_file == NULL) {
        perror("fopen");
        return 1;
    }
    fscanf(config_file, "port: %d\n", &config.port);
    fscanf(config_file, "max_clients: %d\n", &config.max_clients);
    fscanf(config_file, "backlog: %d\n", &config.backlog);
    fclose(config_file);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(config.port);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, config.backlog) == -1) {
        perror("listen");
        return 1;
    }

    struct client *clients[config.max_clients];
    int num_clients = 0;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        if (num_clients >= config.max_clients) {
            printf("Max clients reached\n");
            close(client_sockfd);
            continue;
        }

        char *client_name = malloc(BUFF_SIZE);
        int recv_size = recv(client_sockfd, client_name, BUFF_SIZE, 0);
        if (recv_size == -1) {
            perror("recv");
            close(client_sockfd);
            continue;
        }
        if (recv_size == 0) {
            printf("Client disconnected\n");
            close(client_sockfd);
            continue;
        }
        client_name[recv_size] = '\0';

        struct client *client = malloc(sizeof(struct client));
        client->sockfd = client_sockfd;
        client->name = client_name;

        clients[num_clients] = client;
        num_clients++;
        printf("Client %s connected\n", client->name);
        handle_client(client);
    }

    close(sockfd);
    return 0;
}
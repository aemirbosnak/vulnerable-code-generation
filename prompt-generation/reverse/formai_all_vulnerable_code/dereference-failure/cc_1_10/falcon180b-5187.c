//Falcon-180B DATASET v1.0 Category: Networking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

struct client {
    int sock;
    char ip[16];
    char port[6];
};

void *handle_client(void *arg) {
    struct client *client = arg;
    char buffer[1024];
    while (1) {
        memset(buffer, 0, 1024);
        int n = recv(client->sock, buffer, 1024, 0);
        if (n <= 0) break;
        printf("%s:%s - %s\n", client->ip, client->port, buffer);
        send(client->sock, buffer, strlen(buffer), 0);
    }
    close(client->sock);
    free(client);
    return NULL;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8080);
    if (bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 2;
    }
    if (listen(sock, 10) < 0) {
        perror("listen");
        return 3;
    }
    while (1) {
        struct sockaddr_in cli_addr;
        socklen_t clilen = sizeof(cli_addr);
        int clisock = accept(sock, (struct sockaddr*)&cli_addr, &clilen);
        if (clisock == -1) {
            perror("accept");
            continue;
        }
        char ip[16];
        inet_ntop(AF_INET, &cli_addr.sin_addr, ip, 16);
        char port[6];
        sprintf(port, "%d", ntohs(cli_addr.sin_port));
        struct client *client = malloc(sizeof(struct client));
        client->sock = clisock;
        strcpy(client->ip, ip);
        strcpy(client->port, port);
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, client);
        pthread_detach(thread);
    }
    close(sock);
    return 0;
}
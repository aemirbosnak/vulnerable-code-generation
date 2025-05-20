//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_NODES 10
#define MAX_THREADS 10
#define MAX_BUF_SIZE 1024

typedef struct {
    int id;
    char ip[16];
    int port;
    int status;
} Node;

Node nodes[MAX_NODES];

void *listen_thread(void *arg) {
    int sock = *(int *)arg;
    char buf[MAX_BUF_SIZE];

    while (1) {
        memset(buf, 0, MAX_BUF_SIZE);
        int len = recv(sock, buf, MAX_BUF_SIZE, 0);

        if (len <= 0) {
            break;
        }

        char *token = strtok(buf, " ");
        int node_id = atoi(token);

        for (int i = 0; i < MAX_NODES; i++) {
            if (nodes[i].id == node_id) {
                nodes[i].status = 1;
                break;
            }
        }
    }

    close(sock);
    pthread_exit(0);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 10);

    puts("Server started on port 8080");

    int client_sock;
    while ((client_sock = accept(server_sock, NULL, NULL))!= -1) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, listen_thread, &client_sock);
    }

    return 0;
}
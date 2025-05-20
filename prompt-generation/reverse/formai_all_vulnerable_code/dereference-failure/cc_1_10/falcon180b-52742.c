//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE   1
#define FALSE  0
#define MAX 1000

int g_socket = -1;
int g_port = 8080;
char g_ip[16] = "127.0.0.1";
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_func(void* arg);

int main()
{
    int ret;
    int opt = 1;
    struct sockaddr_in server_addr;
    pthread_t tid;

    ret = setsockopt(g_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
    if (ret < 0) {
        printf("setsockopt error\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(g_port);
    inet_pton(AF_INET, g_ip, &server_addr.sin_addr);

    ret = bind(g_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        printf("bind error\n");
        exit(1);
    }

    ret = listen(g_socket, 5);
    if (ret < 0) {
        printf("listen error\n");
        exit(1);
    }

    while (TRUE) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_socket = accept(g_socket, (struct sockaddr*)&client_addr, &addr_len);

        if (client_socket < 0) {
            printf("accept error\n");
            continue;
        }

        pthread_create(&tid, NULL, thread_func, (void*)client_socket);
        pthread_detach(tid);
    }

    close(g_socket);
    return 0;
}

void* thread_func(void* arg)
{
    int client_socket = *((int*)arg);
    char buffer[MAX];

    while (TRUE) {
        memset(buffer, 0, MAX);
        int ret = recv(client_socket, buffer, MAX, 0);

        if (ret <= 0) {
            break;
        }

        printf("Client: %s\n", buffer);

        pthread_mutex_lock(&g_mutex);
        printf("Server: %s\n", buffer);
        pthread_mutex_unlock(&g_mutex);
    }

    close(client_socket);
    return NULL;
}
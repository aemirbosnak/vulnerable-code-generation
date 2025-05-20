//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define MAX_THREADS 10
#define BUFFER_SIZE 1024

struct thread_data {
    int sock;
    char ip[16];
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(data->sock, buffer, BUFFER_SIZE, 0);

        if(bytes_received <= 0) {
            break;
        }

        printf("Received %d bytes from %s\n", bytes_received, data->ip);
    }

    close(data->sock);
    free(data);
    return NULL;
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr;
    int opt = 1;
    int thread_id;
    pthread_t threads[MAX_THREADS];

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if(server_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if(bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if(listen(server_sock, MAX_THREADS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", SERVER_PORT);

    while(1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);

        if(client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char ip[16];
        inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));

        printf("Connection from %s\n", ip);

        struct thread_data *data = (struct thread_data *)malloc(sizeof(struct thread_data));
        data->sock = client_sock;
        strcpy(data->ip, ip);

        if(pthread_create(&threads[thread_id], NULL, thread_func, data)!= 0) {
            printf("Error creating thread\n");
            close(client_sock);
            free(data);
        } else {
            thread_id++;
        }
    }

    return 0;
}
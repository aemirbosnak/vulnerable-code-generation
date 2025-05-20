//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

// Function prototypes
int create_socket(int port);
void *thread_func(void *arg);

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_socket = create_socket(atoi(argv[1]));

    while (TRUE) {
        socklen_t client_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_create(&thread_id, NULL, thread_func, (void *)client_socket);
    }

    close(listen_socket);
    return 0;
}

int create_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Bind failed\n");
        exit(1);
    }

    listen(sockfd, 5);
    return sockfd;
}

void *thread_func(void *arg) {
    int client_socket = *((int *) arg);
    char buffer[BUF_SIZE];

    while (TRUE) {
        bzero(buffer, BUF_SIZE);
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            break;
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);
    pthread_exit(0);
}
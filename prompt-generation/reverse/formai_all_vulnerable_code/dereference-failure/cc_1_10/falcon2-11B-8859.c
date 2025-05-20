//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

int server_socket;
int client_socket;
pthread_t client_thread[5];

void* client_handler(void* client_socket) {
    int client_socket_arg = *(int*)client_socket;
    int client_socket_fd = client_socket_arg;

    char buffer[1024];
    char message[1024];
    int message_len;

    while (1) {
        message_len = recv(client_socket_fd, buffer, sizeof(buffer), 0);

        if (message_len <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        printf("%s\n", buffer);

        if (strcmp(buffer, "/quit") == 0) {
            send(client_socket_fd, "Bye!", sizeof("Bye!"), 0);
            break;
        }

        strcpy(message, "Hello, ");
        strcat(message, buffer);
        strcat(message, "!\n");

        send(client_socket_fd, message, strlen(message), 0);
    }

    close(client_socket_fd);

    return NULL;
}

void* broadcast_handler(void* message) {
    char* message_arg = *(char**)message;
    int message_len = strlen(message_arg);

    int broadcast_fd = 0;
    int broadcast_socket = 0;

    broadcast_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (broadcast_socket == -1) {
        perror("Socket creation failed.");
        exit(1);
    }

    struct sockaddr_in broadcast_addr;
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(7000);
    broadcast_addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    int broadcast_socket_arg = *(int*)message;
    broadcast_socket_arg = broadcast_socket;

    if (bind(broadcast_socket, (struct sockaddr*)&broadcast_addr, sizeof(broadcast_addr)) == -1) {
        perror("Bind failed.");
        exit(1);
    }

    if (listen(broadcast_socket, 5) == -1) {
        perror("Listen failed.");
        exit(1);
    }

    while (1) {
        int broadcast_client_socket = 0;
        broadcast_client_socket = accept(broadcast_socket, NULL, NULL);

        if (broadcast_client_socket == -1) {
            perror("Accept failed.");
            exit(1);
        }

        int broadcast_client_socket_arg = *(int*)message;
        broadcast_client_socket_arg = broadcast_client_socket;

        send(broadcast_client_socket_arg, message, message_len, 0);
    }

    close(broadcast_socket);

    return NULL;
}

void* server_handler() {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed.");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(7000);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed.");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("Listen failed.");
        exit(1);
    }

    while (1) {
        int client_socket = 0;
        client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            perror("Accept failed.");
            exit(1);
        }

        pthread_t client_thread;
        pthread_create(&client_thread, NULL, client_handler, (void*)&client_socket);
        pthread_detach(client_thread);
    }

    close(server_socket);

    return NULL;
}

void* broadcast_handler2(void* message) {
    char* message_arg = *(char**)message;
    int message_len = strlen(message_arg);

    int broadcast_fd = 0;
    int broadcast_socket = 0;

    broadcast_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (broadcast_socket == -1) {
        perror("Socket creation failed.");
        exit(1);
    }

    struct sockaddr_in broadcast_addr;
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(7000);
    broadcast_addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    int broadcast_socket_arg = *(int*)message;
    broadcast_socket_arg = broadcast_socket;

    if (bind(broadcast_socket, (struct sockaddr*)&broadcast_addr, sizeof(broadcast_addr)) == -1) {
        perror("Bind failed.");
        exit(1);
    }

    if (listen(broadcast_socket, 5) == -1) {
        perror("Listen failed.");
        exit(1);
    }

    while (1) {
        int broadcast_client_socket = 0;
        broadcast_client_socket = accept(broadcast_socket, NULL, NULL);

        if (broadcast_client_socket == -1) {
            perror("Accept failed.");
            exit(1);
        }

        int broadcast_client_socket_arg = *(int*)message;
        broadcast_client_socket_arg = broadcast_client_socket;

        send(broadcast_client_socket_arg, message, message_len, 0);
    }

    close(broadcast_socket);

    return NULL;
}

int main() {
    signal(SIGPIPE, SIG_IGN);

    pthread_t server_thread;
    pthread_create(&server_thread, NULL, server_handler, NULL);

    int server_thread_arg = *(int*)server_thread;
    int server_thread_arg2 = *(int*)server_thread;

    pthread_t broadcast_thread;
    pthread_create(&broadcast_thread, NULL, broadcast_handler2, (void*)&server_thread_arg2);

    int broadcast_thread_arg = *(int*)broadcast_thread;
    int broadcast_thread_arg2 = *(int*)broadcast_thread;

    pthread_join(server_thread, NULL);
    pthread_join(broadcast_thread, NULL);

    return 0;
}
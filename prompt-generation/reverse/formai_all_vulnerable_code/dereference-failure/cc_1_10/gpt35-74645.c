//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LEN 1024

void *client_thread(void *args);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./ftp_client <server_ip> <server_port>\n");
        exit(EXIT_FAILURE);
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Invalid server IP address");
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    pthread_t thread;
    if (pthread_create(&thread, NULL, client_thread, (void *) &client_socket) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread, NULL);

    close(client_socket);
    return 0;
}

void *client_thread(void *args) {
    int client_socket = *(int *) args;
    char message[MAX_LEN];

    while (true) {
        printf(">> ");
        fgets(message, MAX_LEN, stdin);

        if (strcmp(message, "quit\n") == 0) {
            printf("Closing connection...\n");
            break;
        }

        if (send(client_socket, message, strlen(message), 0) < 0) {
            perror("Failed to send message to server");
            exit(EXIT_FAILURE);
        }

        printf("Waiting for response...\n");

        char response[MAX_LEN];
        int bytes_recv = recv(client_socket, response, MAX_LEN, 0);
        response[bytes_recv] = '\0';

        printf("Response: %s\n", response);
    }

    return NULL;
}
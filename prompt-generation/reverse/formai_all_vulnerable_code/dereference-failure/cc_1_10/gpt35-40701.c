//FormAI DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PACKET_SIZE 65535

int tcp_socket;

void *forward(void *p) {
    int client_socket = *(int *)p;
    char *buffer = malloc(MAX_PACKET_SIZE);
    if (buffer == NULL) {
        close(client_socket);
        return NULL;
    }
    while (1) {
        int n = read(client_socket, buffer, MAX_PACKET_SIZE);
        if (n <= 0) break;
        write(tcp_socket, buffer, n);
    }
    free(buffer);
    close(client_socket);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <listen port> <forwarding port> <destination IP>\n", argv[0]);
        return 1;
    }

    int listen_port = atoi(argv[1]);
    int forwarding_port = atoi(argv[2]);
    char *ip = argv[3];

    struct sockaddr_in listen_address;
    memset(&listen_address, 0, sizeof(listen_address));
    listen_address.sin_family = AF_INET;
    listen_address.sin_port = htons(listen_port);
    listen_address.sin_addr.s_addr = INADDR_ANY;

    tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket < 0) {
        printf("Unable to create socket\n");
        return 1;
    }

    if (bind(tcp_socket, (struct sockaddr *)&listen_address, sizeof(listen_address)) < 0) {
        printf("Unable to bind socket\n");
        close(tcp_socket);
        return 1;
    }

    if (listen(tcp_socket, 10) < 0) {
        printf("Unable to listen on socket\n");
        close(tcp_socket);
        return 1;
    }

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(tcp_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            printf("Unable to accept socket\n");
            continue;
        }

        pthread_t thread;
        if (pthread_create(&thread, NULL, forward, &client_socket) != 0) {
            printf("Unable to create thread\n");
            close(client_socket);
            continue;
        }

        struct sockaddr_in forwarding_address;
        memset(&forwarding_address, 0, sizeof(forwarding_address));
        forwarding_address.sin_family = AF_INET;
        forwarding_address.sin_port = htons(forwarding_port);
        inet_aton(ip, &forwarding_address.sin_addr);

        int forwarding_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (forwarding_socket < 0) {
            printf("Unable to create socket\n");
            close(client_socket);
            continue;
        }

        if (connect(forwarding_socket, (struct sockaddr *)&forwarding_address, sizeof(forwarding_address)) < 0) {
            printf("Unable to connect to forwarding destination\n");
            close(forwarding_socket);
            close(client_socket);
            continue;
        }

        char *buffer = malloc(MAX_PACKET_SIZE);
        if (buffer == NULL) {
            close(forwarding_socket);
            close(client_socket);
            continue;
        }
        while (1) {
            int n = read(forwarding_socket, buffer, MAX_PACKET_SIZE);
            if (n <= 0) break;
            write(client_socket, buffer, n);
        }
        free(buffer);
        close(forwarding_socket);
    }

    close(tcp_socket);
    return 0;
}
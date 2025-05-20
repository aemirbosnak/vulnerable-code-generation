//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 10
#define BUFF_SIZE 1024

int clients_socket[MAX_CLIENTS];
int clients_count = 0;
int main_socket;
int max_socket;

void *thread_client(void *arg);

int main(int argc, char *argv[]) {
    int opt = TRUE;
    int addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFF_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    main_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (main_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    setsockopt(main_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    bind(main_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(main_socket, MAX_CLIENTS);

    printf("Server is listening on port %d\n", atoi(argv[1]));

    while (TRUE) {
        addrlen = sizeof(client_addr);
        clients_socket[clients_count] = accept(main_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (clients_socket[clients_count] == -1) {
            perror("accept");
        } else {
            printf("Client connected with IP %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, thread_client, (void *)&clients_socket[clients_count]);
            clients_count++;
        }
    }

    return 0;
}

void *thread_client(void *arg) {
    int client_socket = *((int *) arg);
    char buffer[BUFF_SIZE];

    while (TRUE) {
        bzero(buffer, BUFF_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFF_SIZE, 0);
        if (bytes_received <= 0) {
            if (bytes_received == 0) {
                printf("Client disconnected\n");
            } else {
                printf("Error receiving data from client\n");
            }
            close(client_socket);
            pthread_exit(0);
        }

        printf("Received message from client: %s", buffer);

        for (int i = 0; i < clients_count; i++) {
            if (clients_socket[i]!= client_socket) {
                send(clients_socket[i], buffer, strlen(buffer), 0);
            }
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <pthread.h>

#define MAX_LINE 1024
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8000

int server_socket;
int client_sockets[MAX_CLIENTS];
int clients_count;

void *handle_client(void *socket_desc);

int main() {
    int opt = 1;
    int master_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    addrlen = sizeof(client_addr);
    while (1) {
        memset(&client_addr, 0, sizeof(client_addr));
        if ((client_sockets[clients_count] = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        printf("Connection accepted from: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)client_sockets[clients_count])!= 0) {
            printf("Error creating thread: %s\n", strerror(errno));
            close(client_sockets[clients_count]);
            clients_count--;
            continue;
        }
        clients_count++;
        printf("Total clients connected: %d\n", clients_count);
    }
    return 0;
}

void *handle_client(void *socket_desc) {
    int sock = *((int*)socket_desc);
    char buffer[MAX_LINE];
    while (1) {
        memset(buffer, 0, MAX_LINE);
        if (recv(sock, buffer, MAX_LINE, 0) <= 0) {
            printf("Client disconnected\n");
            close(sock);
            pthread_exit(NULL);
        }
        send(sock, buffer, strlen(buffer), 0);
    }
}
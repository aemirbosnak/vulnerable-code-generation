//Falcon-180B DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>

#define MAX_LINE 1024
#define MAX_CLIENTS 10
#define PORT 8080

int client_sockets[MAX_CLIENTS];
int num_clients = 0;
int max_clients = MAX_CLIENTS;

void *handle_client(void *client_socket) {
    char buffer[MAX_LINE];
    while (fgets(buffer, MAX_LINE, (FILE *)client_socket)!= NULL) {
        printf("%s", buffer);
    }
    close((int)client_socket);
    return NULL;
}

void sig_handler(int signum) {
    printf("Signal %d received\n", signum);
    for (int i = 0; i < num_clients; i++) {
        close(client_sockets[i]);
    }
    exit(0);
}

int main() {
    signal(SIGINT, sig_handler);
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, max_clients);

    printf("Server started on port %d\n", PORT);

    while (num_clients < max_clients) {
        int client_socket = accept(server_socket, NULL, NULL);
        printf("Client connected\n");
        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    while (1) {
        sleep(1);
    }

    return 0;
}
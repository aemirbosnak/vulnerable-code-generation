//Falcon-180B DATASET v1.0 Category: Firewall ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define WHITE_LIST_FILE "whitelist.txt"

int clients[MAX_CLIENTS];
int num_clients = 0;

struct sockaddr_in server_addr;
int server_sock;

void *handle_client(void *client_socket) {
    int client_sock = *(int *) client_socket;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        char *whitelist_file = fopen(WHITE_LIST_FILE, "r");
        char whitelist_line[BUFFER_SIZE];

        while (fgets(whitelist_line, BUFFER_SIZE, whitelist_file)!= NULL) {
            if (strstr(buffer, whitelist_line)!= NULL) {
                send(client_sock, "ALLOWED\n", 8, 0);
            }
        }

        fclose(whitelist_file);
    }

    close(client_sock);
}

void accept_connections() {
    while (1) {
        int client_sock = accept(server_sock, (struct sockaddr *) NULL, NULL);

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "SERVER FULL\n", 11, 0);
            close(client_sock);
        } else {
            clients[num_clients] = client_sock;
            num_clients++;

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) &clients[num_clients - 1]);
        }
    }
}

int main() {
    int opt = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(server_sock, 3);

    printf("Firewall started on port %d\n", PORT);

    accept_connections();

    return 0;
}
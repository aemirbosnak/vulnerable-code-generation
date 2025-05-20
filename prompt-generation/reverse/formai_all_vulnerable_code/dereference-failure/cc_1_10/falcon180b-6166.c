//Falcon-180B DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char name[20];
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *) arg;
    char buffer[BUFFER_SIZE];

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);

        if(bytes_received <= 0) {
            printf("Client disconnected: %s\n", client->name);
            close(client->sock);
            exit(0);
        }

        send(client->sock, buffer, bytes_received, 0);
    }
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    pthread_t thread_id;
    struct client_data clients[MAX_CLIENTS];

    memset(clients, 0, sizeof(clients));

    if((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if(listen(server_sock, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while(1) {
        if((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(clients[i].sock == 0) {
                strcpy(clients[i].name, inet_ntoa(client_addr.sin_addr));
                clients[i].sock = client_sock;
                pthread_create(&thread_id, NULL, handle_client, (void *)&clients[i]);
                break;
            }
        }
    }

    return 0;
}
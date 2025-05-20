//Falcon-180B DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket_desc) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    while(1) {
        int bytes_received = recv(*((int *)socket_desc), buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client %d sent message: %s\n", *((int *)socket_desc), buffer);

        char message[BUFFER_SIZE];
        strcpy(message, buffer);

        for(int i = 0; i < num_clients; i++) {
            if(i!= *((int *)socket_desc)) {
                send(clients[i], message, strlen(message), 0);
            }
        }
    }

    close(*((int *)socket_desc));
    free(socket_desc);

    printf("Client %d disconnected\n", *((int *)socket_desc));

    if(num_clients > 0) {
        printf("There are still %d clients connected\n", num_clients);
    } else {
        printf("No more clients connected\n");
    }
}

void accept_connections(int server_socket) {
    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if(client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client connected\n");

        if(num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", 51, 0);
            close(client_socket);
            continue;
        }

        clients[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&clients[num_clients - 1]);
    }
}

int main() {
    int server_socket, opt = 1;
    struct sockaddr_in server_addr;

    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, (char *)&opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if(listen(server_socket, 3) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port 8080\n");

    accept_connections(server_socket);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

struct client_info {
    int sock;
    struct sockaddr_in address;
    char name[20];
};

void* thread_client(void* arg) {
    struct client_info* client = (struct client_info*) arg;
    char buffer[1024];
    int n;

    while ((n = recv(client->sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Client %s said: %s\n", client->name, buffer);
    }

    close(client->sock);
    free(client);
    return NULL;
}

int main() {
    int master_socket, new_socket, client_socket[10], max_clients = 10, activity, valread, sd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    struct client_info clients[10];

    printf("Happy TCP/IP Server is listening on port %d\n", PORT);

    // create socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&activity, sizeof(activity))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // fill server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind to address and port
    if (bind(master_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(master_socket, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is ready to accept connections\n");

    while(1) {
        // accept a connection
        if ((new_socket = accept(master_socket, (struct sockaddr*)&client_addr, (socklen_t*)&valread)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // get client's name
        strcpy(clients[0].name, inet_ntoa(client_addr.sin_addr));
        clients[0].sock = new_socket;
        clients[0].address = client_addr;

        // create thread for each client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, thread_client, (void*)&clients[0])!= 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
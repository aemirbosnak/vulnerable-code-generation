//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    struct sockaddr_in addr;
    int is_connected;
};

void *handle_client(void *arg) {
    struct client_data *client_data = (struct client_data *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_data->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(client_data->sock);
            client_data->is_connected = 0;
            break;
        }

        printf("Client %s sent: %s\n", inet_ntoa(client_data->addr.sin_addr), buffer);
    }

    return NULL;
}

void accept_connections(int server_sock) {
    struct sockaddr_in client_addr;
    socklen_t addr_size = sizeof(client_addr);

    while (1) {
        int new_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addr_size);

        if (new_sock == -1) {
            perror("accept");
            continue;
        }

        struct client_data *client_data = (struct client_data *) malloc(sizeof(struct client_data));
        memset(client_data, 0, sizeof(struct client_data));

        client_data->sock = new_sock;
        client_data->addr = client_addr;
        client_data->is_connected = 1;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) client_data);
    }
}

int main(int argc, char *argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        perror("listen");
        return 1;
    }

    printf("Server started on port 8080\n");

    accept_connections(server_sock);

    return 0;
}
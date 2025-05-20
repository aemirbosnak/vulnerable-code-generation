//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LEN 1024
#define MAX_PACKET_LEN 512

struct client_t {
    int sock;
    char ip_addr[INET_ADDRSTRLEN];
};

void* thread_func(void* arg) {
    struct client_t* client = arg;
    char buffer[MAX_PACKET_LEN];
    int bytes_recv = recv(client->sock, buffer, MAX_PACKET_LEN, 0);
    if (bytes_recv > 0) {
        printf("Client %s sent: %s\n", client->ip_addr, buffer);
        // Process the received message
    } else if (bytes_recv == 0) {
        printf("Client %s disconnected\n", client->ip_addr);
    } else {
        perror("recv");
    }
    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    listen(server_sock, 5);

    struct client_t* client = malloc(sizeof(struct client_t));
    client->sock = accept(server_sock, NULL, NULL);
    if (client->sock < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, client);

    char* message = "Welcome, client!";
    send(client->sock, message, strlen(message), 0);

    pthread_join(thread, NULL);

    return 0;
}
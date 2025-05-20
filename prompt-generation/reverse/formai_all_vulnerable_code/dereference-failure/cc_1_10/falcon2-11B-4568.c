//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>

#define PORT 110
#define SERVER_ADDR "mail.example.com"
#define BUF_SIZE 1024
#define NUM_THREADS 5

typedef struct {
    int socket_fd;
    char server_addr[INET6_ADDRSTRLEN];
    struct sockaddr_in server_addr_in;
    char buffer[BUF_SIZE];
    char response[BUF_SIZE];
    int num_messages;
    pthread_mutex_t mutex;
} client_t;

client_t* create_client() {
    client_t* client = (client_t*)malloc(sizeof(client_t));
    memset(client, 0, sizeof(client_t));
    return client;
}

int connect_to_server(client_t* client) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Failed to create socket");
        return -1;
    }

    memset(&client->server_addr_in, 0, sizeof(client->server_addr_in));
    client->server_addr_in.sin_family = AF_INET;
    client->server_addr_in.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_ADDR, &client->server_addr_in.sin_addr) <= 0) {
        perror("Invalid address or port");
        return -1;
    }

    if (connect(socket_fd, (struct sockaddr*)&client->server_addr_in, sizeof(client->server_addr_in)) < 0) {
        perror("Failed to connect to server");
        return -1;
    }

    return 0;
}

void* fetch_messages(void* arg) {
    client_t* client = (client_t*)arg;
    while (1) {
        int num_messages = 0;
        if (send(client->socket_fd, "USER test\r\n", 11, 0) < 0) {
            perror("Failed to send USER command");
            break;
        }
        if (recv(client->socket_fd, client->buffer, BUF_SIZE, 0) < 0) {
            perror("Failed to receive response");
            break;
        }
        if (strcmp(client->buffer, "334") == 0) {
            num_messages = atoi(client->buffer + 5);
        }

        if (num_messages > 0) {
            pthread_mutex_lock(&client->mutex);
            printf("Number of messages: %d\n", num_messages);
            pthread_mutex_unlock(&client->mutex);
        }

        if (num_messages <= 0) {
            break;
        }
    }

    return NULL;
}

int main() {
    client_t* client = create_client();
    if (connect_to_server(client) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    pthread_t threads[NUM_THREADS];
    pthread_t thread_fetch;
    pthread_create(&thread_fetch, NULL, fetch_messages, client);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, fetch_messages, client);
    }

    pthread_join(thread_fetch, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(client);
    return 0;
}
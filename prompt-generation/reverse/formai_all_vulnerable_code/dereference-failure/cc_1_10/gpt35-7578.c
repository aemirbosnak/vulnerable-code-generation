//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_CONNECTIONS 5

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int status;
} Client;

Client clients[MAX_CONNECTIONS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
char buffer[MAX_BUFFER_SIZE];

void *client_handler(void *arg) {
    int sockfd = *((int *) arg);

    char client_addr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(clients[sockfd].addr.sin_addr), client_addr, INET_ADDRSTRLEN);

    printf("New connection from %s:%d\n", client_addr, ntohs(clients[sockfd].addr.sin_port));

    while (1) {
        char buf[MAX_BUFFER_SIZE];
        memset(buf, 0, MAX_BUFFER_SIZE);

        int bytes_received = recv(sockfd, buf, MAX_BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Connection from %s:%d closed\n", client_addr, ntohs(clients[sockfd].addr.sin_port));
            close(sockfd);

            pthread_mutex_lock(&clients_mutex);
            clients[sockfd].status = 0;
            pthread_mutex_unlock(&clients_mutex);

            return NULL;
        } else {
            printf("Received %d bytes from %s:%d: %s\n", bytes_received, client_addr,
                   ntohs(clients[sockfd].addr.sin_port), buf);

            pthread_mutex_lock(&buffer_mutex);
            strcat(buffer, buf);
            strcat(buffer, "\n");
            pthread_mutex_unlock(&buffer_mutex);

            send(sockfd, buf, bytes_received, 0);
        }
    }
}

void *server_handler(void *arg) {
    int port = *((int *) arg);
    int serverfd;

    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    int opt = 1;

    if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(serverfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(serverfd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        int addrlen = sizeof(client_addr);

        int sockfd = accept(serverfd, (struct sockaddr *) &client_addr, (socklen_t *) &addrlen);

        if (sockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_mutex_lock(&clients_mutex);
        int i;
        for (i = 0; i < MAX_CONNECTIONS; i++) {
            if (clients[i].status == 0) {
                clients[i].sockfd = sockfd;
                clients[i].addr = client_addr;
                clients[i].status = 1;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        if (i == MAX_CONNECTIONS) {
            printf("Maximum number of connections (%d) reached\n", MAX_CONNECTIONS);
            close(sockfd);
            continue;
        }

        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, client_handler, (void *) &i)) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }
}

void *qos_handler(void *arg) {
    int threshold = *((int *) arg);

    while (1) {
        sleep(1);

        pthread_mutex_lock(&buffer_mutex);
        int buffer_size = strlen(buffer);
        pthread_mutex_unlock(&buffer_mutex);

        if (buffer_size > threshold) {
            printf("Buffer size is %d bytes, which is above the threshold of %d bytes\n", buffer_size, threshold);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <threshold>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int threshold = atoi(argv[2]);

    if (port <= 0 || threshold <= 0) {
        fprintf(stderr, "Port and threshold must be positive integers\n");
        exit(EXIT_FAILURE);
    }

    memset(clients, 0, sizeof(clients));
    memset(buffer, 0, sizeof(buffer));

    pthread_t server_thread;
    if (pthread_create(&server_thread, NULL, server_handler, (void *) &port)) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }

    pthread_t qos_thread;
    if (pthread_create(&qos_thread, NULL, qos_handler, (void *) &threshold)) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }

    pthread_join(server_thread, NULL);
    pthread_join(qos_thread, NULL);

    return EXIT_SUCCESS;
}
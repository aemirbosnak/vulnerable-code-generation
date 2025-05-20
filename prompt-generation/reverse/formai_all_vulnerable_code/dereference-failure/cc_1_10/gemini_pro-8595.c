//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define NUM_THREADS 10

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

void *client_thread(void *arg) {
    client_t *client = (client_t *)arg;

    int ret;
    char buf[1024];

    while (1) {
        ret = recv(client->sockfd, buf, sizeof(buf), 0);
        if (ret <= 0) {
            break;
        }

        printf("%s", buf);
    }

    close(client->sockfd);
    free(client);

    return NULL;
}

int main() {
    int sockfd, ret;
    struct sockaddr_in addr;
    pthread_t threads[NUM_THREADS];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi("8080"));

    ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    ret = listen(sockfd, NUM_THREADS);
    if (ret == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        client_t *client = malloc(sizeof(client_t));
        client->sockfd = accept(sockfd, (struct sockaddr *)&client->addr, sizeof(client->addr));
        if (client->sockfd == -1) {
            perror("accept");
            free(client);
            continue;
        }

        pthread_create(&threads[client->sockfd % NUM_THREADS], NULL, client_thread, client);
    }

    close(sockfd);

    return 0;
}
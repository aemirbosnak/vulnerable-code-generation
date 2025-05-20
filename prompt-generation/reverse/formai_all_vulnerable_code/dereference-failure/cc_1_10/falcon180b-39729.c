//Falcon-180B DATASET v1.0 Category: Chat server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE    1
#define FALSE   0
#define PORT    8080
#define BACKLOG 10

typedef struct {
    int sock;
    struct sockaddr_in addr;
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *) arg;
    char buf[1024];
    int n;

    while ((n = recv(client->sock, buf, sizeof(buf), 0)) > 0) {
        send(client->sock, buf, n, 0);
    }

    close(client->sock);
    free(client);

    return NULL;
}

int main() {
    int sock, newsock, addrlen;
    struct sockaddr_in servaddr, cliaddr;
    pthread_t thread_id;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        printf("bind failed: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(sock, BACKLOG) == -1) {
        printf("listen failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Chat server is running on port %d\n", PORT);

    while (TRUE) {
        addrlen = sizeof(cliaddr);
        newsock = accept(sock, (struct sockaddr *) &cliaddr, &addrlen);

        if (newsock == -1) {
            printf("accept failed: %s\n", strerror(errno));
            continue;
        }

        client_t *client = (client_t *) malloc(sizeof(client_t));
        client->sock = newsock;
        memcpy(&client->addr, &cliaddr, sizeof(cliaddr));

        if (pthread_create(&thread_id, NULL, handle_client, (void *) client)!= 0) {
            printf("pthread_create failed: %s\n", strerror(errno));
            close(newsock);
            free(client);
        }
    }

    return 0;
}
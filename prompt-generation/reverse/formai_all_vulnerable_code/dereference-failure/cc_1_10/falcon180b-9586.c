//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct {
    int sock;
    int qos;
} qos_t;

void *thread(void *arg) {
    qos_t *qos = (qos_t *) arg;

    char buffer[MAX];
    int bytes_received;

    while (TRUE) {
        bytes_received = recv(qos->sock, buffer, MAX, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received: %s\n", buffer);
    }

    close(qos->sock);
    free(qos);
    pthread_exit(NULL);
}

int main() {
    int sock, qos_sock, client_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    qos_t *qos;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(sock, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        addrlen = sizeof(client_addr);
        client_sock = accept(sock, (struct sockaddr *) &client_addr, &addrlen);

        if (client_sock == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        qos = (qos_t *) malloc(sizeof(qos_t));
        qos->sock = client_sock;
        qos->qos = TRUE;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread, (void *) qos);
    }

    return 0;
}
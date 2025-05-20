//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

typedef struct {
    char *ip;
    int port;
} target;

void *scan_thread(void *arg) {
    target *t = (target *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("%s:%d - Failed to create socket\n", t->ip, t->port);
        close(sock);
        pthread_exit(NULL);
    }

    struct hostent *he = gethostbyname(t->ip);
    if (he == NULL) {
        printf("%s:%d - Failed to resolve host\n", t->ip, t->port);
        close(sock);
        pthread_exit(NULL);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(t->port);
    serv_addr.sin_addr = *((struct in_addr *) he->h_addr);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        printf("%s:%d - Connection failed\n", t->ip, t->port);
        close(sock);
        pthread_exit(NULL);
    } else {
        printf("%s:%d - Open\n", t->ip, t->port);
        close(sock);
        pthread_exit(NULL);
    }
}

int main() {
    int num_threads = 10;
    pthread_t threads[num_threads];

    target targets[] = {{"127.0.0.1", 80}, {"127.0.0.1", 443}, {"192.168.1.1", 22}};

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_thread, &targets[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
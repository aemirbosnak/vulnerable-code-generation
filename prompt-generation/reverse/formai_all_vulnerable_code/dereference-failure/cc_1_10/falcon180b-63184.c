//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_HOSTS 100
#define BUFFER_SIZE 1024

int sock;
struct hostent *server;
int port;
int num_hosts;
char *hosts[MAX_HOSTS];
int num_threads;
pthread_t threads[MAX_THREADS];

void *ping_thread(void *arg) {
    int i;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in addr;
    int addr_size = sizeof(addr);

    for (i = 0; i < num_hosts; i++) {
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, hosts[i], &addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&addr, addr_size) == -1) {
            printf("Host %s is down\n", hosts[i]);
        } else {
            printf("Host %s is up\n", hosts[i]);
        }

        close(sock);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int i, opt;
    struct hostent *he;
    char *hostname;

    if (argc < 3) {
        printf("Usage: %s <hostname/IP> <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Unknown host: %s\n", argv[1]);
        exit(1);
    }

    num_hosts = 1;

    for (i = 0; i < num_hosts; i++) {
        hosts[i] = argv[1];
    }

    num_threads = 1;

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, ping_thread, NULL);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);

    return 0;
}
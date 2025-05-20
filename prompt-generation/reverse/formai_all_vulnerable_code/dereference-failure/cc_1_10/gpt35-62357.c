//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define MAX_THREADS 50
#define MAX_HOSTS 1000

int hosts_index = 0;
int threads_index = -1;
char **hosts;
pthread_mutex_t mutex_hosts = PTHREAD_MUTEX_INITIALIZER;

void signal_handler(int sig) {
    printf("Exiting...\n");
    exit(0);
}

void *scanner(void *arg) {
    char *host = (char *) arg;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    inet_pton(AF_INET, host, &addr.sin_addr);
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        printf("%s is up\n", host);
    }
    close(sockfd);
    pthread_mutex_lock(&mutex_hosts);
    hosts_index++;
    pthread_mutex_unlock(&mutex_hosts);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pthread_t threads[MAX_THREADS];
    hosts = (char **) malloc(MAX_HOSTS * sizeof(char *));
    char address[16];
    strncpy(address, argv[1], 16);
    for (int i = 1; i <= 254; ++i) {
        sprintf(strrchr(address, '.') + 1, "%d", i);
        pthread_mutex_lock(&mutex_hosts);
        hosts[hosts_index] = (char *) malloc(16 * sizeof(char));
        strncpy(hosts[hosts_index], address, 16);
        pthread_mutex_unlock(&mutex_hosts);
        if (threads_index == MAX_THREADS - 1) {
            for (int j = 0; j < MAX_THREADS; ++j) {
                pthread_join(threads[j], NULL);
            }
            threads_index = -1;
        }
        pthread_create(&threads[++threads_index], NULL, scanner, hosts[hosts_index]);
    }
    for (int i = 0; i <= threads_index; ++i) {
        pthread_join(threads[i], NULL);
    }
    for (int i = 0; i < hosts_index; ++i) {
        free(hosts[i]);
    }
    free(hosts);
    return EXIT_SUCCESS;
}
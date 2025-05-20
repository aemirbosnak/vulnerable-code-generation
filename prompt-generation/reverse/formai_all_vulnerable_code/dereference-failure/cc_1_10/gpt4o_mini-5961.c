//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <errno.h>

#define TIMEOUT 1
#define MAX_THREADS 10
#define MAX_PORT 65535
#define HOST "127.0.0.1"

void *scan_port(void *arg);
void print_usage(char *prog_name);
void set_socket_timeout(int sock);
void *handler(void *arg);

typedef struct {
    char *ip_address;
    int port;
} port_info;

pthread_mutex_t print_mutex;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    pthread_mutex_init(&print_mutex, NULL);

    printf("Initiating a paranoid port scan on %s...\n", ip_address);

    for (int port = 1; port <= MAX_PORT; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }

        port_info *info = malloc(sizeof(port_info));
        info->ip_address = ip_address;
        info->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, info) != 0) {
            perror("Failed to create thread");
            free(info);
            exit(EXIT_FAILURE);
        }

        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&print_mutex);
    printf("Port scan completed on %s.\n", ip_address);
    return 0;
}

void *scan_port(void *arg) {
    port_info *info = (port_info *)arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in target;

    if (sock < 0) {
        perror("Could not create socket");
        free(info);
        pthread_exit(NULL);
    }

    set_socket_timeout(sock);

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(info->port);
    target.sin_addr.s_addr = inet_addr(info->ip_address);

    int conn_result = connect(sock, (struct sockaddr *)&target, sizeof(target));
    if (conn_result == 0) {
        pthread_mutex_lock(&print_mutex);
        printf("Port %d is open on %s\n", info->port, info->ip_address);
        pthread_mutex_unlock(&print_mutex);
    }

    close(sock);
    free(info);
    pthread_exit(NULL);
}

void set_socket_timeout(int sock) {
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("Set socket timeout failed");
    }
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("Set socket timeout failed");
    }
}

void print_usage(char *prog_name) {
    fprintf(stderr, "Usage: %s <ip_address>\n", prog_name);
    fprintf(stderr, "Example: %s 192.168.1.1\n", prog_name);
}
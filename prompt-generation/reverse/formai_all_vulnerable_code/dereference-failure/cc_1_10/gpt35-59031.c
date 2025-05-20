//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 256

struct scan_args {
    char* ip;
    int port;
};

void* scan(void* args);
int is_open(char* ip, int port);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP_Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* ip = argv[1];

    printf("Scanning %s...\n", ip);

    // Create threads for scanning
    pthread_t threads[MAX_THREADS];
    int count = 0;

    for (int i = 1; i <= 65535; i++) {
        struct scan_args* args = malloc(sizeof(struct scan_args));
        args->ip = ip;
        args->port = i;

        if (pthread_create(&threads[count++], NULL, scan, args) != 0) {
            fprintf(stderr, "Failed to create thread for port %d.\n", i);
            count--;
        }

        if (count == MAX_THREADS) {
            for (int j = 0; j < MAX_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
            count = 0;
        }
    }

    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void* scan(void* args) {
    struct scan_args* scanArgs = (struct scan_args*)args;

    if (is_open(scanArgs->ip, scanArgs->port)) {
        printf("%d Open\n", scanArgs->port);
    }

    free(scanArgs);
    return NULL;
}

int is_open(char* ip, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        return 0;
    }

    int result = connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    close(sock);

    return result == 0;
}
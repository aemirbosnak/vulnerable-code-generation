//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 1000
#define MAX_PORTS 65535

struct port_info {
    int port;
    char *ip;
};

void *scan_port(void *param) {
    struct port_info *info = param;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(info->port);
    addr.sin_addr.s_addr = inet_addr(info->ip);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        close(sock);
        printf("Port %d is open on %s\n", ntohs(addr.sin_port), info->ip);
        return NULL;
    } else {
        close(sock);
        return NULL;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage:./scanner <ip> <port_range>\n");
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    pthread_t threads[MAX_THREADS];
    struct port_info info[MAX_THREADS];

    int count = 0;
    for (int i = start_port; i <= end_port; i++) {
        char port_str[6];
        snprintf(port_str, sizeof(port_str), "%d", i);
        info[count].port = i;
        info[count].ip = strdup(ip);
        pthread_create(&threads[count], NULL, scan_port, &info[count]);
        count++;

        if (count >= MAX_THREADS) {
            for (int j = 0; j < count; j++) {
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
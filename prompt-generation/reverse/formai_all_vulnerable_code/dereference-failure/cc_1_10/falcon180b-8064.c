//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

typedef struct {
    int port;
    char *ip;
} target;

void *scan_port(void *arg) {
    int sock = 0;
    struct sockaddr_in addr;
    int port = ((target *)arg)->port;
    char *ip = ((target *)arg)->ip;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open on %s\n", port, ip);
        close(sock);
    } else {
        printf("Port %d is closed on %s\n", port, ip);
        close(sock);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[1024];
    target targets[MAX_THREADS];
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    if (argc < 3) {
        printf("Usage: %s <ip> <port_range>\n", argv[0]);
        exit(1);
    }

    fp = fopen("ips.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(targets[num_threads].ip, line);
        num_threads++;
        if (num_threads == MAX_THREADS) {
            break;
        }
    }
    fclose(fp);

    for (int i = 1; i <= MAX_PORTS; i++) {
        if (i >= atoi(argv[2]) && i <= MAX_PORTS) {
            for (int j = 0; j < num_threads; j++) {
                targets[j].port = i;
                pthread_create(&threads[j], NULL, scan_port, &targets[j]);
            }
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int scan_port(int port, char *ip_address) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
        close(sockfd);
        printf("Port %d is open on %s\n", port, ip_address);
        return 1;
    } else if (errno == ECONNREFUSED) {
        close(sockfd);
        printf("Port %d is closed on %s\n", port, ip_address);
        return 0;
    } else {
        close(sockfd);
        printf("Error scanning port %d on %s\n", port, ip_address);
        return -1;
    }
}

void *scan_thread(void *args) {
    int *port = (int *)args;
    char *ip_address = "127.0.0.1";
    scan_port(*port, ip_address);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (end_port <= start_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    pthread_t threads[MAX_THREADS];
    int count = 0;

    for (int i = start_port; i <= end_port; i++) {
        if (count >= MAX_THREADS) {
            for (int j = 0; j < count; j++) {
                pthread_join(threads[j], NULL);
            }
            count = 0;
        }

        pthread_create(&threads[count], NULL, scan_thread, (void *)&i);
        count++;
    }

    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
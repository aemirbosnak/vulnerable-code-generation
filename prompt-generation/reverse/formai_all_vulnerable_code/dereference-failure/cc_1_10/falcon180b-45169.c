//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define THREAD_COUNT 50

struct port_info {
    int port;
    char *ip;
    int status;
};

void *scan_port(void *arg) {
    struct port_info *port_info = (struct port_info *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_info->port);
    inet_pton(AF_INET, port_info->ip, &server_addr.sin_addr);
    int result = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    close(sock);
    if (result == 0) {
        port_info->status = 1;
    } else {
        port_info->status = 0;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    pthread_t threads[THREAD_COUNT];
    struct port_info port_info[THREAD_COUNT];

    int thread_id = 0;
    for (int i = start_port; i <= end_port; i++) {
        port_info[thread_id].port = i;
        strncpy(port_info[thread_id].ip, ip, strlen(ip));
        pthread_create(&threads[thread_id], NULL, scan_port, &port_info[thread_id]);
        thread_id++;
        if (thread_id == THREAD_COUNT) {
            for (int j = 0; j < THREAD_COUNT; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_id = 0;
        }
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
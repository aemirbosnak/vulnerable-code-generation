//FormAI DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_PORTS 65535 // maximum number of ports to scan
#define MAX_THREADS 100 // maximum number of threads to use concurrently

struct scan_config {
    char *target_ip;
    int start_port;
    int end_port;
};

struct thread_data {
    int id;
    int sock_fd;
};

void *scan_port(void *arg) {
    struct thread_data *th_data = (struct thread_data *) arg;
    while (1) {
        int port;
        if (read(th_data->sock_fd, &port, sizeof(port)) < 0)
            continue;
        printf("Thread %d scanning port %d\n", th_data->id, port);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        addr.sin_port = htons(port);
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
            printf("Port %d is closed\n", port);
            close(sock);
        } else {
            printf("Port %d is open\n", port);
            close(sock);
        }
    }
    return NULL;
}

void scan_ports(struct scan_config *config) {
    printf("Scanning ports from %d to %d on %s\n", config->start_port, config->end_port, config->target_ip);
    int ports_to_scan = config->end_port - config->start_port + 1;
    int num_threads = ports_to_scan < MAX_THREADS ? ports_to_scan : MAX_THREADS;
    int ports_per_thread = ports_to_scan / num_threads;
    pthread_t threads[num_threads];
    int socks[num_threads][2];
    for (int i = 0; i < num_threads; i++) {
        socketpair(AF_UNIX, SOCK_STREAM, 0, socks[i]);
        int start_port = config->start_port + i * ports_per_thread;
        int end_port = start_port + ports_per_thread - 1;
        if (i == num_threads - 1)
            end_port = config->end_port;
        struct scan_config th_config = {
            .target_ip = config->target_ip,
            .start_port = start_port,
            .end_port = end_port
        };
        pthread_create(&threads[i], NULL, scan_port, &(struct thread_data) { i, socks[i][0] });
        write(socks[i][1], &th_config, sizeof(th_config));
    }
    for (int i = 0; i < num_threads; i++)
        pthread_join(threads[i], NULL);
}

int main() {
    char target_ip[] = "127.0.0.1";
    printf("Welcome to the distributed port scanner!\n");
    printf("Please enter the range of ports to scan (e.g. 1-100): ");
    char range_str[32];
    fgets(range_str, sizeof(range_str), stdin);
    int start_port = atoi(strtok(range_str, "-"));
    int end_port = atoi(strtok(NULL, "-"));
    struct scan_config config = {
        .target_ip = target_ip,
        .start_port = start_port,
        .end_port = end_port
    };
    scan_ports(&config);
    return 0;
}
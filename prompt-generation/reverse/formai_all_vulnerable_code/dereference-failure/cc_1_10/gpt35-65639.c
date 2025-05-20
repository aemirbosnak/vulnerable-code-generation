//FormAI DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_PORTS 65536
#define MAX_THREADS 200
#define BUFFER_SIZE 1024

typedef struct {
    int start_port;
    int end_port;
    char* ip_address;
} scanner_args;

int open_socket(char* ip_address, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    memset(&server_address.sin_zero, 0, sizeof(server_address.sin_zero));
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        return -1;
    }
    return sock;
}

void scan_range(int start_port, int end_port, char* ip_address) {
    int port;
    for (port = start_port; port <= end_port; port++) {
        int sock = open_socket(ip_address, port);
        if (sock >= 0) {
            printf("Port %d is open\n", port);
            close(sock);
        }
    }
}

void* scan_range_threaded(void* arg_struct) {
    scanner_args* args = (scanner_args*)arg_struct;
    scan_range(args->start_port, args->end_port, args->ip_address);
    return NULL;
}

void scan_range_multi_threaded(int start_port, int end_port, char* ip_address, int num_threads) {
    int ports_per_thread = (int) ((end_port - start_port + 1) / num_threads);
    int remaining_ports = (end_port - start_port + 1) % num_threads;
    
    pthread_t threads[MAX_THREADS];
    scanner_args thread_args[MAX_THREADS];
    
    int i;
    for (i = 0; i < num_threads; i++) {
        thread_args[i].ip_address = ip_address;
        thread_args[i].start_port = start_port + i * ports_per_thread;
        thread_args[i].end_port = thread_args[i].start_port + ports_per_thread - 1;
        if (i == num_threads - 1)
            thread_args[i].end_port += remaining_ports;
        pthread_create(&threads[i], NULL, scan_range_threaded, (void*)&thread_args[i]);
    }
    
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4 && argc != 5) {
        fprintf(stderr, "usage: %s <ip address> <start port> <end port> [<num threads>]\n", argv[0]);
        exit(1);
    }
    
    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    int num_threads = 1;
    if (argc == 5)
        num_threads = atoi(argv[4]);
    
    if (start_port < 0 || start_port > MAX_PORTS) {
        fprintf(stderr, "error: invalid starting port\n");
        exit(1);
    }
    
    if (end_port < 0 || end_port > MAX_PORTS) {
        fprintf(stderr, "error: invalid ending port\n");
        exit(1);
    }
    
    if (num_threads <= 0 || num_threads > MAX_THREADS) {
        fprintf(stderr, "error: invalid number of threads\n");
        exit(1);
    }
    
    printf("Scanning %s from port %d to %d\n", ip_address, start_port, end_port);
    
    if (num_threads == 1) {
        scan_range(start_port, end_port, ip_address);
    } else {
        scan_range_multi_threaded(start_port, end_port, ip_address, num_threads);
    }
    
    printf("\nScan finished.\n");
    return 0;
}
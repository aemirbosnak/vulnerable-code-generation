//FormAI DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <errno.h>

#define MAX_PORTS 1024
#define MAX_THREADS 100

typedef struct {
    int start;
    int end;
    char *target;
    int *ports;
    int num_ports;
} scan_data;

int open_connection(char *hostname, int port) {
    struct sockaddr_in server_address;
    struct hostent *server_info;
    int socket_fd;
    
    if ((server_info = gethostbyname(hostname)) == NULL) {
        perror("Error resolving hostname");
        return -1;
    }
    
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr*) server_info->h_addr);
    server_address.sin_port = htons(port);
    
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Error creating socket");
        return -1;
    }
    
    if (connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        return -1;
    }
    
    return socket_fd;
}

void* port_scanner(void* arg) {
    scan_data *data = (scan_data*) arg;
    int i, socket_fd;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    for(i = data->start; i < data->end; i++) {
        socket_fd = open_connection(data->target, data->ports[i]);

        if (socket_fd >= 0) {
            printf("Port %d open\n", data->ports[i]);
            close(socket_fd);
        }
    }
    return NULL;
}

void distribute_ports(char *target, int *ports, int num_ports, int num_threads) {
    // Distribute ports over threads
    int i, chunk_size, remainder;
    pthread_t threads[MAX_THREADS];
    scan_data thread_data[MAX_THREADS];
    
    printf("Scanning %d ports on %s...\n", num_ports, target);
    
    chunk_size = num_ports / num_threads;
    remainder = num_ports % num_threads;
    
    for (i = 0; i < num_threads; i++) {
        thread_data[i].target = target;
        thread_data[i].ports = ports;
        thread_data[i].num_ports = (i == 0) ? chunk_size + remainder : chunk_size;
        thread_data[i].start = (i == 0) ? 0 : thread_data[i-1].end;
        thread_data[i].end = thread_data[i].start + thread_data[i].num_ports;
        
        pthread_create(&threads[i], NULL, port_scanner, (void*) &thread_data[i]);
    }
    
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char **argv) {
    char *target;
    int num_threads, ports[MAX_PORTS], num_ports, i;

    if(argc < 3) {
       printf("usage: %s <hostname> <# threads>\n", argv[0]);
       return 1;
    }
    target = argv[1];
    num_threads = atoi(argv[2]);
    
    // Collect ports to scan
    num_ports = 0;
    for(i = 0; i < MAX_PORTS; i++) {
        ports[num_ports++] = i+1;
    }
    
    distribute_ports(target, ports, num_ports, num_threads);
    
    return 0;
}
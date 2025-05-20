//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// port scanner results
typedef struct {
    int port;
    char* ip;
    int is_open;
} port_scan_result;

// thread data
typedef struct {
    char* ip;
    int start_port;
    int end_port;
    port_scan_result* results;
} thread_data;

// thread function
void* scan_ports(void* arg) {
    thread_data* data = (thread_data*)arg;

    // initialize socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // scan ports
    for (int port = data->start_port; port <= data->end_port; port++) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(data->ip);

        // connect to port
        int status = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
        if (status == 0) {
            // port is open
            data->results[port - data->start_port].port = port;
            data->results[port - data->start_port].ip = data->ip;
            data->results[port - data->start_port].is_open = 1;
        } else {
            // port is closed
            data->results[port - data->start_port].port = port;
            data->results[port - data->start_port].ip = data->ip;
            data->results[port - data->start_port].is_open = 0;
        }
    }

    // close socket
    close(sockfd);

    return NULL;
}

int main(int argc, char** argv) {
    // check arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    // get arguments
    char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // allocate memory for results
    port_scan_result* results = malloc(sizeof(port_scan_result) * (end_port - start_port + 1));
    if (results == NULL) {
        perror("malloc");
        exit(1);
    }

    // create thread pool
    int num_threads = 4;
    pthread_t threads[num_threads];
    thread_data data[num_threads];
    int ports_per_thread = (end_port - start_port + 1) / num_threads;

    for (int i = 0; i < num_threads; i++) {
        data[i].ip = ip;
        data[i].start_port = start_port + i * ports_per_thread;
        data[i].end_port = start_port + (i + 1) * ports_per_thread - 1;
        data[i].results = results;

        pthread_create(&threads[i], NULL, scan_ports, &data[i]);
    }

    // join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // print results
    for (int i = 0; i < end_port - start_port + 1; i++) {
        if (results[i].is_open) {
            printf("Port %d is open on %s\n", results[i].port, results[i].ip);
        }
    }

    // free memory
    free(results);

    return 0;
}
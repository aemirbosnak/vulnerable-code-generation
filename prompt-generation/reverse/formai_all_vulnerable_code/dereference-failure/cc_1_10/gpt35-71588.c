//FormAI DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define MAX_PORT 65536
#define MAX_THREADS 100

int open_ports[MAX_PORT] = {0};
pthread_mutex_t scan_mutex;

typedef struct {
    char *ip;
    int start_port;
    int end_port;
} scan_arguments;

void* thread_scan(void* arg) {
    scan_arguments* arguments = (scan_arguments*) arg;
    struct hostent* host;
    struct sockaddr_in destination;
    int sock, port;

    memset(&destination, 0, sizeof(destination));
    destination.sin_family = AF_INET;
    destination.sin_addr.s_addr = inet_addr(arguments->ip);

    for(port = arguments->start_port; port <= arguments->end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        destination.sin_port = htons(port);

        if(connect(sock, (struct sockaddr *) &destination, sizeof(destination)) == 0) {
            pthread_mutex_lock(&scan_mutex);
            open_ports[port] = 1;
            pthread_mutex_unlock(&scan_mutex);
            close(sock);
        }
    }

    free(arguments->ip);
    free(arguments);
    return NULL;
}

void help_message() {
    printf("Port Scanner Usage\n");
    printf("Syntax: ./scanner [options] <ip>\n\n");
    printf("Options:\n");
    printf("\t-s: start port (default 1)\n");
    printf("\t-e: end port (default 65535)\n");
    printf("\t-t: number of threads (default 10)\n");
    printf("\t-h: print this message\n");
}

int main(int argc, char** argv) {
    int i, start_port = 1, end_port = MAX_PORT, num_threads = 10;
    char *ip = NULL;
    pthread_t threads[MAX_THREADS];

    if(argc == 1) {
        help_message();
        return 0;
    }

    for(i = 1; i < argc; i++) {
        char* arg = argv[i];

        if(strcmp(arg, "-s") == 0) {
            start_port = atoi(argv[++i]);
            if(start_port < 1 || start_port > MAX_PORT) {
                printf("Invalid start port %d\n", start_port);
                return -1;
            }
        } else if(strcmp(arg, "-e") == 0) {
            end_port = atoi(argv[++i]);
            if(end_port < 1 || end_port > MAX_PORT) {
                printf("Invalid end port %d\n", end_port);
                return -1;
            }
        } else if(strcmp(arg, "-t") == 0) {
            num_threads = atoi(argv[++i]);
            if(num_threads < 1 || num_threads > MAX_THREADS) {
                printf("Invalid number of threads %d\n", num_threads);
                return -1;
            }
        } else if(strcmp(arg, "-h") == 0) {
            help_message();
            return 0;
        } else {
            ip = arg;
        }
    }

    if(ip == NULL) {
        printf("Missing IP parameter\n");
        return -1;
    }

    printf("Starting scan on %s\n", ip);

    pthread_mutex_init(&scan_mutex, NULL);

    int port_range = end_port - start_port + 1;
    int ports_per_thread = port_range / num_threads;
    int remaining_ports = port_range % num_threads;

    int current_port = start_port;
    for(i = 0; i < num_threads; i++) {
        scan_arguments* arguments = (scan_arguments*) malloc(sizeof(scan_arguments));
        arguments->ip = strdup(ip);
        arguments->start_port = current_port;
        current_port += ports_per_thread;
        if(remaining_ports > 0) {
            current_port += 1;
            remaining_ports--;
        }
        arguments->end_port = current_port - 1;

        pthread_create(&threads[i], NULL, thread_scan, arguments);
    }

    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&scan_mutex);

    printf("Open ports:\n");
    for(i = 1; i <= MAX_PORT; i++) {
        if(open_ports[i] == 1) {
            printf("\t%d\n", i);
        }
    }

    return 0;
}
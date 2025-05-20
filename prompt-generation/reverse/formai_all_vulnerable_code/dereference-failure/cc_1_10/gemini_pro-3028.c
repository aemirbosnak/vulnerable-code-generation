//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <netdb.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_THREADS 10
#define MAX_PORTS 1024
#define MAX_HOSTNAME 255

typedef struct {
    int port;
    char *hostname;
} thread_arg;

void sigint_handler(int);
int create_socket(char *, int);
void *scan_thread(void *);

int main(int argc, char **argv) {
    int num_threads, num_ports, i, j, fd, optval, scan_status;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    char *hostname, *ports[MAX_PORTS];
    pthread_t threads[MAX_THREADS];
    thread_arg args[MAX_THREADS];

    if (argc < 4) {
        fprintf(stderr, "Usage: %s hostname port1 port2 ...\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    num_ports = argc - 2;
    if (num_ports > MAX_PORTS) {
        fprintf(stderr, "Maximum number of ports exceeded (max: %d)\n", MAX_PORTS);
        return 1;
    }

    for (i = 0; i < num_ports; i++) {
        ports[i] = argv[i + 2];
    }

    signal(SIGINT, sigint_handler);

    num_threads = num_ports;
    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Maximum number of threads exceeded (max: %d)\n", MAX_THREADS);
        return 1;
    }

    for (i = 0; i < num_threads; i++) {
        args[i].hostname = hostname;
        args[i].port = atoi(ports[i]);
        if ((scan_status = pthread_create(&threads[i], NULL, scan_thread, &args[i])) != 0) {
            fprintf(stderr, "Failed to create thread: %s\n", strerror(scan_status));
            return 1;
        }
    }

    for (i = 0; i < num_threads; i++) {
        if ((scan_status = pthread_join(threads[i], NULL)) != 0) {
            fprintf(stderr, "Failed to join thread: %s\n", strerror(scan_status));
            return 1;
        }
    }

    return 0;
}

void sigint_handler(int sig) {
    exit(0);
}

int create_socket(char *hostname, int port) {
    int fd, status;
    struct hostent *host;
    struct sockaddr_in addr;

    if ((host = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", hostname);
        return -1;
    }

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *) host->h_addr);

    if ((status = connect(fd, (struct sockaddr *) &addr, sizeof(addr))) == -1) {
        if (errno == ECONNREFUSED) {
            // Port is closed
            return 0;
        } else {
            fprintf(stderr, "Failed to connect to port %d on host %s: %s\n", port, hostname, strerror(errno));
            return -1;
        }
    }

    return fd;
}

void *scan_thread(void *arg) {
    thread_arg *args = (thread_arg *) arg;
    int fd;

    if ((fd = create_socket(args->hostname, args->port)) > 0) {
        printf("Port %d on host %s is open\n", args->port, args->hostname);
        close(fd);
    }

    return NULL;
}
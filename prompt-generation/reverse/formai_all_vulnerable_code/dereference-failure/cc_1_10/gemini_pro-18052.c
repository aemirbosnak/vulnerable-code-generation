//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

#define MAX_SIZE 1024
#define MAX_ATTEMPTS 5

int sock_fd;
struct sockaddr_in dest_addr;
unsigned long long total_size, total_time;
struct timespec begin, end;
char buf[MAX_SIZE];

void usage(char *argv[]) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
}

int create_socket(char *host, int port) {
    int sock_fd;

    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr = *((struct in_addr *)host_entry->h_addr);

    return sock_fd;
}

int connect_socket(int sock_fd) {
    int status;

    status = connect(sock_fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (status == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return status;
}

int send_data(int sock_fd, char *buf, int size) {
    int status;

    status = write(sock_fd, buf, size);
    if (status == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    return status;
}

int receive_data(int sock_fd, char *buf, int size) {
    int status;

    status = read(sock_fd, buf, size);
    if (status == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    return status;
}

void close_socket(int sock_fd) {
    close(sock_fd);
}

double get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000000000.0 + (end.tv_nsec - start.tv_nsec);
}

void signal_handler(int signum) {
    if (signum == SIGALRM) {
        close(sock_fd);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    sock_fd = create_socket(host, port);
    if (connect_socket(sock_fd) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    signal(SIGALRM, signal_handler);
    alarm(1);

    total_size = 0;
    total_time = 0;
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        memset(buf, 0, MAX_SIZE);
        clock_gettime(CLOCK_MONOTONIC, &begin);
        int status = send_data(sock_fd, buf, MAX_SIZE);
        if (status == -1) {
            perror("send_data");
            exit(EXIT_FAILURE);
        }
        total_size += status;
        status = receive_data(sock_fd, buf, MAX_SIZE);
        if (status == -1) {
            perror("receive_data");
            exit(EXIT_FAILURE);
        }
        total_size += status;
        clock_gettime(CLOCK_MONOTONIC, &end);
        total_time += get_time_diff(begin, end);
        printf("Round %d: %f ms\n", i + 1, get_time_diff(begin, end) / 1000000.0);
    }

    close_socket(sock_fd);

    printf("Average response time: %f ms\n", total_time / (1000000.0 * MAX_ATTEMPTS));
    printf("Total data sent: %llu bytes\n", total_size);

    return EXIT_SUCCESS;
}
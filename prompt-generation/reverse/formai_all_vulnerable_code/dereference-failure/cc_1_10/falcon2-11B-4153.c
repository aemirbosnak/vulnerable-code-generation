//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>

// Define global variables
int num_threads = 4;
pthread_t *threads;
int thread_id;
int server_fd;
char *server_ip = "127.0.0.1";
int server_port = 8080;
int client_port;
char *client_ip;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;
struct timeval start_time, end_time;
long int total_time;

int is_port_open(int port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(sock);
        perror("connect");
        return -1;
    }
    close(sock);
    return 0;
}

void *send_data(void *arg) {
    int client_fd = (int)arg;
    char buf[1024] = "GET / HTTP/1.1\r\nHost: ";
    memset(buf, 0, sizeof(buf));
    int n = sprintf(buf, "%s:%d\r\n", client_ip, client_port);
    if (n == -1) {
        printf("Failed to sprintf\n");
        return NULL;
    }
    n = send(client_fd, buf, n, 0);
    if (n == -1) {
        printf("Failed to send data\n");
        return NULL;
    }
    fflush(stdout);
    close(client_fd);
    pthread_exit(NULL);
}

int main() {
    // Initialize global variables
    signal(SIGPIPE, SIG_IGN);
    gettimeofday(&start_time, NULL);
    total_time = 0;
    thread_id = 0;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    // Set socket options
    int yes = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Set server address and port
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Bind server socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen on server socket
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Create threads
    threads = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, &send_data, (void *)i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    close(server_fd);
    free(threads);

    // Calculate total time
    gettimeofday(&end_time, NULL);
    total_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
    printf("Total time: %ld ms\n", total_time);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <pthread.h>
#include <stdint.h>
#define MB (1024 * 1024)

struct ThreadInfo {
    int sockfd;
    char *buffer;
    size_t buffer_size;
    uint64_t bytes_received;
};

static void *download_thread(void *arg) {
    struct ThreadInfo *info = (struct ThreadInfo *)arg;
    ssize_t bytes_read;
    info->bytes_received = 0;
    
    while ((bytes_read = read(info->sockfd, info->buffer, info->buffer_size)) > 0) {
        info->bytes_received += bytes_read;
    }
    
    if (bytes_read < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    
    return NULL;
}

static void print_speed(uint64_t bytes, time_t start, time_t end) {
    double elapsed = difftime(end, start);
    double mbps = (double)bytes / MB / elapsed;
    printf("Speed: %.2f MBps\n", mbps);
}

int main(int argc, char *argv[]) {
    char *host = "example.com";
    int port = 80;
    size_t buffer_size = 100 * MB; /* 100 MB buffer */
    int threads = 4;
    struct ThreadInfo *info;
    pthread_t *threads_handles;

    if (argc >= 2) {
        host = argv[1];
    }

    if (argc >= 3) {
        port = atoi(argv[2]);
    }

    if (argc >= 4) {
        buffer_size = atol(argv[3]) * MB;
    }

    if (argc >= 5) {
        threads = atoi(argv[4]);
    }

    threads_handles = malloc(threads * sizeof(pthread_t));
    info = malloc(threads * sizeof(struct ThreadInfo));

    for (int i = 0; i < threads; i++) {
        int sockfd;
        struct sockaddr_in addr;
        struct hostent *host_info;
        
        host_info = gethostbyname(host);
        if (!host_info) {
            perror("gethostbyname");
            exit(EXIT_FAILURE);
        }

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        memcpy(&addr.sin_addr, host_info->h_addr, host_info->h_length);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("connect");
            exit(EXIT_FAILURE);
        }

        info[i].sockfd = sockfd;
        info[i].buffer = malloc(buffer_size);
        info[i].buffer_size = buffer_size;
        info[i].bytes_received = 0;

        if (pthread_create(&threads_handles[i], NULL, download_thread, &info[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    time_t start = time(NULL);
    
    for (int i = 0; i < threads; i++) {
        if (pthread_join(threads_handles[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    time_t end = time(NULL);
    uint64_t total_bytes = 0;
    
    for (int i = 0; i < threads; i++) {
        total_bytes += info[i].bytes_received;
        free(info[i].buffer);
    }
    
    free(info);
    free(threads_handles);
    
    print_speed(total_bytes, start, end);
    
    return 0;
}
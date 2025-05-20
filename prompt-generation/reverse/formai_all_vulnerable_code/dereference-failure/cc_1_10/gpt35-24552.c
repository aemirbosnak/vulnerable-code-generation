//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_THREADS 10
#define MAX_IP_LEN 16
#define PORT 8888

// Thread arguments
typedef struct {
    char ip[MAX_IP_LEN];
} thread_args_t;

void *scan_ip(void *args) {
    thread_args_t *t_args = (thread_args_t*) args;
    char *ip = t_args->ip;

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0 ) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
        printf("%s is open\n", ip);
    }

    close(sockfd);
    free(args);
    pthread_exit(NULL);
}

void scan_network(char *base_ip) {
    pthread_t threads[MAX_THREADS];
    char ip[MAX_IP_LEN];
    int i;

    for (i = 1; i <= 255; i++) {
        sprintf(ip, "%s.%d", base_ip, i);

        thread_args_t *args = (thread_args_t*) malloc(sizeof(thread_args_t));
        strncpy(args->ip, ip, MAX_IP_LEN);

        pthread_create(&threads[i % MAX_THREADS], NULL, scan_ip, args);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <base_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *base_ip = argv[1];
    
    scan_network(base_ip);
    
    return 0;
}
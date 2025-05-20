//FormAI DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
 
void *scan(void *ptr);
int open_socket(int port);
int is_open(struct sockaddr_in srv);
 
struct thread_args {
    char *target;
    int start;
    int end;
};
 
int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <target> <start-port> <end-port>\n", argv[0]);
        return 1;
    }
 
    char *target = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
 
    pthread_t *threads = malloc(sizeof(pthread_t) * (end_port - start_port + 1));
    struct thread_args *args = malloc(sizeof(struct thread_args) * (end_port - start_port + 1));
    int num_threads = 0;
 
    for (int i = start_port; i <= end_port; i++) {
        args[num_threads].target = target;
        args[num_threads].start = i;
        args[num_threads].end = end_port;
        pthread_create(&threads[num_threads], NULL, scan, &args[num_threads]);
        num_threads++;
    }
 
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
 
    free(args);
    free(threads);
 
    return 0;
}
 
void *scan(void *ptr) {
    struct thread_args *args = ptr;
    char *target = args->target;
    int start_port = args->start;
    int end_port = args->end;
 
    for (int i = start_port; i <= end_port; i++) {
        int sock = open_socket(i);
 
        if (sock == -1) {
            continue;
        }
 
        struct sockaddr_in srv;
        socklen_t srv_len = sizeof(srv);
 
        if (getpeername(sock, (struct sockaddr*)&srv, &srv_len) == -1) {
            printf("Port %d on %s is open but failed to connect\n", i, target);
        } else {
            printf("Port %d on %s is open\n", i, target);
        }
 
        close(sock);
    }
 
    return NULL;
}
 
int open_socket(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
 
    if (sock == -1) {
        perror("socket");
        return -1;
    }
 
    struct sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = inet_addr("127.0.0.1");
    srv.sin_port = htons(port);
 
    if (connect(sock, (struct sockaddr*)&srv, sizeof(srv)) == -1) {
        return -1;
    }
 
    return sock;
}
 
int is_open(struct sockaddr_in srv) {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
 
    if (sock == -1) {
        perror("socket");
        return -1;
    }
 
    if (connect(sock, (struct sockaddr*)&srv, sizeof(srv)) == -1) {
        close(sock);
        return -1;
    }
 
    close(sock);
    return 0;
}
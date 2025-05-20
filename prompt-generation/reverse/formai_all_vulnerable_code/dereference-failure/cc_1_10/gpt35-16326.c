//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_HOSTS 100

char* hosts[MAX_HOSTS];
int num_hosts = 0;
int thread_count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* scan_hosts(void* arg) {
    int i;
    char buf[1024];
    int s;
    struct sockaddr_in addr;
    struct hostent *host_info;
    
    pthread_mutex_lock(&mutex);
    i = thread_count++;
    pthread_mutex_unlock(&mutex);
    
    while (i < num_hosts) {
        s = socket(AF_INET, SOCK_STREAM, 0);
        if (s < 0) {
            perror("socket");
            exit(1);
        }
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
        host_info = gethostbyname(hosts[i]);
        if (host_info == NULL) {
            printf("Cannot resolve host: %s\n", hosts[i]);
            close(s);
            i = thread_count++;
            continue;
        }
        memcpy(&addr.sin_addr, host_info->h_addr_list[0], sizeof(struct in_addr));
        if (connect(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
            printf("Cannot connect to host %s\n", hosts[i]);
            close(s);
            i = thread_count++;
            continue;
        }
        sprintf(buf, "%s:%d\n", hosts[i], ntohs(addr.sin_port));
        write(1, buf, strlen(buf));
        close(s);
        i = thread_count++;
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    int i;
    pthread_t threads[MAX_THREADS];
    
    if (argc < 2) {
        printf("Usage: %s <host1> <host2> ... <hostn>\n", argv[0]);
        exit(1);
    }
    for (i = 1; i < argc; i++) {
        hosts[num_hosts++] = strdup(argv[i]);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, scan_hosts, NULL);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
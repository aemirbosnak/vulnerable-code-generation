//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define MAX_HOSTS 128
#define MAX_THREADS 10
#define TIMEOUT 1

typedef struct {
    char *hostname;
    int thread_id;
} ping_task_t;

void *ping_host(void *arg) {
    ping_task_t *task = (ping_task_t *)arg; 
    char command[256];
    
    snprintf(command, sizeof(command), "ping -c 1 -W %d %s", TIMEOUT, task->hostname);
    printf("[Thread %d] Pinging %s...\n", task->thread_id, task->hostname);
    
    FILE *fp;
    char result[1024];
    int status;

    if ((fp = popen(command, "r")) == NULL) {
        fprintf(stderr, "[Thread %d] Error executing ping for %s: %s\n", task->thread_id, task->hostname, strerror(errno));
        pthread_exit(NULL);
    }

    while (fgets(result, sizeof(result) - 1, fp) != NULL) {
        printf("[Thread %d] %s", task->thread_id, result);
    }

    status = pclose(fp);
    if (status == -1) {
        fprintf(stderr, "[Thread %d] Error closing ping process for %s: %s\n", task->thread_id, task->hostname, strerror(errno));
    }

    pthread_exit(NULL);
}

void create_ping_tasks(char **hosts, int host_count) {
    pthread_t threads[MAX_THREADS];
    ping_task_t tasks[MAX_THREADS];
    
    int num_threads = host_count < MAX_THREADS ? host_count : MAX_THREADS;

    for (int i = 0; i < num_threads; i++) {
        tasks[i].hostname = hosts[i];
        tasks[i].thread_id = i;
        
        if (pthread_create(&threads[i], NULL, ping_host, &tasks[i]) != 0) {
            fprintf(stderr, "Error creating thread for host %s: %s\n", hosts[i], strerror(errno));
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host1> <host2> ... <hostN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hosts[MAX_HOSTS];
    int host_count = argc - 1;

    for (int i = 1; i <= host_count && i < MAX_HOSTS; i++) {
        hosts[i - 1] = argv[i];
    }

    create_ping_tasks(hosts, host_count);

    return EXIT_SUCCESS;
}
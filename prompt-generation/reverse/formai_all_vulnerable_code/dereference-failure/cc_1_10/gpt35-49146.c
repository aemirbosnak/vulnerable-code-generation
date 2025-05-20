//FormAI DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_COUNT 500

// A structure to hold the arguments for a worker thread
struct WorkerArgs 
{
    char* ip;
    int start;
    int incr;
};

// A function used by each thread to scan for open ports on a given IP address
void* worker(void* arg)
{
    struct WorkerArgs* args = (struct WorkerArgs*) arg;
    struct sockaddr_in target;
    int sock, port;
    char* ip = args->ip;
    int start = args->start;
    int incr = args->incr;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip);
    for(port = start; port <= 65535; port += incr)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_port = htons(port);
        if(connect(sock, (struct sockaddr*) &target, sizeof(target)) == 0)
        {
            printf("Port %d on %s is open\n", port, ip);
            close(sock);
        }
        else
        {
            close(sock);
        }
    }
    free(args);
    return NULL;
}

// A recursive function to create worker threads and scan for open ports on a given IP address
void recursive_scan(char* ip, int start, int end)
{
    int range = (end - start) / THREAD_COUNT;
    int i;
    pthread_t threads[THREAD_COUNT];
    for(i = 0; i < THREAD_COUNT; i++)
    {
        struct WorkerArgs* args = (struct WorkerArgs*) malloc(sizeof(struct WorkerArgs));
        args->ip = ip;
        args->start = start + i * range;
        args->incr = THREAD_COUNT * range;
        pthread_create(&threads[i], NULL, worker, (void*) args);
    }
    for(i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }
    if(end - start > 1000)
    {
        int mid = start + (end - start) / 2;
        recursive_scan(ip, start, mid);
        recursive_scan(ip, mid, end);
    }
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }
    char* ip = argv[1];
    recursive_scan(ip, 0, 65535);
    return 0;
}
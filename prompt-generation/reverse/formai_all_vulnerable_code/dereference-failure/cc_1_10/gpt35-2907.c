//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<pthread.h>

#define MAX_THREADS 50
#define LOWER_BOUND 1
#define UPPER_BOUND 65535

void *scan_port(void *arg);

struct scan_data {
    char *dest_ip;
    int port;
};

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    char *dest_ip = argv[1];

    pthread_t threads[MAX_THREADS];
    int i, thread_count = 0;

    for(i=LOWER_BOUND; i<=UPPER_BOUND; i++) {
        struct scan_data *data = (struct scan_data *) malloc(sizeof(struct scan_data));
        data->dest_ip = dest_ip;
        data->port = i;

        if(pthread_create(&threads[thread_count], NULL, scan_port, (void *) data) != 0) {
            printf("Unable to create thread: %d\n", errno);
            return 1;
        }

        thread_count++;

        if(thread_count == MAX_THREADS) {
            for(i=0; i<MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }

            thread_count = 0;
        }
    }

    for(i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *scan_port(void *arg) {
    struct scan_data *data = (struct scan_data *) arg;
    char *dest_ip = data->dest_ip;
    int port = data->port;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(dest_ip);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        printf("Error opening socket: %d\n", errno);
        pthread_exit(NULL);
    }

    int res = connect(sock, (struct sockaddr *) &addr, sizeof(addr));
    if(res == 0) {
        printf("Port %d is open\n", port);
    }

    close(sock);
    free(data);
    pthread_exit(NULL);
}
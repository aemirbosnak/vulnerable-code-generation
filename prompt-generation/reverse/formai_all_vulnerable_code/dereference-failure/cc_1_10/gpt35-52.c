//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORT 65535  
#define MAX_THREADS 512 

struct thread_data {
    int sockfd;
    int port;
    struct sockaddr_in serv_addr;
};

void *scanner_worker(void *arg) {
    struct thread_data *tdata = (struct thread_data *) arg;
    int sockfd = tdata->sockfd;
    int port = tdata->port;

    if(connect(sockfd, (struct sockaddr*) &(tdata->serv_addr), sizeof(tdata->serv_addr)) < 0) {
        // port closed
        free(arg);
        pthread_exit(NULL);
    }

    printf("Port %d is open.\n", port);
    free(arg);
    pthread_exit(NULL);
}

void start_port_scan(char* ip_addr) {
    pthread_t threads[MAX_THREADS];
    struct sockaddr_in serv_addr;
    struct thread_data *tdata_ptr = NULL;
    int thread_count = 0;
    int sockfd;

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);

    for(int i=1; i<=MAX_PORT; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) {
            perror("Cannot create socket");
            exit(errno);
        }

        serv_addr.sin_port = htons(i);

        tdata_ptr = (struct thread_data *) malloc(sizeof(struct thread_data));
        tdata_ptr->sockfd = sockfd;
        tdata_ptr->port = i;
        memcpy(&(tdata_ptr->serv_addr), &serv_addr, sizeof(serv_addr));

        if((pthread_create(&(threads[thread_count]), NULL, scanner_worker, (void *) tdata_ptr)) != 0) {
            perror("Cannot create thread");
            exit(errno);
        }

        thread_count++;

        if(thread_count == MAX_THREADS) {
            for(int j=0; j<MAX_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }
    }

    // join the remaining threads
    for(int i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s IP_ADDRESS\n", argv[0]);
        exit(0);
    }

    start_port_scan(argv[1]);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    char *hostname;
    int port;
    int num_pings;
    int num_replies;
    double avg_rtt;
} ping_args;

void *ping_thread(void *arg) {
    ping_args *args = (ping_args *)arg;
    
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        pthread_exit(NULL);
    }
    
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(args->port);
    if (inet_aton(args->hostname, &servaddr.sin_addr) == 0) {
        perror("inet_aton");
        pthread_exit(NULL);
    }
    
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "PING");
    
    struct timeval start, end;
    double rtt;
    
    for (int i = 0; i < args->num_pings; i++) {
        if (sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
            perror("sendto");
            pthread_exit(NULL);
        }
        
        socklen_t len = sizeof(servaddr);
        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, &len) < 0) {
            perror("recvfrom");
            pthread_exit(NULL);
        }
        
        gettimeofday(&end, NULL);
        rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        
        args->num_replies++;
        args->avg_rtt += rtt;
        printf("Reply from %s: time=%f ms\n", args->hostname, rtt);
        
        usleep(10000);
    }
    
    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <num_pings>\n", argv[0]);
        exit(1);
    }
    
    ping_args args;
    args.hostname = argv[1];
    args.port = atoi(argv[2]);
    args.num_pings = atoi(argv[3]);
    args.num_replies = 0;
    args.avg_rtt = 0.0;
    
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, ping_thread, &args) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }
    
    printf("Summary:\n");
    printf("Number of replies: %d\n", args.num_replies);
    printf("Average RTT: %f ms\n", args.avg_rtt / args.num_replies);
    
    return 0;
}
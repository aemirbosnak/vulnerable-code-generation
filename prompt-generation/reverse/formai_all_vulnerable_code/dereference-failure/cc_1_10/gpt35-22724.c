//FormAI DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <netinet/tcp.h> 
#include <netdb.h> 
#include <netinet/ip.h> 

#define MAX_THREADS 1000

struct thread_data {
    char* ip;
    int startport;
    int endport;
};

void *thread_scan(void *arg) {
    struct thread_data *data = (struct thread_data*) arg;

    int sockfd, ret, port;
    struct sockaddr_in target;

    for(port = data->startport; port <= data->endport; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        fcntl(sockfd, F_SETFL, O_NONBLOCK);

        target.sin_family = AF_INET;
        target.sin_addr.s_addr = inet_addr(data->ip);
        target.sin_port = htons(port);

        ret = connect(sockfd, (struct sockaddr *)&target, sizeof(target));

        if(ret < 0 && errno != EINPROGRESS) 
        {
            close(sockfd);
        } 
        else 
        {
            struct timeval tv;
            fd_set fds;
            tv.tv_sec = 1;
            tv.tv_usec = 0;
            FD_ZERO(&fds);
            FD_SET(sockfd, &fds);
            ret = select(sockfd + 1, NULL, &fds, NULL, &tv);

            if(ret > 0) 
            {
                int so_error;
                socklen_t len = sizeof(so_error);
                getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &len);

                if(so_error == 0) 
                {
                    printf("%s:%d is open\n", data->ip, port);
                } 
                else 
                {
                    close(sockfd);
                }
            } 
            else if(ret == 0) 
            {
                close(sockfd);
            }
        }
    }

    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
    char* ip = argv[1];
    int threads = MAX_THREADS;
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    int range = end_port - start_port;
    int i, j, step;

    if(range < threads) {
        threads = range;
    }
  
    step = range / threads;

    pthread_t tid[MAX_THREADS];
    struct thread_data td[MAX_THREADS];

    for(i = 0; i < threads; i++) {
        td[i].ip = ip;
        td[i].startport = start_port + (i * step) + 1;

        if(i == threads - 1) {
            td[i].endport = end_port;
        } 
        else {
            td[i].endport = td[i].startport + step - 1;
        }
    }

    for(i = 0; i < threads; i++) {
        pthread_create(&tid[i], NULL, thread_scan, &td[i]);
    }

    for(j = 0; j < threads; j++) {
        pthread_join(tid[j], NULL);
    }

    return 0;
}
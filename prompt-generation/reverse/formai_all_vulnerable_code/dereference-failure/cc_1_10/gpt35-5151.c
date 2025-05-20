//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>

#define MAX_THREADS 1000

void *scan(void *port){
    int sockfd; 
    int status;
    struct addrinfo hints;
    struct addrinfo *servinfo;
    char portstr[5];
    sprintf(portstr, "%d", *(int*)port);
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if ((status = getaddrinfo(NULL, portstr, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo %s\n", gai_strerror(status));
        pthread_exit(NULL);
    }
    if ((sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) == -1) {
        printf("Port %d: closed \n", *(int*)port);
        pthread_exit(NULL);
    }
    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        printf("Port %d: closed \n", *(int*)port);
        close(sockfd);
        pthread_exit(NULL);
    }
    printf("Port %d: open \n", *(int*)port);
    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    int end, start, num_ports, i, j;
    if (argc < 3){
        printf("Usage: %s hostname [start_port] [end_port]\n", argv[0]);
        return 1;
    }
    int suffix = atoi(argv[1]);
    if (suffix == 0){
        struct hostent *he;
        struct in_addr **addr_list;
        if ((he = gethostbyname(argv[1])) == NULL) {
            herror("gethostbyname");
            return 2;
        }
        addr_list = (struct in_addr **) he->h_addr_list;
        suffix = atoi(inet_ntoa(*addr_list[0]));
    }
    if (argc == 3){
        num_ports = 100; // default port range
        start = atoi(argv[2]);
        end = start + num_ports;
    }
    else{
        start = atoi(argv[2]);
        end = atoi(argv[3]);
        num_ports = end - start;
    }
    int ports[num_ports];
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    for (i=0; i<num_ports; i++){
        ports[i] = start + i;
        if (thread_count == MAX_THREADS){
            for (j=i-MAX_THREADS; j<i; j++){
                pthread_join(threads[j],NULL);
            }
            thread_count = 0;
        }
        pthread_create(&threads[thread_count], NULL, scan, &ports[i]);
        thread_count++;
    }
    for (i=0; i<thread_count; i++){
        pthread_join(threads[i],NULL);
    }
    return 0;
}
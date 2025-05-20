//FormAI DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<pthread.h>

void *scan(void *arg);

int main(int argc, char *argv[]) {

    if(argc != 4) {
        fprintf(stderr, "Usage: %s <target> <port-range-min> <port-range-max>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target = argv[1];
    int min_port = atoi(argv[2]);
    int max_port = atoi(argv[3]);

    pthread_t tid[max_port - min_port + 1];

    struct hostent *host = gethostbyname(target);
    if(host == NULL) {
        fprintf(stderr, "Unable to resolve host %s\n", target);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in target_addr;
    memcpy(&target_addr.sin_addr, host->h_addr_list[0], host->h_length);
    target_addr.sin_family = AF_INET;

    for(int i=min_port; i <= max_port; ++i) {
        target_addr.sin_port = htons(i);
        if(pthread_create(&tid[i-min_port], NULL, scan, (void*)&target_addr) < 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for(int i=min_port; i <= max_port; ++i) {
        pthread_join(tid[i-min_port], NULL);
    }

    return 0;
}

void *scan(void *arg) {

    struct sockaddr_in server = *(struct sockaddr_in*)arg;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = htons(0);

    if(bind(sockfd, (struct sockaddr*)&client, sizeof(client)) < 0) {
        close(sockfd);
        perror("bind");
        return NULL;
    }

    if(connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        close(sockfd);
        return NULL;
    } else {
        printf("Port %d is open\n", ntohs(server.sin_port));
        close(sockfd);
        return NULL;
    }
}
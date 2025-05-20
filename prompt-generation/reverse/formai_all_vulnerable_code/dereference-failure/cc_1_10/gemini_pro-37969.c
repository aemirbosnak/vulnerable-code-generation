//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define HOST "speedtest.googlefiber.net"
#define PORT 8080
#define BUF_SIZE 1024

pthread_t threads[10];

void* send_thread(void* arg) {
    int sockfd = *(int*)arg;
    char buf[BUF_SIZE];
    int n;
 while(1){
    memset(buf, 0, BUF_SIZE);
    n = send(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }
    usleep(1000);
   }
    return NULL;
}

void* recv_thread(void* arg) {
    int sockfd = *(int*)arg;
    char buf[BUF_SIZE];
    int n;
    while(1){
    memset(buf, 0, BUF_SIZE);
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    }
   

    return NULL;
}

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, send_thread, &sockfd);
        pthread_create(&threads[i], NULL, recv_thread, &sockfd);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sockfd);
    return 0;
}
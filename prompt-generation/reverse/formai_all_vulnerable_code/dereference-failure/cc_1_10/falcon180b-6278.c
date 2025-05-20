//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <sys/time.h>
#include <pthread.h>

#define BUF_SIZE 1024

struct sockaddr_in server_addr;
int sockfd;
char send_buf[BUF_SIZE];
char recv_buf[BUF_SIZE];
int opt = 1;
int addrlen = sizeof(server_addr);

void *send_thread(void *arg) {
    int n;
    while (1) {
        memset(send_buf, 0, BUF_SIZE);
        sprintf(send_buf, "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n");
        n = send(sockfd, send_buf, strlen(send_buf), 0);
        if (n <= 0) {
            printf("Send failed: %s\n", strerror(errno));
            break;
        }
        usleep(100000);
    }
    return NULL;
}

void *recv_thread(void *arg) {
    int n;
    while (1) {
        n = recv(sockfd, recv_buf, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Recv failed: %s\n", strerror(errno));
            break;
        }
        printf("Received %d bytes\n", n);
        usleep(100000);
    }
    return NULL;
}

int main() {
    pthread_t send_id, recv_id;
    int ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket failed: %s\n", strerror(errno));
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, "www.example.com", &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, addrlen);
    if (ret == -1) {
        printf("Connect failed: %s\n", strerror(errno));
        return 1;
    }

    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char *)&opt, sizeof(opt));

    pthread_create(&send_id, NULL, send_thread, NULL);
    pthread_create(&recv_id, NULL, recv_thread, NULL);

    pthread_join(send_id, NULL);
    pthread_join(recv_id, NULL);

    close(sockfd);
    return 0;
}
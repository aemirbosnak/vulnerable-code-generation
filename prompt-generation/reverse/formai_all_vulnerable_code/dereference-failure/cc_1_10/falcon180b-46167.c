//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUF_SIZE 1024

struct thread_data {
    int sockfd;
    struct sockaddr_in server_addr;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char buf[BUF_SIZE];
    int len;

    while (1) {
        len = recv(data->sockfd, buf, BUF_SIZE, 0);
        if (len <= 0) {
            break;
        }
        printf("Thread %d received %d bytes from server\n", getpid(), len);
        buf[len] = '\0';
        printf("Thread %d received message: %s\n", getpid(), buf);
    }

    close(data->sockfd);
    free(data);
    return NULL;
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, max_threads;
    int thread_id;
    int addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUF_SIZE];
    pthread_t thread_id_list[MAX_THREADS];

    if (argc < 3) {
        printf("Usage: %s <server_ip> <port_number>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    addrlen = sizeof(struct sockaddr_in);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buf, 0, sizeof(buf));
        fgets(buf, BUF_SIZE, stdin);
        send(sockfd, buf, strlen(buf), 0);

        if (strcmp(buf, "exit") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}
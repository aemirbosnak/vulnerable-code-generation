//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 1500

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    uint32_t npackets;
} thread_data;

void *thread_main(void *arg) {
    thread_data *data = (thread_data *)arg;

    uint8_t buffer[MAX_PACKET_SIZE];
    while (1) {
        ssize_t nbytes = recv(data->sockfd, buffer, MAX_PACKET_SIZE, 0);
        if (nbytes < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("recv");
                break;
            }
        } else if (nbytes == 0) {
            break;
        }
        data->npackets++;
    }
    close(data->sockfd);
    free(data);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <interface> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    int nthreads = 4;
    pthread_t threads[nthreads];
    thread_data data[nthreads];
    for (int i = 0; i < nthreads; i++) {
        data[i].sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
        if (data[i].sockfd < 0) {
            perror("socket");
            return EXIT_FAILURE;
        }
        data[i].addr = addr;
        data[i].npackets = 0;
        if (pthread_create(&threads[i], NULL, thread_main, &data[i]) < 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < nthreads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < nthreads; i++) {
        printf("Thread %d: %d packets\n", i, data[i].npackets);
    }

    return EXIT_SUCCESS;
}
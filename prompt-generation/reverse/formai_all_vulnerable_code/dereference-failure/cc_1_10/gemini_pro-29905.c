//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <pthread.h>

#define BUFFERSIZE 1024
#define TIMEOUT 5

typedef struct {
    char *hostname;
    int port;
    int num_threads;
    int test_time;
} test_params;

void *test_thread(void *arg) {
    test_params *params = (test_params *)arg;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(params->port);
    serveraddr.sin_addr.s_addr = inet_addr(params->hostname);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFFERSIZE];
    int bytes_sent = 0;
    int bytes_received = 0;
    time_t start_time = time(NULL);

    while ((time(NULL) - start_time) < params->test_time) {
        memset(buffer, 0, BUFFERSIZE);
        int n = read(sockfd, buffer, BUFFERSIZE);
        if (n < 0) {
            perror("read");
            exit(1);
        }
        bytes_received += n;

        memset(buffer, 'a', BUFFERSIZE);
        n = write(sockfd, buffer, BUFFERSIZE);
        if (n < 0) {
            perror("write");
            exit(1);
        }
        bytes_sent += n;
    }

    close(sockfd);

    printf("Thread %d: Sent %d bytes, Received %d bytes\n", (int)pthread_self(), bytes_sent, bytes_received);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <num_threads> <test_time>\n", argv[0]);
        exit(1);
    }

    test_params params;
    params.hostname = argv[1];
    params.port = atoi(argv[2]);
    params.num_threads = atoi(argv[3]);
    params.test_time = atoi(argv[4]);

    pthread_t threads[params.num_threads];

    for (int i = 0; i < params.num_threads; i++) {
        if (pthread_create(&threads[i], NULL, test_thread, &params) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (int i = 0; i < params.num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    return 0;
}
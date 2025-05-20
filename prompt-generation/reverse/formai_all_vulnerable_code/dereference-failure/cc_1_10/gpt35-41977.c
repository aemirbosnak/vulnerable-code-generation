//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define NUM_THREADS 10

struct arg_struct {
    int start_port;
    int end_port;
    char* ip_address;
};

void *port_scan(void *arguments) {
    struct arg_struct *args = (struct arg_struct *) arguments;
    int sockfd, port;
    struct sockaddr_in serv_addr;

    /* Create socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    /* Set timeout */
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) < 0) {
        perror("Timeout error");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(args->start_port);

    if (inet_pton(AF_INET, args->ip_address, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    /* Connect to host */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        /* Port closed */
        close(sockfd);
        pthread_exit(NULL);
    } else {
        /* Port open */
        printf("Port %d on %s is open\n", args->start_port, args->ip_address);
        close(sockfd);
        pthread_exit(NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    char* ip_address = argv[1];

    pthread_t threads[NUM_THREADS];
    int rc, i;
    for (i = start_port; i < end_port; i += NUM_THREADS) {
        int j, count = 0;
        struct arg_struct args[NUM_THREADS];
        for (j = i; j < i+NUM_THREADS && j < end_port; j++) {
            args[count].start_port = j;
            args[count].end_port = end_port;
            args[count].ip_address = ip_address;
            count++;
        }
        for (j = 0; j < count; j++) {
            rc = pthread_create(&threads[j], NULL, port_scan, (void *)&args[j]);
            if (rc != 0) {
                perror("Thread creation error");
                return EXIT_FAILURE;
            }
        }
        for (j = 0; j < count; j++) {
            pthread_join(threads[j], NULL);
        }
    }

    return EXIT_SUCCESS;
}
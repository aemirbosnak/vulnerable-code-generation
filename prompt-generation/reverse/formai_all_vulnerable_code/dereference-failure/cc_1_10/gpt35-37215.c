//FormAI DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define NUM_THREADS 1000

// Global Variables
int port_count = 0;
char* host;
int start_port, end_port;
pthread_mutex_t lock;
void (*callback)(int port, int status);

// Function Prototypes
void *scan(void *thread_id);

// Scanning function
void *scan(void *thread_id) {
    int sockfd, port;
    struct sockaddr_in server;
    struct hostent *hostname;
    char* thread_info = (char*) thread_id;

    // Loop over all ports
    while (1) {
        pthread_mutex_lock(&lock);
        if (port_count > end_port) {
            pthread_mutex_unlock(&lock);
            break;
        } else {
            port = port_count++;
            pthread_mutex_unlock(&lock);
            hostname = gethostbyname(host);
            if (hostname == NULL) {
                perror("gethostbyname");
                pthread_exit(NULL);
            }

            memset(&server, 0, sizeof(server));
            server.sin_family = AF_INET;
            server.sin_port = htons(port);
            server.sin_addr = *((struct in_addr*)hostname->h_addr);

            if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("socket");
                pthread_exit(NULL);
            }

            if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) == 0) {
                close(sockfd);
                callback(port, 1);
            } else {
                callback(port, 0);
            }
        }
    }

    sprintf(thread_info, "Thread %ld is done.\n", pthread_self());
    pthread_exit(NULL);
}

// Main method
int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <hostname> <starting port> <ending port>\n", argv[0]);
        return 0;
    }

    // Get command line args
    host = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);
    if (end_port < start_port) {
        printf("Ending port must not be less than starting port.\n");
        return 0;
    }
    if (start_port < 0 || end_port > 65535) {
        printf("Invalid port number.\n");
        return 0;
    }

    // Initialize mutex lock
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("pthread_mutex_init");
        return 0;
    }

    // Initialize threads
    pthread_t threads[NUM_THREADS];
    char thread_info[NUM_THREADS][20];
    int thread_num;
    for (thread_num = 0; thread_num < NUM_THREADS; ++thread_num) {
        sprintf(thread_info[thread_num], "Thread %d", thread_num);
        pthread_create(&threads[thread_num], NULL, scan, (void*)thread_info[thread_num]);
    }

    // Wait for threads to complete
    for (thread_num = 0; thread_num < NUM_THREADS; ++thread_num) {
        pthread_join(threads[thread_num], NULL);
    }

    // Destroy mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}
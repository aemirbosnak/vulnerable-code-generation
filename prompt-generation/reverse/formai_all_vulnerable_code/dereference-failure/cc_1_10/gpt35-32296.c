//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

#define PORT 80 // port to connect to
#define ITERATIONS 5 // number of times to run the test
#define THREADS 10 // number of threads to use

int success_count = 0; // number of successful connections made
int failure_count = 0; // number of failed connections made
pthread_mutex_t success_lock; // lock for modifying success_count
pthread_mutex_t failure_lock; // lock for modifying failure_count

void* test_speed(void* arg) {
    int sockfd, nbytes;
    struct sockaddr_in servaddr;
    char sendline[1000], recvline[1000];
    struct hostent* host;
    char* hostname = (char*) arg;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // get host information
    host = gethostbyname(hostname);

    // set server details
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr = *((struct in_addr*) host->h_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        pthread_mutex_lock(&failure_lock);
        failure_count++;
        pthread_mutex_unlock(&failure_lock);
        close(sockfd);
        pthread_exit(NULL);
    }

    // send HTTP GET request
    sprintf(sendline, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    write(sockfd, sendline, strlen(sendline));

    // read and discard server response
    while ((nbytes = read(sockfd, recvline, sizeof(recvline))) > 0) {}

    // close socket
    close(sockfd);

    pthread_mutex_lock(&success_lock);
    success_count++;
    pthread_mutex_unlock(&success_lock);

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    pthread_t threads[THREADS];
    int i, j;
    struct timeval start, end;

    // initialize locks
    pthread_mutex_init(&success_lock, NULL);
    pthread_mutex_init(&failure_lock, NULL);

    // run test multiple times
    for (i = 0; i < ITERATIONS; i++) {
        success_count = 0;
        failure_count = 0;

        // start time
        gettimeofday(&start, NULL);

        // start threads
        for (j = 0; j < THREADS; j++) {
            pthread_create(&threads[j], NULL, test_speed, argv[1]);
        }

        // join threads
        for (j = 0; j < THREADS; j++) {
            pthread_join(threads[j], NULL);
        }

        // end time
        gettimeofday(&end, NULL);

        long elapsed_seconds = end.tv_sec - start.tv_sec;
        long elapsed_microseconds = end.tv_usec - start.tv_usec;

        if (elapsed_microseconds < 0) {
            elapsed_microseconds += 1000000;
            elapsed_seconds--;
        }

        float elapsed_time = elapsed_seconds + elapsed_microseconds / 1000000.0;

        printf("Iteration #%d:\n", i+1);
        printf("Success: %d\n", success_count);
        printf("Failure: %d\n", failure_count);
        printf("Elapsed time: %.3f seconds\n", elapsed_time);
        printf("Download speed: %.3f KB/s\n", success_count * 8000 / elapsed_time / 1024);
    }

    // cleanup locks
    pthread_mutex_destroy(&success_lock);
    pthread_mutex_destroy(&failure_lock);

    return 0;
}
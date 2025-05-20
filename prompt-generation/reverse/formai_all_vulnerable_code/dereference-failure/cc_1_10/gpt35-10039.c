//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_DATASIZE 1024          // maximum data size
#define NSEC_PER_SEC 1000000000    // nanoseconds per second

// structure to hold host and port information
struct host_info {
    char* host;
    char* port;
};

// structure to hold thread data
struct thread_data {
    int thread_id;
    struct host_info server_info;
};

// function to handle received data
void handle_received_data(char* buffer, int numbytes, struct timespec start_time, int* num_received, double* total_time) {
    struct timespec end_time;       // end time
    clock_gettime(CLOCK_MONOTONIC, &end_time);  // get end time
    double elapsed_time = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_nsec - start_time.tv_nsec) / (double)NSEC_PER_SEC;   // elapsed time in seconds
    *total_time += elapsed_time;    // add elapsed time to total time
    (*num_received)++;             // increment number of received packets
    printf("Received %d bytes in %f seconds\n", numbytes, elapsed_time);
}

// thread function to send packets to the server
void* send_packets(void* args) {
    struct thread_data* thread_data = (struct thread_data*)args;   // get thread data
    int sockfd;             // socket file descriptor
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int i;
    int num_sent = 0;       // number of sent packets
    int sock_error = 0;     // is there a socket error?
    int num_errors = 0;     // number of socket errors
    double total_time = 0.0;    // total time
    char buffer[MAX_DATASIZE];  // buffer to hold data
    memset(&hints, 0, sizeof hints);    // make sure the struct is empty
    hints.ai_family = AF_UNSPEC;        // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;    // use TCP
    // get server information
    if ((rv = getaddrinfo(thread_data->server_info.host, thread_data->server_info.port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        pthread_exit((void*)1);
    }
    // loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        // create socket
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }
        // connect to server
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }
        break;
    }
    // if p is NULL, we failed to connect
    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        pthread_exit((void*)1);
    }
    freeaddrinfo(servinfo);     // all done with this structure
    printf("Client[%d]: Connected to %s:%s\n", thread_data->thread_id, thread_data->server_info.host, thread_data->server_info.port);
    // send data
    while (1) {
        // generate random data
        for (i = 0; i < MAX_DATASIZE; i++) {
            buffer[i] = rand() % 256;
        }
        // send data
        clock_t start_time = clock();   // start time
        if (send(sockfd, buffer, MAX_DATASIZE, 0) == -1) {
            perror("send");
            sock_error = 1;
            num_errors++;
            break;
        }
        num_sent++;     // increment number of sent packets
        clock_t end_time = clock();     // end time
        total_time += (double)(end_time - start_time) / (double)CLOCKS_PER_SEC;    // add elapsed time to total time
    }
    // close socket
    close(sockfd);
    pthread_exit((void*)0);
}

// main function
int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s [server hostname] [server port] [num threads]\n", argv[0]);
        return 0;
    }
    int num_threads = atoi(argv[3]);    // number of threads
    pthread_t threads[num_threads];     // thread array
    struct thread_data thread_data[num_threads];    // thread data array
    struct host_info server_info = { argv[1], argv[2] };   // server information
    int i;
    int num_received = 0;           // number of received packets
    double total_time = 0.0;        // total time
    // create threads
    for (i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].server_info = server_info;
        if (pthread_create(&threads[i], NULL, send_packets, (void*)&thread_data[i])) {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }
    }
    // wait for threads to finish
    for (i = 0; i < num_threads; i++) {
        void* status;
        if (pthread_join(threads[i], &status)) {
            printf("Error joining thread %d\n", i + 1);
            return 1;
        }
        if (status) {
            printf("Error in thread %d\n", i + 1);
            return 1;
        }
    }
    // calculate statistics
    double avg_time = total_time / (double)num_received;
    double packet_loss_rate = (double)(num_threads - num_received) / (double)num_threads * 100.0;
    if (packet_loss_rate > 0.0) {
        printf("\n-------------------------------\n");
        printf("PACKET LOSS RATE: %.2f%%\n", packet_loss_rate);
        printf("NUM ERRORS: %d\n", num_threads - num_received);
    }
    printf("\n-------------------------------\n");
    printf("TOTAL TIME: %f seconds\n", total_time);
    printf("AVERAGE TIME: %f seconds\n", avg_time);
    printf("NUM SENT: %d\n", num_threads);
    printf("NUM RECEIVED: %d\n", num_received);
    printf("\n-------------------------------\n");
    return 0;
}
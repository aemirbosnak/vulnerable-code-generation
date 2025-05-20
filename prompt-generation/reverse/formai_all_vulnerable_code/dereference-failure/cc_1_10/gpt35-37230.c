//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>

#define MAX_THREADS 100

volatile sig_atomic_t stop_signal = 0;

// Define a struct to hold information for each thread.
typedef struct thread_info {
    int id;
    int sock;
    struct sockaddr_in server;
} thread_info;

void signal_handler(int sig) {
    stop_signal = 1;
}

void* scanner_thread(void* arg) {
    thread_info* info = (thread_info*)arg;

    printf("Thread %d started.\n", info->id);

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    // Send a "hello" message to the server.
    sprintf(buffer, "Hello from thread %d", info->id);
    if (sendto(info->sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&info->server, sizeof(info->server)) < 0) {
        fprintf(stderr, "Error sending message to server: %s\n", strerror(errno));
        return NULL;
    }

    // Wait for a response from the server.
    struct timeval timeout;
    timeout.tv_sec = 5; // 5 second timeout
    timeout.tv_usec = 0;

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(info->sock, &read_fds);

    int res = select(info->sock+1, &read_fds, NULL, NULL, &timeout);
    if (res < 0) {
        fprintf(stderr, "Error waiting for response from server: %s\n", strerror(errno));
        return NULL;
    } else if (res == 0) {
        printf("Thread %d timed out waiting for response.\n", info->id);
    } else {
        memset(buffer, 0, sizeof(buffer));
        recv(info->sock, buffer, sizeof(buffer), 0);
        printf("Thread %d received response: %s\n", info->id, buffer);
    }

    printf("Thread %d exiting.\n", info->id);

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 0;
    }

    signal(SIGINT, signal_handler);

    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(5000);
    
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Started scanner...\n");

    // Start threads
    while (!stop_signal && num_threads < MAX_THREADS) {
        // Create a new thread
        thread_info* info = (thread_info*)malloc(sizeof(thread_info));
        if (!info) {
            fprintf(stderr, "Error allocating memory for thread: %s\n", strerror(errno));
            return 1;
        }

        info->sock = sock;
        info->server = server;
        info->id = num_threads;

        if (pthread_create(&threads[num_threads], NULL, scanner_thread, info)) {
            fprintf(stderr, "Error creating thread: %s\n", strerror(errno));
            free(info);
            break;
        }

        num_threads++;
        usleep(100000); // Wait 100ms before creating the next thread.
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scanner finished.\n");

    close(sock);

    return 0;
}
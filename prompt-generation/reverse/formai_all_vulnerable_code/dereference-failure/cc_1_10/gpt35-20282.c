//FormAI DATASET v1.0 Category: Benchmarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1000000
#define ITERATIONS 10000000

int *buffer;
int read_pos = 0;
int write_pos = 0;

void reader() {
    int i;
    for (i = 0; i < ITERATIONS; i++) {
        while (read_pos == write_pos) {
            // Wait for the writer to add data
            usleep(1);
        }
        read_pos ++;
        if (read_pos == BUFFER_SIZE) read_pos = 0;
    }
}

void writer() {
    int i;
    for (i = 0; i < ITERATIONS; i++) {
        while (((write_pos + 1) % BUFFER_SIZE) == read_pos) {
            // Wait for the reader to read data
            usleep(1);
        }
        buffer[write_pos] = i;
        write_pos ++;
        if (write_pos == BUFFER_SIZE) write_pos = 0;
    }
}

int main(void) {
    struct timeval start_time, end_time, elapsed_time;
    gettimeofday(&start_time, NULL);

    buffer = (int *) malloc(BUFFER_SIZE * sizeof(int));
    if (buffer == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == 0) { // Child process is the reader
        reader();
        _exit(0);
    }
    else if (pid > 0) { // Parent process is the writer
        writer();
    }
    else {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&end_time, NULL);
    timersub(&end_time, &start_time, &elapsed_time);
    printf("Time taken: %ld.%ld seconds\n", elapsed_time.tv_sec, elapsed_time.tv_usec);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MB 1024*1024
#define TIMEOUT 10  // in seconds

double get_speed(int size) {
    char *buffer = malloc(size);
    if (!buffer) {
        perror("malloc");
        return -1;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    int n = 0;
    while (1) {
        n += fread(buffer, 1, size, stdin);
        gettimeofday(&end, NULL);
        if (end.tv_sec - start.tv_sec >= TIMEOUT) {
            break;
        }
    }

    free(buffer);
    return (double)n / (end.tv_sec - start.tv_sec) / MB;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s size (in MB)\n", argv[0]);
        return EXIT_FAILURE;
    }

    int size = atoi(argv[1]);
    if (size <= 0) {
        fprintf(stderr, "Invalid size: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    double speed = get_speed(size * MB);
    if (speed < 0) {
        fprintf(stderr, "Error measuring speed\n");
        return EXIT_FAILURE;
    }

    printf("Speed: %.2f MB/s\n", speed);
    return EXIT_SUCCESS;
}
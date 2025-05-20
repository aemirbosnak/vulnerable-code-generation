//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/mman.h>

#define TIME_TRAVEL_MAGIC "TimeTravelSimulator"
#define MAX_TIME_TRAVELS 10
#define TIME_TRAVEL_SIZE (sizeof(struct TimeTravel) + 1)

struct TimeTravel {
    struct timeval tv;
    char reason[128];
};

int main(void) {
    int fd, i;
    char *map_base;
    struct TimeTravel *travel;

    fd = open("/dev/time_travel_simulator", O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("Can't open /dev/time_travel_simulator");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, (1 + MAX_TIME_TRAVELS) * TIME_TRAVEL_SIZE) == -1) {
        perror("Can't truncate file");
        exit(EXIT_FAILURE);
    }

    map_base = mmap(NULL, (1 + MAX_TIME_TRAVELS) * TIME_TRAVEL_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (map_base == MAP_FAILED) {
        perror("Can't mmap file");
        exit(EXIT_FAILURE);
    }

    travel = (struct TimeTravel *) map_base;

    for (i = 0; i < MAX_TIME_TRAVELS; i++) {
        travel[i].tv = (struct timeval) {
            0,  // microseconds
            1000 // seconds
        };

        strcpy(travel[i].reason, "Artistic style time travel: Traveling to the past to paint the Mona Lisa");

        if (msync(travel + i, TIME_TRAVEL_SIZE, MS_SYNC) == -1) {
            perror("Can't sync file");
            exit(EXIT_FAILURE);
        }

        if (settimeofday(&(travel[i].tv.tv_sec), &(travel[i].tv.tv_usec)) == -1) {
            perror("Can't set time");
            exit(EXIT_FAILURE);
        }

        sleep(1); // wait for a second before the next time travel

        printf("Time traveled to the past at %ld.%06ld and did: %s\n",
            (long int) travel[i].tv.tv_sec, (long int) travel[i].tv.tv_usec, travel[i].reason);
    }

    munmap(map_base, (1 + MAX_TIME_TRAVELS) * TIME_TRAVEL_SIZE);
    close(fd);

    return EXIT_SUCCESS;
}